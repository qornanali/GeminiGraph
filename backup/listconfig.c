#include "listconfig.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

P_Config allocConfig(){
	P_Config P = (P_Config) malloc(sizeof(Config));
	strcpy(P->value, "");
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

P_Config getConfig(LConfigs L, char name[]){
	P_Config P = L.first;
	while(P != NULL){
		if(strcmp(name, P->name) == 0){
			return P;
		}else{
			P = P->next;
		}
	}
	return P;	
}

void deAllocConfig (P_Config P){
	free(P);
}

void addConfigtToList(LConfigs * L, P_Config P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

void removeConfigFromList(LConfigs * L, char name[]){
	P_Config PDel = (*L).first;
	P_Config PRec = NULL;
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
 		deAllocConfig(PDel);
	}	
}

void printListItemConfigs(LConfigs L){
	P_Config P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %s\n", i, P->name, P->value);
		P = P->next;
		i++;
	}
}

void initListConfigs(LConfigs * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

P_Config createInstanceConfig(char name[], char value[]){
	P_Config P = allocConfig();
	strcpy(P->name, name);
	strcpy(P->value, value);
	return P;
}
