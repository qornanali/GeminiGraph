/*
Nama file : list_int.c
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengolah linked list bertipe data integer
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 


#include "list_int.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Method fungsi untuk mengalokasikan elemen baru pada memori. */
P_Int allocInt(){
	P_Int P = (P_Int) malloc(sizeof(Int));
	P->value = 0;
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

/* Method fungsi untuk mencari satu elemen pada linked list integer. */
P_Int getInt(LInts L, char name[]){
	P_Int P = L.first;
	while(P != NULL){
		if(strcmp(name, P->name) == 0){
			return P;
		}else{
			P = P->next;
		}
	}
	return P;	
}

/* Method prosedur untuk menghapus suatu elemen pada linked list di memori. */
void deAllocInt (P_Int P){
	free(P);
}

/* Method prosedur untuk menambah satu elemen baru pada linked list integer. */
void addIntToList(LInts * L, P_Int P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list integer. */
void removeIntFromList(LInts * L, char name[]){
	P_Int PDel = (*L).first;
	P_Int PRec = NULL;
	int isFound = 0;
	while(PDel != NULL && !isFound){
		if(strcmp(name, PDel->name) == 0){
			isFound = 1;
		}else{
			PRec = PDel;
			PDel = PDel->next;	
		}
	}
	if(isFound){
		if(PRec == NULL && PDel->next == NULL){ 
			(*L).first = NULL; 
		}else if(PRec == NULL){ 
			(*L).first = PDel->next; 
		}else{ 
			PRec->next = PDel->next; 
		}
 		PDel->next;
 		deAllocInt(PDel);
	}	
}

/* Method prosedur untuk menginisiasikan struct LInts. */
void printListItemInts(LInts L){
	P_Int P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %d\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

/* Method prosedur untuk menampilkan isi masing-masing elemen yang ada pada linked list integer. */
void initListInts(LInts * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

/* Method fungsi untuk memasukkan nilai kepada elemen yang sudah dialokasikan pada memori. */
P_Int createInstanceInt(char name[], unsigned int value){
	P_Int P = allocInt();
	P->value = value;
	strcpy(P->name, name);
	return P;
}
