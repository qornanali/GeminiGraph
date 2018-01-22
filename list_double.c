/*
Nama file : list_double.c
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengolah linked list bertipe data double
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#include "list_Double.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Method fungsi untuk mengalokasikan elemen baru pada memori. */
P_Double allocDouble(){
	P_Double P = (P_Double) malloc(sizeof(Double));
	P->value = 0;
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

/* Method fungsi untuk mencari satu elemen pada linked list double. */
P_Double getDouble(LDoubles L, char name[]){
	P_Double P = L.first;
	while(P != NULL){
		if(strcmp(name, P->name) == 0){
			return P;
		}else{
			P = P->next;
		}
	}
	return P;	
}

/* Method prosedur untuk mengubah nilai suatu elemen pada linked list double. */
void setDouble(LDoubles * L, char name[], double value){
	P_Double P = getDouble((*L), name);
	if(P != NULL){
		P->value = value;
	}
}

/* Method prosedur untuk menghapus suatu elemen pada linked list di memori. */
void deAllocDouble (P_Double P){
	free(P);
}

/* Method prosedur untuk menambah satu elemen baru pada linked list double. */
void addDoubleToList(LDoubles * L, P_Double P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list double. */
void removeDoubleFromList(LDoubles * L, char name[]){
	P_Double PDel = (*L).first;
	P_Double PRec = NULL;
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
 		deAllocDouble(PDel);
	}	
}

/* Method prosedur untuk menampilkan isi masing-masing elemen yang ada pada linked list double. */
void printListItemDoubles(LDoubles L){
	P_Double P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %lf\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

/* Method prosedur untuk menginisiasikan struct LDoubles */
void initListDoubles(LDoubles * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

/* Method fungsi untuk memasukkan nilai kepada elemen yang sudah dialokasikan pada memori.. */
P_Double createInstanceDouble(char name[], double value){
	P_Double P = allocDouble();
	strcpy(P->name, name);
	P->value = value;
	return P;
}
