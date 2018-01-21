#include "list_int.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

P_Int allocInt(){
	P_Int P = (P_Int) malloc(sizeof(Int));
	P->value = 0;
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

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

void deAllocInt (P_Int P){
	free(P);
}

void addIntToList(LInts * L, P_Int P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

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

void printListItemInts(LInts L){
	P_Int P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %d\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

void initListInts(LInts * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

P_Int createInstanceInt(char name[10], unsigned int value){
	P_Int P = allocInt();
	P->value = value;
	strcpy(P->name, name);
	return P;
}
