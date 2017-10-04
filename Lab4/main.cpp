#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <string.h>
#include <iomanip>
#include "list.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace std;

typedef List Datastructure;
Datastructure book;

void print_menu();
bool operate(char);
void search_record();
void add_record();
void add_number();
void delete_record();
void update_record();
void clear_list();
void print_all();

int main(){
    book.create();
    bool end = false;
    char choice;
    
    while(!end){
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
    cout << "A: Add Record" << endl;
    cout << "N: Add Number" << endl;
    cout << "U: Update Record" << endl;
    cout << "D: Delete Record" << endl;
    cout << "L: List Records" << endl;
    cout << "E: Exit" << endl << endl;
    cout << "Enter an option {S, A, U, D, L, E} : ";
};

bool operate(char choice){
    bool end = false;
    
    switch (choice){
        case 'S': case 's':
            search_record();
            break;
        case 'A': case 'a':
            add_record();
            break;
        case 'N': case 'n':
            add_number();
            break;
        case 'U': case 'u':
            update_record();
            break;
        case 'D': case 'd':
            delete_record();
            break;
        case 'L': case 'l':
            print_all();
            break;
        case 'E': case 'e':
            cout << "Are you sure that you wish to terminate the program? (Y/N): ";
            cin >> choice;
            if(choice == 'Y' || choice == 'y') end = true;
            break;
        default:
            cout << "Error, you've made an invalid choice. Please try again {S, A, U, D, L, E}: ";
            break;
    }
    return end;
};

void search_record(){
    char name [NAME_LENGTH];
    cout << "Please enter the name of the person you wish to search for. ('*' to view all): " << endl;
    cin.ignore(1000, '\n');
    cin.getline(name, NAME_LENGTH);
    
    if(book.search(name)==0){
        cout << "Record cannot be found. " << endl;
    }
    getchar();
};


void add_record(){
    char name[NAME_LENGTH], phone[PHONENUM_LENGTH], numtype[TYPE_LENGTH];		// numtype1[6] = { 'M', 'O', 'B', 'I', 'L', 'E' }, numtype2[6] = { 'W', 'O', 'R', 'K', '\0', '\0' }, numtype3[6] = { 'H', 'O', 'M', 'E', '\0', '\0' };
    int numbertype;
    
    cout << "Please enter the information of the person you wish to save. " << endl;
    cout << "Name: ";
    cin.ignore(1000, '\n');
    cin.getline(name, NAME_LENGTH);
    int validity = book.search2(name);
    if (validity != 0){
        cout << "This name already exists!" << endl;
        return;
    }
    book.insert(name);
    cout << "Record has been added. " << endl;
    getchar();
};


void add_number(){
    char name[NAME_LENGTH], phone[PHONENUM_LENGTH], numtype[TYPE_LENGTH], numtype1[7] = { 'M', 'o', 'b', 'i', 'l', 'e', '\0' }, numtype2[7] = { 'W', 'o', 'r', 'k', '\0', '\0', '\0' }, numtype3[7] = { 'H', 'o', 'm', 'e', '\0', '\0', '\0' };
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
            book.create_number(name, phone, numtype1);
            break;
        case 2:
            book.create_number(name, phone, numtype2);
            break;
        case 3:
            book.create_number(name, phone, numtype3);
            break;
    }
    cout << "Number has been added. " << endl;
    getchar();
};

void delete_record(){
    char name[NAME_LENGTH];
    
    cout << "Please enter the name of the person you wish to delete ('*' to view all): " << endl;
    cin.ignore(1000, '\n');
    cin.getline(name, NAME_LENGTH);
    
    Phone_node* numpeople = book.search(name);
    
    if (numpeople == NULL){
        cout << "Record cannot be found. " << endl;
    }
    else {
        book.remove(name);
        cout << "Record has been deleted. " << endl;
    }
    getchar();
};

void update_record(){
    char name[NAME_LENGTH];
    char updatename[NAME_LENGTH];
    
    cout << "Please enter the name of the person you want to update ('*' to list all):" << endl;
    cin.ignore(1000, '\n');
    cin.getline(name,NAME_LENGTH);
    
    int numpeople=book.search2(name);
    
    if(numpeople == 0)
        cout << "Record can not be found." << endl;
    else{
        cout << "Please enter the up-to-date information" << endl;
        cout << "Name : " ;
        cin.ignore(1000, '\n');
        cin.getline(updatename, NAME_LENGTH);
        book.update(numpeople, updatename);
        cout << "Record has been updated successfully" <<endl;
    }
    getchar();
};

void print_all(){
    book.printList();
    getchar();
};

void clear_list(){
    getchar();
};
