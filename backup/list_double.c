#include "list_Double.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

P_Double allocDouble(){
	P_Double P = (P_Double) malloc(sizeof(Double));
	P->value = 0;
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

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

void deAllocDouble (P_Double P){
	free(P);
}

void addDoubleToList(LDoubles * L, P_Double P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

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

void printListItemDoubles(LDoubles L){
	P_Double P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %lf\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

void initListDoubles(LDoubles * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

P_Double createInstanceDouble(char name[10], double value){
	P_Double P = allocDouble();
	P->value = value;
	
	return P;
}
