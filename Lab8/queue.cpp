#include <iostream>
#include "queue.h"

typedef char QueueDataType;

void Queue::create(){
	front = NULL; back = NULL;
}
void Queue::close(){
	QNode *p;
	while (front) {
		p = front;
		front = front->next;
		delete p;
	}
}
void Queue::enqueue(char *newdata){
	QNode *newnode = new QNode;
	newnode->data = newdata;
	newnode->next = NULL;
	if (isEmpty()) {		// first element?
		back = newnode;
		front = back;
	}
	else {
		back->next = newnode;
		back = newnode;
	}
}
char* Queue::dequeue() {
	QNode *topnode;
	char *temp;
	topnode = front;
	front = front->next;
	temp = topnode->data;
	delete topnode;
	return temp;
}
bool Queue::isEmpty() {
	return front == NULL;
}