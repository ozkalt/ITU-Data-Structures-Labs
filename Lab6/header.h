#ifndef STACK_H
#define STACK_H

struct Node{
	char data;
	Node *next;
};

struct Stack{
	Node *head;
	void create();
	void makeEmpty();
	void push(char);
	char pop();
	char getHeadChar();
	bool isEmpty();
	void print();
};

#endif //STACK_H