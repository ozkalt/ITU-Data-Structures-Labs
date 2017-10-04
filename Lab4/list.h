#ifndef LIST_H
#define LIST_H
#include "node.h"

struct List{
    Phone_node *head, *tail;
    int nodecount;
    
    void create();
    
    void create_number(char*, char*, char*);
    Phone_node *create_person(char*);
    void close();
    void printList();
    void insert(char*);
    void remove(char*);
    Phone_node* search(char*);
    int search2(char*);
    void update(int, char*);
};

#endif
