#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iomanip>
#include "list.h"

using namespace std;

void List::create(){
	head = NULL;
	tail = NULL;
	nodecount = 0;
};

void List::close(){
	makeEmpty();
};

void List::makeEmpty(){
	Phone_node *p;
	number *q;

	while (head){
		p = head;
		head = head->next;
		q = p->phonenum;

		while (q){
			p->phonenum = p->phonenum->next;
			delete q;
			q = p->phonenum;
		}
		delete p;
	}
	nodecount = 0;
};

Phone_node * List::addName(char * name){
	Phone_node * newperson = new Phone_node;
	strcpy(newperson->name, name);
	newperson->phonenum = NULL;
	newperson->next = NULL;
	newperson->previous = NULL;
	return newperson;
};

void List::addPerson(char *newname){
	Phone_node *traverse, *behind, *newperson;
	number *newnum;
	traverse = head;
	newperson = new Phone_node;
	newperson = addName(newname);

	if (head == NULL){									//first node being added
		head = newperson;
		head->next = NULL;
		head->previous = NULL;
		nodecount++;
		return;
	}
	if (strcmp(newname, head->name) < 0){				//Insert to head of list
		newperson->next = head;
//		head->previous = newperson;
		head = newperson;
		newperson->next->previous = newperson;
		nodecount++;
		return;
	}
	while (traverse && (strcmp(newname, traverse->name) > 0)){		//newname's name comes after traverse
		tail = traverse;
		traverse = traverse->next;
	}

	if (traverse){													//Inserting new name in between 
		tail->next = newperson;
		newperson->previous = tail;
		newperson->next = traverse;
		traverse->previous = newperson;
	}
	else{															//insert to the end
		traverse = newperson;
		traverse->next = NULL;
		tail->next = traverse;
	}
	nodecount++;
}

void List::addNumber(char* name, char* phone, char* type){
	Phone_node *traverse;
	number *pn;
	traverse = head;
	
	number * newnum = new number;
	strcpy(newnum->num, phone);
	strcpy(newnum->type, type);
	while (traverse){
		if (strnicmp(name, traverse->name, strlen(name)) == 0){
			pn = traverse->phonenum;

			if (traverse->phonenum == NULL){
				traverse->phonenum = newnum;
			}
			else{
				pn = newnum;
			}
			traverse->phonenum->next = pn;
		}
		traverse = traverse->next;
	}
};


void List::removePerson(char* inname){
	Phone_node *traverse, *tail = NULL, *behind;
	number *pn;
	int counter = 1;
	traverse = head;
	behind = head;
	while (traverse){
		if (strnicmp(inname, traverse->name, strlen(inname)) == 0)	break;
		behind = traverse;
		traverse = traverse->next;
		if (traverse->next)
			tail = traverse->next;
	}

	if (traverse){
		behind->next = traverse->next;
		if (tail)
			behind = tail->previous;
		if (traverse->phonenum){
			pn = traverse->phonenum;
			while (pn){
				traverse->phonenum = traverse->phonenum->next;
				delete pn;
				pn = traverse->phonenum;
			}
		}
		delete traverse;
	}
	nodecount--;
}

void List::removeNumber(char* inname){
	Phone_node *traverse;
	number* pn;
	int choice;

	traverse = head;
	while (traverse){
		if (strnicmp(inname, traverse->name, strlen(inname)) == 0)	break;
		traverse = traverse->next;
	}

	if (traverse){
		if (traverse->phonenum){
			pn = traverse->phonenum;
			cout << "Which one is your want to remove?  ";
			while (pn){
				int i = 1;
				cout << i << ". " << pn->type << ": " << pn->num << endl;
				pn = pn->next;
			}
			cin >> choice;
			
			for (int i = 1; i < choice; i++){
				traverse->phonenum = traverse->phonenum->next;
				pn = traverse->phonenum;
			}
			if (pn->next != NULL)
				traverse->phonenum = pn->next;
			else
				traverse->phonenum = NULL;
			delete pn;	
		}
	}
}

Phone_node* List::search(char *target){
	Phone_node *traverse;
	number *pn;
	int counter = 0;
	traverse = head;

	bool all = false;

	if (target[0] == '*')
		all = true;

	while (traverse){
		counter++;
		pn = traverse->phonenum;
		if (all){
			cout << counter << ". " << traverse->name << endl;
			while (pn){
				cout << pn->type << " : " << pn->num << endl;
				pn = pn->next;
			}
		}
		else if (strnicmp(target, traverse->name, strlen(target)) == 0){
			cout << "Record # : " << counter << endl;
			cout << "Name: " << traverse->name << endl;
			if (traverse->phonenum != NULL){
				while (pn){
					cout << pn->type << " : " << pn->num << endl;
					pn = pn->next;
				}
			}
			return traverse;
		}
		traverse = traverse->next;
	}
	return NULL;
};

int List::search2(char *target){
	Phone_node *traverse;
	number *pn;
	int counter = 0;
	int found = 0;
	traverse = head;

	while (traverse){
		counter++;
		pn = traverse->phonenum;
		if (strnicmp(target, traverse->name, strlen(target)) == 0){
			found++;
		}
		traverse = traverse->next;
	}
	return found;
};

void List::updatePerson(char *newname){			//ONLY NAME
	Phone_node *traverse, *behind;
	number *temp, *pn;
	int counter = 1;
	traverse = head;
	behind = head;
	while (traverse){
		if (strnicmp(newname, traverse->name, strlen(newname)) == 0){
			pn = traverse->phonenum;
			while (pn){
				strcpy(temp->num, pn->num);
				strcpy(temp->type, pn->type);
				pn = pn->next;
				temp = temp->next;
			}
			behind->next = traverse->next;
			behind = traverse->next->previous;
			delete traverse;
			addName(newname);
			while (temp){
				addNumber(newname, temp->num, temp->type);
				temp = temp->next;
			}
		}
		behind = traverse;
		traverse = traverse->next;
	}
};

void List::updateNumber(char *inname){
	Phone_node *traverse;
	number* pn, *newnode;
	int choice;
	char *newnum;
	int numtype;

	traverse = head;
	while (traverse){
		if (strnicmp(inname, traverse->name, strlen(inname)) == 0)	break;
		traverse = traverse->next;
	}

	if (traverse){
		if (traverse->phonenum){
			pn = traverse->phonenum;
			cout << "Which one is your want to update?  ";
			while (pn){
				int i = 1;
				cout << i << ". " << pn->type << ": " << pn->num << endl;
				pn = pn->next;
			}
			cin >> choice;
			cout << "Enter the new number: ";
			cin.getline(newnum, PHONENUM_LENGTH);
			strcpy(newnode->num, newnum);
			cout << "Please Choose a Number Type: " << endl;
			cout << "1. Mobile" << endl;
			cout << "2. Work" << endl;
			cout << "3. Home" << endl;
			cout << "Please choose: {1, 2, 3}" << endl;
			cin >> numtype;
			switch (numtype){
			case 1:
				strcpy(newnode->type, "Mobile");
				break;
			case 2:
				strcpy(newnode->type, "Work");
				break;
			case 3:
				strcpy(newnode->type, "Home");
				break;
			}

			for (int i = 1; i < choice; i++){
				traverse->phonenum = traverse->phonenum->next;
				pn = traverse->phonenum;
			}

			traverse->phonenum->next = newnode;
			newnode->next = pn;
		}
	}
}

void List::printList(){
	Phone_node *traverse;
	number * pn;
	traverse = head;

	int counter = 1;

	while (traverse){
		cout << "\n" << "Record # " << counter << " : " << endl;
		cout << "Name : " << traverse->name << endl;
		pn = traverse->phonenum;
		while (pn){
			cout << pn->type << " : " << pn->num << endl;
			pn = pn->next;
		}
		traverse = traverse->next;
		counter++;
	}
};
