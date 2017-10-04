#ifndef LIST_H
#define LIST_H
#include "node.h"

struct List{
	Phone_node *head, *tail;
	int nodecount;

	void create();
	void close();
	void addNumber(char*, char*, char*);
	Phone_node *addName(char*);
	void addPerson(char*);
	void removeNumber(char*);
	void removePerson(char*);
	void updateNumber(char*);
	void updatePerson(char*);
	Phone_node* search(char*);
	void printList();
	void makeEmpty();
	int search2(char*);
};

#endif