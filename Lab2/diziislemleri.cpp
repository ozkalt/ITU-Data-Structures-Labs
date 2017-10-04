#include <iostream>
#include <stdlib.h>
//#include <cstdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include "diziislemleri.h"

using namespace std;

void Dizi::ekle(Tel_Kayit* ykptr){
	Tel_Kayit temp[MAX_KAYIT];
	Tel_Kayit * ptr = k;
	bool check = false;
	int i = 0;
	int j = 0;

	strcpy(temp[j].ad, ykptr->ad);
  	strcpy(temp[j].telno, ykptr->telno);
  	j++;
    
  	if (kayitsayisi == 0){
        	strcpy(ptr->ad, ykptr->ad);
        	strcpy(ptr->telno, ykptr->telno);
    	}
    	else{
       		for (i = 0; i < kayitsayisi; i++){
            		if (strcmp(ykptr->ad, ptr->ad) < 0){
                		strcpy(temp[j].ad, ptr->ad);
                		strcpy(temp[j].telno, ptr->telno);
                		j++;
            		}
            		ptr++;
        	}
        	ptr = k;
        
        	for (i = 0; i < kayitsayisi; i++){
            		if (strcmp(ykptr->ad, ptr->ad) > 0){
                		ptr++;
            		}
        	}
        
        	for (int x = 0; x < j; x++){
            		strcpy(ptr->ad, temp[x].ad);
            		strcpy(ptr->telno, temp[x].telno);
            		ptr++;
        	}
    	}
	kayitsayisi++;
}

void Dizi::olustur(){
	teldefteri = fopen("teldefteri.txt", "a+");
	int kayitsayisi = 0;

	fseek(teldefteri, 0, SEEK_SET);
    	while (!feof(teldefteri)){
    		if (feof(teldefteri)) break;
        	fread(&k[kayitsayisi], sizeof(Tel_Kayit), 1, teldefteri);
        	ekle(&k[kayitsayisi]);
    	}
    
    fclose(teldefteri);
}

void Dizi::kapat(){
	teldefteri = fopen("teldefteri.txt", "w+");
	int i;
	int silinen = 0;
	fseek(teldefteri, 0, SEEK_SET);
	for (i = 0; i < kayitsayisi; i++){
		if (strcmp(k[i].ad, "") != 0){
			fwrite(&k[i], sizeof(Tel_Kayit), 1, teldefteri);
		}
		else
			silinen++;
	}
	fclose(teldefteri);
}

int Dizi::ara(char aranacak[]){
	int sayac = 0;
	bool tumu = false;
	int bulunan, flag = 0;
	if (strcmp(aranacak, "*") == 0)
		tumu = true;
	for (int i = 0; i<kayitsayisi; i++){
		if (strcmp(k[i].ad, aranacak) == 0){
			cout << i + 1 << ". " << k[i].ad << endl;
			bulunan = i;
			flag = 1;
		}
	}
	return flag;
}

void Dizi::guncelle(int kayitno, Tel_Kayit *ykptr){
	strcpy(k[kayitno - 1].ad, ykptr->ad);
	strcpy(k[kayitno - 1].telno, ykptr->telno);
}

void Dizi::sil(int kayitno){
	Tel_Kayit temp;
	strcpy(temp.ad, "");
	strcpy(temp.telno, "");
	int indisno;
	indisno = kayitno - 1;
	k[indisno] = temp;
}

void Dizi::listele(){
	Tel_Kayit * ptr = k;
    	for (int i = 0; i < kayitsayisi; i++){
        	cout << i + 1 << ". " << ptr->ad << " \t" << ptr->telno << endl;
        	ptr++;
	}
}
