#include "fileoperations.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void Dosya::ekle(Tel_Kayit *ykptr){
	fseek(teldefteri, 0, SEEK_END);
	fwrite(ykptr, sizeof(Tel_Kayit), 1, teldefteri);
}

void Dosya::olustur(){
	dosyaadi = "teldefteri.txt";
	teldefteri = fopen(dosyaadi, "r+");
	if (!teldefteri){
		if (!(teldefteri = fopen(dosyaadi, "w+"))){
			cerr << "File can not be opened" << endl;
			exit(1);
		}
	}
}

void Dosya::kapat(){
	fclose(teldefteri);
}

int Dosya::ara(char aranacak[]){
	Tel_Kayit k;
	int sayac = 0;
	bool tum = false;
	int bulunan = 0;
	if (strcmp(aranacak, "*") == 0)
		tum = true;
	fseek(teldefteri, 0, SEEK_SET);
	while (!feof(teldefteri)){
		sayac++;
		fread(&k, sizeof(Tel_Kayit), 1, teldefteri);
		if (feof(teldefteri)) break;

		if (!tum && strncmp(k.ad, aranacak, strlen(aranacak)) != 0)
			continue;
		cout << sayac << "." << k.ad << " " << k.telno << endl;
		bulunan++;
	}
	return bulunan;
}

void Dosya::guncelle(int kayitno, Tel_Kayit *ykptr){
	if (fseek(teldefteri, sizeof(Tel_Kayit)*(kayitno - 1), SEEK_SET) == 0)
		fwrite(ykptr, sizeof(Tel_Kayit), 1, teldefteri);
}

void Dosya::sil(int kayitno){
	Tel_Kayit boskayit = { "", "" };
	if (fseek(teldefteri, sizeof(Tel_Kayit)*(kayitno - 1), SEEK_SET) == 0)
		fwrite(&boskayit, sizeof(Tel_Kayit), 1, teldefteri);
}

int Dosya::maintenance(){
	char *tempdosyaadi = "tempteldefteri.txt";
	FILE *tempteldefteri;
	Tel_Kayit r;
	int counter = 0;
	tempteldefteri = fopen(tempdosyaadi, "w+");
	if (!tempteldefteri){
		cerr << "Could not open temporary file for maintenance";
		exit(1);
	}
	
	fseek(teldefteri, 0, SEEK_SET);
	while (!feof(teldefteri)){
		fread(&r, sizeof(Tel_Kayit), 1, teldefteri);
		if (feof(teldefteri)) break;
		if (strcmp(r.ad, "") == 0) //bossa
			counter++;
		else
			fwrite(&r, sizeof(Tel_Kayit), 1, tempteldefteri);
	}
	fseek(tempteldefteri, 0, SEEK_SET);
	int say = 1;
	while (!feof(teldefteri)){
		sil(say);
		say++;
	}
	fclose(teldefteri);
	teldefteri = fopen(dosyaadi, "w+");
	fseek(teldefteri, 0, SEEK_SET);
	while (!feof(tempteldefteri)){
		fread(&r, sizeof(Tel_Kayit), 1, tempteldefteri);
		if (feof(tempteldefteri)) break;
		fwrite(&r, sizeof(Tel_Kayit), 1, teldefteri);
	}

	if (counter > 0) {
		fclose(teldefteri);
		fclose(tempteldefteri);
	/*	char command[500] = "copy ";
		strcat(command, tempdosyaadi);
		strcat(command, " ");
		strcat(command, dosyaadi);
		system(command);*/
		olustur();
	}
	return counter;
}
