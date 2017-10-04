#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>
#include "list.h"

using namespace std;

typedef List Datastructure;
Datastructure book;

void print_menu();
bool operate(char);
void search_record();
void add_person();
void add_number();
void remove_person();
void remove_number();
void update_person();
void update_number();
void print_all();

int main(){
	book.create();
	bool end = false;
	char choice;

	while (!end){
		print_menu();
		cin >> choice;
		end = operate(choice);
	}
	book.close();
	return EXIT_SUCCESS;
};

void print_menu(){
	cout << endl << endl;
	cout << "Phone Book Application" << endl;
	cout << "Choose an operation" << endl;
	cout << "S: Search Record" << endl;
	cout << "A: Add Person" << endl;
	cout << "N: Add Number" << endl;
	cout << "U: Update Person" << endl;
	cout << "G: Update Number" << endl;
	cout << "R: Remove Person" << endl;
	cout << "D: Remove Number" << endl;
	cout << "L: List Records" << endl;
	cout << "E: Exit" << endl << endl;
	cout << "Enter an option {S, A, N, U, G, R, D, L, E} : ";
};

bool operate(char choice){
	bool end = false;

	switch (choice){
	case 'S': case 's':
		search_record();
		break;
	case 'A': case 'a':
		add_person();
		break;
	case 'N': case 'n':
		add_number();
		break;
	case 'U': case 'u':
		update_person();
		break;
	case 'G': case 'g':
		update_number();
		break;
	case 'R': case 'r':
		remove_person();
		break;
	case 'D': case 'd':
		remove_number();
		break;
	case 'L': case 'l':
		print_all();
		break;
	case 'E': case 'e':
		cout << "Are you sure that you wish to terminate the program? (Y/N): ";
		cin >> choice;
		if (choice == 'Y' || choice == 'y') end = true;
		break;
	default:
		cout << "Error, you've made an invalid choice. Please try again {S, A, U, D, L, E}: ";
		cin >> choice;
		end = operate(choice);
		break;
	}
	return end;
};

void search_record(){
	char name[NAME_LENGTH];
	cout << "Please enter the name of the person you wish to search for. ('*' to view all): " << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);

	if (book.search(name) == 0){
		cout << "Record cannot be found. " << endl;
	}
	getchar();
};


void add_person(){
	char name[NAME_LENGTH];

	cout << "Please enter the information of the person you wish to save. " << endl;
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);
	int validity = book.search2(name);
	if (validity != 0){
		cout << "This name already exists!" << endl;
		return;
	}
	book.addPerson(name);
	cout << "Record has been added. " << endl;
	getchar();
};


void add_number(){
	char name[NAME_LENGTH], phone[PHONENUM_LENGTH];
	int numbertype;

	cout << "Please enter the information of the person you wish to save. " << endl;
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);
	int validity = book.search2(name);
	if (validity == 0){
		cout << endl << "There is no contact as " << name << endl << "Please try again..." << endl;
		getchar();
		return;
	}
	cout << "Phone Number: ";
	cin.getline(phone, PHONENUM_LENGTH);

	cout << "Please Choose a Number Type: " << endl;
	cout << "1. Mobile" << endl;
	cout << "2. Work" << endl;
	cout << "3. Home" << endl;
	cout << "Please choose: {1, 2, 3}" << endl;
	cin >> numbertype;

	switch (numbertype){
	case 1:
		book.addNumber(name, phone, "Mobile");
		break;
	case 2:
		book.addNumber(name, phone, "Work");
		break;
	case 3:
		book.addNumber(name, phone, "Home");
		break;
	}
  	cout << "Number has been added. " << endl;
	getchar();
};

void remove_person(){
	char name[NAME_LENGTH];

	cout << "Please enter the name of the person you wish to delete ('*' to view all): " << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);

	book.removePerson(name);
	getchar();
};

void remove_number(){
	char name[NAME_LENGTH];

	cout << "Please enter the name of the person you wish to delete whom number ('*' to view all): " << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);

	Phone_node* numpeople = book.search(name);

	if (numpeople == NULL){
		cout << "Record cannot be found. " << endl;
	}
	else {
		book.removeNumber(name);
	}
	getchar();
};

void update_person(){
	char name[NAME_LENGTH];
	char updatedname[NAME_LENGTH];

	cout << "Please enter the name of the person you want to update ('*' to list all):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);

	Phone_node* numpeople = book.search(name);

	if (numpeople == NULL)
		cout << "Record can not be found." << endl;
	else{
		Phone_node newnode;
		cout << "Please enter the up-to-date information" << endl;
		cout << "Name : ";
		cin.ignore(1000, '\n');
		cin.getline(updatedname, NAME_LENGTH);
		book.updatePerson(updatedname);
		cout << "Record has been updated successfully" << endl;
	}
	getchar();
};

void update_number(){
	char name[NAME_LENGTH];

	cout << "Please enter the name of the person you want to update whom number ('*' to list all):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);

	Phone_node* numpeople = book.search(name);

	if (numpeople == NULL)
		cout << "Record can not be found." << endl;
	else{
		book.updatePerson(name);
		cout << "Record has been updated successfully" << endl;
	}
	getchar();
};

void print_all(){
	book.printList();
	getchar();
};