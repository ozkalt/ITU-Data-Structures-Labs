#ifndef LIST_H
#define LIST_H
#include "node.h"

struct List{
    Phone_node *head, *tail;
    int nodecount;
    
    void create();
    
    Phone_node *create_person(char*, char*, char*);
    void close();
    void printList();
    void insert(char*, char*, char*);
    void remove(Phone_node *);
    Phone_node* search(char*);
    int search2(char*, char*);
    void update(int, char*);
};

#endif
