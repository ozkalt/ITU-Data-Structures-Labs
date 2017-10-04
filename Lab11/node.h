//
//  node.h
//  DS_Lab11_berk
//
//  Created by Tuğba Özkal on 21.12.2016.
//  Copyright © 2016 Tuğba Özkal. All rights reserved.
//

#ifndef node_h
#define node_h

#define NAME_LENGTH 30
#define PHONENUM_LENGTH 15

struct number_node{
    char phonenum[PHONENUM_LENGTH];
    number_node *next;
};

struct Phone_node{
    char name[NAME_LENGTH];
    char phonenum[PHONENUM_LENGTH];
    number_node *head;
    Phone_node *left;
    Phone_node *right;
};

struct Tree {
    Phone_node *root;
    int nodecount;
    void create();
    void close();
    void emptytree(Phone_node *);
    void add(Phone_node *);
    void remove(char *);
    void remove(Phone_node *);
    void traverse_inorder(Phone_node *);
    Phone_node * search(char *);
    void update(char *);
    
    
};

#endif /* node_h */
