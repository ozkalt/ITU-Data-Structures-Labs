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
    number *q;
    
    while (head){
        p = head;
        head = head->next;
        q = p->phonenum;
        
        while (q){
            p->phonenum = p->phonenum->next;
            delete q;
            q = p->phonenum;
        }
        delete p;
    }
    nodecount = 0;
};


Phone_node * List::create_person(char * name){
    Phone_node * newperson;
    newperson = new Phone_node;
    int length = strlen(name);
    newperson->name = new char[length];
    strcpy(newperson->name, name);
    newperson->phonenum = NULL;
    newperson->next = NULL;
    
    return newperson;
};
void List::create_number(char * name, char * phone, char * type){
    Phone_node *traverse;
    traverse = head;
    
    number *newnum = new number;
    strcpy(newnum->num, phone);
    strcpy(newnum->type, type);
    newnum->next = NULL;
    
    while (traverse){
        if (strncmp(name, traverse->name, strlen(traverse->name)) == 0)	break;
        traverse = traverse->next;
    }
    
    if (traverse->phonenum == NULL){
        traverse->phonenum = newnum;
    }
    else{
        newnum->next = traverse->phonenum;
        traverse->phonenum = newnum;
    }
};

void List::insert(char *newname){
    Phone_node *traverse, *behind, *newperson;
    number *newnum;
    traverse = head;
    behind = new Phone_node;
    
    if (head == NULL){									//first node being added
        head = create_person(newname);
        nodecount++;
        return;
    }
    if (strcmp(newname, head->name) < 0){				//Insert to head of list
        newperson = create_person(newname);
        newperson->next = head;
        head = newperson;
        nodecount++;
        return;
    }
    while (traverse && (strcmp(newname, traverse->name) > 0)){		//newname's name comes after traverse
        behind = traverse;
        traverse = traverse->next;
    }
    
    newperson = create_person(newname);
    if (traverse){													//Inserting new name in between
        newperson->next = traverse;
        behind->next = newperson;
    }
    else															//insert to the end
        behind->next = newperson;
    nodecount++;
}

void List::remove(char* deleted){
    Phone_node *traverse, *del, *back;
    number *pn;
    traverse = head;
    back = head;
    del = NULL;
    
    while (traverse){
        if (strncmp(deleted, traverse->name, strlen(deleted)) == 0){
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
        if (del->phonenum){
            while (del->phonenum){
                pn = del->phonenum;
                del->phonenum = del->phonenum->next;
                delete pn;
            }
        }
        delete del;
    }
}

Phone_node* List::search(char *target){
    Phone_node *traverse;
    number *pn;
    int counter = 0;
    traverse = head;
    
    bool all = false;
    
    if (target [0] == '*')
        all = true;
    
    while (traverse){
        counter ++;
        pn = traverse->phonenum;
        if (all){
            cout << counter << ". " << traverse -> name << endl;
            while (pn){
                cout << pn->type << " : " << pn->num << endl;
                pn = pn->next;
            }
        }
        else if (strncmp(target, traverse->name, strlen(target)) == 0){
            cout << "Record # : " << counter << endl;
            cout << "Name: " << traverse->name << endl;
            if (traverse->phonenum != NULL){
                cout << pn->type << " : " << pn->num << endl;
            }
            return traverse;
        }
        traverse = traverse->next;
    }
    return NULL;
};

int List::search2(char *target){
    Phone_node *traverse;
    number *pn;
    int counter = 0;
    int found = 0;
    traverse = head;
    
    while (traverse){
        counter++;
        pn = traverse->phonenum;
        if (strncmp(target, traverse->name, strlen(traverse->name)) == 0){
            found++;
        }
        traverse = traverse->next;
    }
    return found;
};

void List::update(int num, char *newname){
    Phone_node *traverse;
    number * temp = new number;
    int counter = 1;
    traverse = head;
    
    for (int i = 0; i < num; i++){
        traverse = traverse->next;
    }
    
    
    if (strcmp(traverse->name, newname) != 0){
        temp = traverse->phonenum;
        remove(traverse->name);
        insert(newname);
    }
    
    traverse = head;
    while (traverse){
        if (strncmp(traverse->name, newname, strlen(newname)) == 0){
            traverse->phonenum = temp;
        }
        traverse = traverse->next;
    }
};

void List::printList(){
    Phone_node *traverse;
    number * pn;
    traverse = head;
    
    int counter = 1;
    
    while (traverse){
        cout << "\n" << "Record # " << counter << " : " << endl;
        cout << "Name : " << traverse->name << endl;
        pn = traverse->phonenum;
        while (pn){
            cout << pn->type << " : " << pn->num << endl;
            pn = pn->next;
        }
        traverse = traverse->next;
        counter++;
    }
};
