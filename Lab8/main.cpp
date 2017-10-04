#include <iostream>
#include <string>
#include <iomanip>
#include "stack.h"
#include "queue.h"

#define UZUNLUK 15
#define N 5

using namespace std;

Stack s[4];
Queue q;
void add();
void remove();
void print();

int main(){
	for (int i = 0; i<4; i++)
		s[i].create();

	q.create();

	bool menu = true;
	while (menu){
		cout << endl << "Choose operation";
		cout << endl << "Ad(A) \nRemove(R) \nExit(E) \nPrint(P) " << endl;
		char op;
		cin >> op;
		if (op == 'A' || op == 'a')
			add();
		else if (op == 'R' || op == 'r')
			remove();
		else if (op == 'P' || op == 'p')
			print();
		else if (op == 'E' || op == 'e')
			menu = false;
	}

	q.close();

	for (int i = 0; i < 4; i++)
		s[i].close();

	getchar();
	return EXIT_SUCCESS;
}


void add(){
	int area;
	char plaka[UZUNLUK];

	cout << endl << "Choose Area(1-4)	";
	cin >> area;

	if (area < 1 || area > 4){
		cout << "Invalid area." << endl;
		add();
	}
	else{
		cout << endl << "Enter License Plate	";
		cin >> plaka;

		char *plate = new char[strlen(plaka) + 1];
		strcpy(plate, plaka);

		if (s[area - 1].limit == N)
			cout << endl << "Area is Full" << endl;
		else{
			s[area - 1].push(plate);
			cout << endl << "Car parked the area." << endl;
		}
	}
}

void remove(){
	int area;
	char plaka[UZUNLUK];
	int count = 0;
	int count2 = 0;

	int current[4] = { s[0].limit, s[1].limit, s[2].limit, s[3].limit };

	cout << endl << "Choose Area	";
	cin >> area;

	cout << endl << "Enter License Plate	";
	cin >> plaka;

	char *plate = new char[strlen(plaka) + 1];
	strcpy(plate, plaka);

	Node *traverse;
	traverse = s[area - 1].head;

	while (traverse){
		if (strcmp(traverse->data, plate) == 0){
			cout << endl << "Car has found";
			break;
		}
		count++;
		traverse = traverse->next;
	}


	for (int i = 0; i<4; i++){
		while (s[i].limit != N && count != 0){
			if (area != (i + 1)){
				s[i].push(s[area - 1].pop());
				count--;
			}
			else
				break;
		}
	}
	
	int temp = count;

	if (count != 0){
		while (count != 0){
			q.enqueue(s[area - 1].pop());
			count2++;
			count--;
		}
	}

	s[area - 1].pop();

	if (temp != 0){
		for (int i = 1; i < count2; i++){
			q.enqueue(q.dequeue());
		}
		for (int i = 0; i < count2; i++){
			s[area - 1].push(q.dequeue());
		}
	}



	for (int i = 3; i>-1; i--){
		if (i + 1 != area)
		while (current[i] != s[i].limit){
			s[area - 1].push(s[i].pop());
		}
	}

}

void print(){
	Node *traverse[4] = { s[0].head, s[1].head, s[2].head, s[3].head };

	for (int j = 0; j < N; j++){
		for (int i = 0; i < 4; i++){
			if (s[i].limit >= N - j && traverse[i]){
				cout << "|";
				cout << setw(10) << traverse[i]->data;
				cout << "|";
				traverse[i] = traverse[i]->next;
			}
			else{
				cout << "|";
				cout << setw(10) << " ";
				cout << "|";
			}

		}
		cout << "|";
		cout << endl << endl << endl << endl;
	}
	cout << "___________________________________________________";
}

