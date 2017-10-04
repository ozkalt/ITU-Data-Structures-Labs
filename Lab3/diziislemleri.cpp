#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iomanip>
#include"diziislemleri.h"

using namespace std;

void Dizi::olustur(){
	total = 2;
	k = new Tel_Kayit[total];
	kayitsayisi = 0;
};
void Dizi::kapat(){
	delete[] k;
}


void Dizi::ekle(Tel_Kayit *ykptr){
	if (total == kayitsayisi){
		total *= 2;
		Tel_Kayit * t = new Tel_Kayit[total];
		for (int i = 0; i < kayitsayisi; i++){
			t[i] = k[i];
		}
		
		delete[] k;
		k = t;
	}

	int al = strlen(ykptr->ad);
	int sl = strlen(ykptr->soyisim);
	int tl = strlen(ykptr->telno);

	k[kayitsayisi].ad = new char[al];
	k[kayitsayisi].soyisim = new char[sl];
	k[kayitsayisi].telno = new char[tl];

	if (kayitsayisi == 0){
		strcpy(k[kayitsayisi].ad, ykptr->ad);
		strcpy(k[kayitsayisi].soyisim, ykptr->soyisim);
		strcpy(k[kayitsayisi].telno, ykptr->telno);
	}	
	else {
		int i = kayitsayisi-1;
		if (strcmp(ykptr->ad, k[kayitsayisi-1].ad) < 0){
			while (strcmp(ykptr->ad, k[i].ad) < 0){
				strcpy(k[i+1].ad, k[i].ad);
				strcpy(k[i+1].soyisim, k[i].soyisim);
				strcpy(k[i+1].telno, k[i].telno);
				i--;
				if (i < 0)
					break;
			}
		}
		i++;
		strcpy(k[i].ad, ykptr->ad);
		strcpy(k[i].soyisim, ykptr->soyisim);
		strcpy(k[i].telno, ykptr->telno);
	}
	
	kayitsayisi++;
};

void Dizi::guncelle(int kayitno, Tel_Kayit *ykptr){
	sil(kayitno);
	ekle(ykptr);
}

int Dizi::ara(char aranacak[]){
	int sayac = 0;
	bool tum = false;
	int bulunan = 0, flag = -1;

	if (strcmp(aranacak, "*") == 0)
		tum = true;

	for (int i = 0; i < kayitsayisi; i++){
		if (strcmp(k[i].ad, aranacak) == 0){
			cout << i + 1 << ". " << k[i].ad << " " << k[i].soyisim << "\t" << k[i].telno << endl;
			bulunan++;
			flag = i;
		}
	}
	return flag;
}

void Dizi::sil(int kayitno){
	kayitsayisi--;
	for (int i = kayitno; i < kayitsayisi; i++){
		k[i] = k[i + 1];
	}
};

void Dizi::listele(){
	Tel_Kayit * ptr = k;
	if (kayitsayisi == 0)
		cout << "There is no record.";
	else{
		for(int i = 0; i<kayitsayisi; i++){
			cout << i + 1 << ". " << k[i].ad << " " << k[i].soyisim << "\t" << k[i].telno << endl;
			ptr++;
		}
	}
};
