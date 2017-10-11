#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iomanip>
#include "list.h"

using namespace std;

void List::create(){
    head = NULL;
    tail = NULL;
    nodecount = 0;
};

void List::close(){
    Phone_node *p;
    
    while (head){
        p = head;
        head = head->next;
        delete p;
    }
    nodecount = 0;
};


Phone_node * List::create_person(char * name, char * lastname, char * num){
    Phone_node * newperson;
    newperson = new Phone_node;
    int length = strlen(name);
    newperson->name = new char[length];
    strcpy(newperson->name, name);
    length = strlen(lastname);
    newperson->lastname = new char[length];
    strcpy(newperson->lastname, lastname);
    length = strlen(num);
    newperson->phonenum = new char[length];
    strcpy(newperson->phonenum, num);
    newperson->next = NULL;
    
    return newperson;
};

void List::insert(char *newname, char *newlastname, char *newphonenum){
    Phone_node *traverse, *behind, *newperson;
    number *newnum;
    traverse = head;
    behind = new Phone_node;
    
    if (head == NULL){									//first node being added
        head = create_person(newname, newlastname, newphonenum);
        nodecount++;
        return;
    }
    if (strcmp(newname, head->name) < 0){				//Insert to head of list
        newperson = create_person(newname, newlastname, newphonenum);
        newperson->next = head;
        head = newperson;
        nodecount++;
        return;
    }
    while (traverse && (strcmp(newname, traverse->name) > 0)){		//newname's name comes after traverse
        behind = traverse;
        traverse = traverse->next;
    }
    
    newperson = create_person(newname, newlastname, newphonenum);
    if (traverse){													//Inserting new name in between
        newperson->next = traverse;
        behind->next = newperson;
    }
    else															//insert to the end
        behind->next = newperson;
    nodecount++;
}

void List::remove(Phone_node * deleted){
    Phone_node *traverse, *del, *back;
    traverse = head;
    back = head;
    del = NULL;
    
    while (traverse){
        if (strncmp(deleted->name, traverse->name, strlen(deleted->name)) == 0 && strncmp(deleted->lastname, traverse->lastname, strlen(deleted->lastname)) == 0){
            if (traverse == head){
                head = traverse->next;
            }
            else{
                back->next = traverse->next;
            }
            del = traverse;
            break;
        }
        back = traverse;
        traverse = traverse->next;
    }
    if (del){
        delete del;
    }
}

Phone_node* List::search(char *target){
    Phone_node *traverse;
    int counter = 0;
    traverse = head;
    
    bool all = false;
    
    if (target [0] == '*')
        all = true;
    
    while (traverse){
        counter ++;
        if (all){
            cout << counter << ". " << traverse -> name << " " << traverse -> lastname << " " << traverse -> phonenum << endl;
        }
        else if (strncmp(target, traverse->name, strlen(target)) == 0){
            cout << "Record # : " << counter << endl;
            cout << "Name: " << traverse->name << endl;
            cout << "Last Name: " << traverse->lastname << endl;
            cout << "Phone num: " << traverse->phonenum << endl;

            return traverse;
        }
        traverse = traverse->next;
    }
    return NULL;
};

int List::search2(char *target, char *targetlastname){
    Phone_node *traverse;
    int counter = 0;
    int found = 0;
    traverse = head;
    
    while (traverse){
        counter++;
        if (strncmp(target, traverse->name, strlen(traverse->name)) == 0 && strncmp(targetlastname, traverse->lastname, strlen(traverse->lastname))){
            found++;
        }
        traverse = traverse->next;
    }
    return found;
};

void List::update(int num, char *newname, char *newlastname){
    Phone_node *traverse;
    int counter = 1;
    traverse = head;
    char num = new char[30];
    
    for (int i = 0; i < num; i++){
        traverse = traverse->next;
    }
    
    
    if (strcmp(traverse->name, newname) != 0){
        strcpy(num, traverse->num);
        remove(traverse->name);
        insert(newname, newlastname, num);
    }
};

void List::printList(){
    Phone_node *traverse;
    traverse = head;
    
    int counter = 1;
    
    while (traverse){
        cout << "\n" << "Record # " << counter << " : " << endl;
        cout << "Name : " << traverse->name << endl;
        cout << "Last Name : " << traverse->lastname << endl;
        cout << "Phonen num : " << traverse->phonenum << endl;       
        traverse = traverse->next;
        counter++;
    }
};
