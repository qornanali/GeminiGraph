#include "listTexture.h"

#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

P_Texture allocTexture(){
	P_Texture P = (P_Texture) malloc(sizeof(Texture));
	P->id = 0;
	strcpy(P->name, "");
	P->next = NULL;
	return P;
}

P_Texture getTexture(LTextures L, char name[]){
	P_Texture P = L.first;
	while(P != NULL){
		if(strcmp(name, P->name) == 0){
			return P;
		}else{
			P = P->next;
		}
	}
	return P;	
}

void deAllocTexture (P_Texture P){
	free(P);
}

void addTexturetToList(LTextures * L, P_Texture P){
	if((*L).first == NULL){
		(*L).first = P;
	}else{
		((*L).last)->next = P;
	}
	(*L).last = P;
}

void removeTextureFromList(LTextures * L, char name[]){
	P_Texture PDel = (*L).first;
	P_Texture PRec = NULL;
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
 		deAllocTexture(PDel);
	}	
}

void printListItemTextures(LTextures L){
	P_Texture P = L.first;
	int i = 0;
	while(P != NULL){
		printf("%d -> %s %d\n", i, P->name, P->id);
		P = P->next;
		i++;
	}
}

void initListTextures(LTextures * L){
	(*L).first = NULL;
	(*L).last = NULL;
}

P_Texture createInstanceTexture(char name[10], unsigned int id){
	P_Texture P = allocTexture();
	P->id = id;
	strcpy(P->name, name);
	return P;
}
