#ifndef DIZIISLEMLERI_H
#define DIZIISLEMLERI_H
#include <stdio.h>
#include "record.h"
#define MAX_KAYIT 100

struct Dizi{
	char* dosyaadi;
	FILE* teldefteri;
	Tel_Kayit k[MAX_KAYIT];
	void olustur();
	void kapat();
	void ekle(Tel_Kayit*);
	int ara(char[]);
	void sil(int kayitno);
	void guncelle(int kayitno, Tel_Kayit*);
	void listele();
	int kayitsayisi;
	void sirala(Tel_Kayit*);
};

#endif