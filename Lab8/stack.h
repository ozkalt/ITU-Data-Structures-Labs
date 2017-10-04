#ifndef STACK_H
#define STACK_H

struct Node{
	char *data;
	Node *next;
};

struct Stack{
	Node *head;
	void create();
	void close();
	void push(char*);
	char* pop();
	bool isEmpty();
	char* topStack();
	void print();
	int limit;
};
#endif