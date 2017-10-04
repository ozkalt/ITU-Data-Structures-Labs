//
//  main.cpp
//  DS_Lab11_berk
//
//  Created by Tuğba Özkal on 21.12.2016.
//  Copyright © 2016 Tuğba Özkal. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include "node.h"

using namespace std;

Tree defter;

void menu_yazdir();
bool islem_yap(char);
void kayit_ara();
void kayit_ekle();
void kayit_sil();
void kayit_guncelle();
void kayit_listele();


int main(){
    defter.create();
    bool bitir = false;
    char secim;
    while (!bitir) {
        menu_yazdir();
        cin >> secim;
        bitir = islem_yap(secim);
    }
    return 0;
}


void menu_yazdir(){
    cout << endl << endl;
    cout << "Phone Book Application" << endl;
    cout << "Choose an option" << endl;
    cout << "A: Search Record" << endl;
    cout << "E: Add Record" << endl;
    cout << "G: Update Record" << endl;
    cout << "S: Delete Record" << endl;
    cout << "L: Listele" << endl;
    cout << "C: Exit" << endl;
    cout << endl;
    cout << "Enter your option {A, E, G, S, L, C} : ";
}


bool islem_yap(char secim){
    bool sonlandir=false;
    switch (secim) {
        case 'A': case 'a':
            kayit_ara();
            break;
        case 'E': case 'e':
            kayit_ekle();
            break;
        case 'G': case 'g':
            kayit_guncelle();
            break;
        case 'S': case 's':
            kayit_sil();
            break;
        case 'L': case 'l':
            kayit_listele();
            break;
        case 'C': case 'c':
            cout << "Are you sure that you want to terminate the program? (E/H):";
            cin >> secim;
            if(secim=='E' || secim=='e')
                sonlandir=true;
            break;
        default:
            cout << "Error: You have made an invalid choice. Try again." << endl;
            break;
    }
    return sonlandir;
}


void kayit_ara(){
    char ad[NAME_LENGTH];
    cout << "Please enter the name of the person you want to search (press '*' for listing all):" << endl;
    cin.ignore(1000, '\n');
    cin.getline(ad,NAME_LENGTH);
    if(defter.search(ad)==0){
        cout << "Record can not be found" << endl;
    }
    getchar();
};


void kayit_ekle(){
    Phone_node yenikayit;
    cout << "Please enter the information of the person you want to save " << endl;
    cout << "Name : " ;
    cin.ignore(1000, '\n');
    cin.getline(yenikayit.name,NAME_LENGTH);
    cout << "Phone number :";
    cin >> setw(PHONENUM_LENGTH) >> yenikayit.phonenum;
    defter.add(&yenikayit);
    cout << "Record has been added" << endl;
    getchar();
};


void kayit_sil(){
    char ad[NAME_LENGTH];
    cout << "Please enter the name of the person you want to remove" << endl;
    cin.ignore(1000, '\n');
    cin.getline(ad, NAME_LENGTH);
    Phone_node * deletednode;
    deletednode = defter.search(ad);
    //defter.remove(deletednode);
    defter.remove(ad);
    getchar();
};


void kayit_guncelle(){
    char ad[NAME_LENGTH];
    cout << "Please enter the name of the person you want to update" << endl;
    cin.ignore(1000, '\n');
    cin.getline(ad, NAME_LENGTH);
    defter.update(ad);
};


void kayit_listele(){
    defter.traverse_inorder(defter.root);
    getchar();
}
