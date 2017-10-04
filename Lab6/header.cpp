#include<iostream>
#include<stdio.h>
#include"header.h"

using namespace std;

void Stack::create(){
	head = NULL;
}

bool Stack::isEmpty(){
	return head == NULL;
}

void Stack::makeEmpty(){
	Node *p;
	while (head){
		p = head;
		head = head->next;
		delete p;
	}
}

void Stack::print(){
	cout << "Stack contents: ";
	Node *p = head;
	while (p){
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl << endl;
}

void Stack::push(char in){
	Node *nn = new Node;
	nn->data = in;
	nn->next = head;
	head = nn;
}

char Stack::pop(){
	if (head == NULL){
		return '\0';
	}
	Node *top = head;
	char toReturn = top->data;
	head = head->next;
	delete top;
	return toReturn;
}

char Stack::getHeadChar(){
	if (head == NULL){
		return '\0';
	}
	return head->data;
}