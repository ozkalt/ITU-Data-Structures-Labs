#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<ctype.h>
#include"diziislemleri.h"

typedef Dizi Veriyapisi;
Veriyapisi defter;

using namespace std;

void menu_yazdir();
bool islem_yap(char );
void kayit_ekle();
void kayit_sil();
void kayit_listele();
void kayit_ara();
void kayit_guncelle();

int main()   {
	defter.olustur();
	bool finish = false;
	char secim;
	while (!finish) {
		menu_yazdir();
		cin >> secim;
		finish = islem_yap(secim);
	}
	defter.kapat();
	return EXIT_SUCCESS;
}

void menu_yazdir(){
	cout << endl << endl;
	cout << "Telephone application" << endl;
	cout << "Choose and operand" << endl;
	cout << "A: Add record" << endl;
	cout << "D: Delete record" << endl;
	cout << "L: List record" << endl;
	cout << "S: Search record" << endl;
	cout << "U: Update record" << endl;
	cout << "E: Exit" << endl;
	cout << endl << "Enter your selection {A, D, S, U, L, E}: ";
}

bool islem_yap(char secim){
	bool finish = false;
	switch (secim) {
	case 'A': case 'a':
		kayit_ekle();
		break;
	case 'D': case 'd':
		kayit_sil();
		break;
	case 'L': case 'l':
		kayit_listele();
		break;
	case 'U': case 'u':
		kayit_guncelle();
		break;
	case 'S': case 's':
		kayit_ara();
		break;
	case 'E': case 'e':
		cout << "Are you sure that you want to terminate the program? (Y/N):";
		cin >> secim;
		if (secim == 'Y' || secim == 'y'){
			cout << "Records are saved.";
			finish = true;
		}
		break;
	default:
		cout << "Error: You have made an invalid choice \nTry again {A, D, S, U, L, E} :" << endl;
		break;
	}
	return finish;
}

void kayit_ekle(){
	Tel_Kayit yenikayit;
	yenikayit.ad = new char[100];
	yenikayit.soyisim = new char[100];
	yenikayit.telno = new char[100];
	cout << "Please enter the information of the person you want to save " << endl;
	cout << "Name : ";
	cin.ignore(1000, '\n');
	cin.getline(yenikayit.ad, 100);
	cout << "Last name : ";
	cin.getline(yenikayit.soyisim, 100);
	cout << "Phone number :";
	cin.getline(yenikayit.telno, 100);
	defter.ekle(&yenikayit);
	cout << "Record has been added" << endl;
	getchar();
}

void kayit_sil(){
	char * ad = new char[];
	cout << "Please enter the name of the person you want to delete:" << endl;
	cin.ignore(1000, '\n');
	cin >> ad;
	int kisi = defter.ara(ad);
	if(kisi < 0){
		cout << "Record has been not found!" << endl;
	}
	else {
		defter.sil(kisi);
		cout << "Record has been deleted" << endl;
	}
	getchar();
}

void kayit_listele(){
	defter.listele();
	getchar();
}

void kayit_guncelle(){
	char * ad = new char[];

	cout << "Please enter the name of the person you want to update (press '*' for listing all):" << endl;
	cin.ignore(1000, '\n');
	cin >> ad;
	int kisi = defter.ara(ad);
	if (kisi < 0){
		cout << "Record can not be found." << endl;
	}
	else {
		Tel_Kayit yenikayit;
		yenikayit.ad = new char[];
		yenikayit.soyisim = new char[];
		yenikayit.telno = new char[];

		cout << "Please enter the up-to-date information." << endl;
		cout << "Name : ";
		cin >> yenikayit.ad;
		cout << "Last name : ";
		cin >> yenikayit.soyisim;
		cout << "Phone number : ";
		cin >> yenikayit.telno;
		defter.guncelle(kisi, &yenikayit);
		cout << "Record has been updated successfully." << endl;
	}
	getchar();
};

void kayit_ara(){
	char * ad = new char[];
	cout << "Please enter the name of the person you want to search (press '*' for listing all):" << endl;
	cin.ignore(1000, '\n');
	cin >> ad;
	if (defter.ara(ad) < 0){
		cout << "Record can not be found." << endl;
	}
	getchar();
};
