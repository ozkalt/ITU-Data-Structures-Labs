//
// Created by jarvis on 20.12.2016.
//
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iomanip>
#include "node.h"
using namespace std;


void Tree::create() {
    root = NULL; // create empty tree
    nodecount = 0; // initialize nodecount to 0
}

void Tree::close() {
    emptytree(root);
}

void Tree::emptytree(Phone_node *p) {
    if (p) {
        if (p->left != NULL) {
            emptytree(p->left);
            p->left = NULL;
        }
        if (p->right != NULL) {
            emptytree(p->right);
            p->right = NULL;
        }
        delete p;
    }
}


void Tree::remove(char *remove_name){
    Phone_node *traverse, *parent;
    traverse = root;
    parent = NULL;
    bool found = false;
    char direction = 'k';
    
    while (traverse && !found) {
        int comparison = strcmp(remove_name, traverse->name);
        if (comparison < 0) {
            parent = traverse;
            direction = 'l';
            traverse = traverse->left;
        }
        else if (comparison > 0) {
            parent = traverse;
            direction = 'r';
            traverse = traverse->right;
        }
        else // found record to remove
            found = true;
    }
    
    if (found) {
        switch (direction){
            case 'l':
                parent->left = traverse->right;
                while(parent->left){
                    parent = parent->left;
                }
                parent->left = traverse->left;
                break;
            case 'r':
                parent->right = traverse->left;
                while(parent->right){
                    parent = parent->right;
                }
                parent->right = traverse->right;
                break;
            default:
                parent = root;
                root = root->left;
                traverse = root;
                while(traverse && traverse->right){
                    traverse = traverse->right;
                }
                if(!traverse)
                    traverse->right = parent->right;
                break;
        }

        number_node * n = traverse->head;
        number_node * p;
        while(n){
            p = n;
            n = n->next;
            delete p;
            
        }
        delete traverse;
    }
    else
        cout << "Could not find record to remove.\n";
}

        
Phone_node * Tree::search(char *search_name) {
    Phone_node *traverse;
    traverse = root;
    int countfound = 0;
    
    
    while(traverse && !countfound){
        int comparison = strcmp(search_name, traverse->name);
        if(comparison < 0)
            traverse = traverse->left;
        else if (comparison > 0)
            traverse = traverse->right;
        else{
            cout << traverse->name << endl;
            cout << traverse->phonenum << endl;
            number_node *iterate;
            iterate = traverse->head;
            while(iterate){
                cout << iterate->phonenum << endl;
                iterate = iterate->next;
            }
            
            countfound++;
            return traverse;
        }
    }
    return NULL;
}

void Tree::traverse_inorder(Phone_node *p) {
    if (p){
        traverse_inorder(p->left);
        cout << p->name <<endl;
        cout << p->phonenum <<endl;
        number_node *iterate;
        iterate = p->head;
        while(iterate)
        {
            cout<<iterate->phonenum<<endl;
            iterate = iterate->next;
        }
        
        traverse_inorder(p->right);
    }
}

void Tree::add( Phone_node *toadd ) {
    Phone_node *traverse, *newnode;
    traverse = root;
    int comparison;
    bool added = false;
    
    newnode = new Phone_node;
    
    strcpy(newnode->name, toadd->name);
    strcpy(newnode->phonenum, toadd->phonenum);
    
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->head = NULL;
    
    if (root == NULL){
        //first node being added
        root = newnode;
        nodecount++;
        return;
    }
    
    while ((traverse != NULL) && (!added)){
        comparison = strcmp(newnode->name,
                            traverse->name);
        if (comparison < 0) {
            if (traverse->left != NULL)
                traverse = traverse->left;
            else {
                traverse->left = newnode;
                added = true;
            }
        }
        else if (comparison > 0) {
            if (traverse->right != NULL)
                traverse = traverse->right;
            else {
                traverse->right = newnode;
                added = true;
            }
        }
        else {
            number_node *adder = new number_node;
            strcpy(adder->phonenum,toadd->phonenum);
            adder->next=NULL;
            number_node *iterate;
            if (traverse->head == NULL) {
                //first node being added
                traverse->head = adder;
                return;
            }
            else {
                iterate = traverse->head;
                while (iterate){
                	if(iterate->next==NULL){
                        iterate->next = adder;
                        return;
                    }
                    else {
                        iterate = iterate->next;
                    }
                }
                added = true;
                nodecount--;
            }
        }
    }
    
    if (added) nodecount++;
}

void Tree::update(char * updatename){
    Phone_node * updatenode;
    updatenode = search(updatename);
    if(!updatenode){
        cout << "Record cannot be found." << endl;
    }
    else{
        char newname[NAME_LENGTH];
        cout << "Enter the new name: ";
        cin.getline(newname, NAME_LENGTH);

        
        Phone_node * newnode = new Phone_node;
        number_node * newnum = NULL;
        
        if(updatenode->head)
            newnum = updatenode->head;
        
        strcpy(newnode->phonenum, updatenode->phonenum);
        strcpy(newnode->name, newname);
        
        newnode->left = NULL;
        newnode->right = NULL;
        
        updatenode->head = NULL;
        
        remove(updatenode->name);
        add(newnode);
        
        updatenode = search(newname);
        updatenode->head = newnum;
        
    }
}
