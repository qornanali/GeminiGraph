/*
Nama file : list_string.c
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengolah linked list bertipe data string.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#include "list_string.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Method fungsi untuk mengalokasikan elemen baru pada memori. */
P_String allocString(){
	P_String P = (P_String) malloc(sizeof(String));
	strcpy(P->value, "");
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

/* Method fungsi untuk mencari satu elemen pada linked list integer */
P_String getString(LStrings L, char name[]){
	P_String P = L.first;
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
void deAllocString (P_String P){
	free(P);
}

/* Method prosedur untuk menambah satu elemen baru pada linked list string */
void addStringToList(LStrings * L, P_String P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list string. */
void removeStringFromList(LStrings * L, char name[]){
	P_String PDel = (*L).first;
	P_String PRec = NULL;
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
 		deAllocString(PDel);
	}	
}

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list string.. */
void printListItemStrings(LStrings L){
	P_String P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %s\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

/* Method prosedur untuk menampilkan isi masing-masing elemen yang ada pada linked list integer. */
void initListStrings(LStrings * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

/* Method fungsi untuk memasukkan nilai kepada elemen yang sudah dialokasikan pada memori. */
P_String createInstanceString(char name[], char value[]){
	P_String P = allocString();
	strcpy(P->name, name);
	strcpy(P->value, value);
	return P;
}
