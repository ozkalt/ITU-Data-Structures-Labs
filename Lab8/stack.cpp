#include <iostream>
#include "stack.h"

using namespace std;

void Stack::create(){
	head = NULL;
	limit = 0;
}

void Stack::close(){
	Node *p;
	while (head){
		p = head;
		head = head->next;
		delete p;
	}
}
void Stack::push(char *newdata){
	Node *newnode = new Node;
	newnode->data = newdata;
	newnode->next = head;
	head = newnode;
	limit++;
}

char* Stack::pop(){
	if (head == NULL)
		return '\0';

	Node *topnode;
	char *temp;
	topnode = head;
	head = head->next;
	temp = topnode->data;
	limit--;
	delete topnode;
	return temp;
}

bool Stack::isEmpty(){
	return (head == NULL);
}

void Stack::print(){
	cout << "Stack contents: ";
	Node *traverse = head;
	while (traverse){
		cout << traverse->data;
		traverse = traverse->next;
	}
	cout << endl;
}

char* Stack::topStack(){
	if (head == 0)
		return '\0';
	else
		return head->data;
}