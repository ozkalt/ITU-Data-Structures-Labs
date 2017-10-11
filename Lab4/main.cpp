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
    char name[NAME_LENGTH], lastname[NAME_LENGTH], phone[PHONENUM_LENGTH];
    
    cout << "Please enter the information of the person you wish to save. " << endl;
    cout << "Name: ";
    cin.ignore(1000, '\n');
    cin.getline(name, NAME_LENGTH);
    cout << "Last Name: ";
    cin.getline(lastname, NAME_LENGTH);
    int validity = book.search2(name, lastname);
    if (validity != 0){
        cout << "This name already exists!" << endl;
        return;
    }
    book.insert(name, lastname, phone);
    cout << "Record has been added. " << endl;
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
        book.remove(numpeople);
        cout << "Record has been deleted. " << endl;
    }
    getchar();
};

void update_record(){
    char name[NAME_LENGTH];
    char updatename[NAME_LENGTH];
    char lastname[NAME_LENGTH];
    char updatelastname[NAME_LENGTH];
    
    cout << "Please enter the name of the person you want to update ('*' to list all):" << endl;
    cin.ignore(1000, '\n');
    cin.getline(name,NAME_LENGTH);
    cout << "Please enter the last name of the person you want to update:" << endl;
    cin.ignore(1000, '\n');
    cin.getline(lastname,NAME_LENGTH);
    
    int numpeople=book.search2(name,  lastname);
    
    if(numpeople == 0)
        cout << "Record can not be found." << endl;
    else{
        cout << "Please enter the up-to-date information" << endl;
        cout << "Name : " ;
        cin.ignore(1000, '\n');
        cin.getline(updatename, NAME_LENGTH);
        cout << "Last Name : " ;
        cin.getline(updatelastname, NAME_LENGTH);
        book.update(numpeople, updatename, updatelastname);
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
