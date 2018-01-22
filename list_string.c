#include "list_string.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

P_String allocString(){
	P_String P = (P_String) malloc(sizeof(String));
	strcpy(P->value, "");
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

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

void deAllocString (P_String P){
	free(P);
}

void addStringToList(LStrings * L, P_String P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

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

void printListItemStrings(LStrings L){
	P_String P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %s\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

void initListStrings(LStrings * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

P_String createInstanceString(char name[], char value[]){
	P_String P = allocString();
	strcpy(P->name, name);
	strcpy(P->value, value);
	return P;
}
