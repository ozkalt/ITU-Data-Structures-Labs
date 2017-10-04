#ifndef DIZIISLEMLERI_H
#define DIZIISLEMLERI_H
#include <stdio.h>
#include "kayit.h"

struct Dizi{
	Tel_Kayit * k;
	void olustur();
	void kapat();
	int ara(char[]);
	void ekle(Tel_Kayit *);
	void sil(int);
	void listele();
	void guncelle(int, Tel_Kayit*);
	int kayitsayisi;
	int total;
};
#endif
