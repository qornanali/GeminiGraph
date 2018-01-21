#ifndef  __LISTTEXTURE_H__
#define  __LISTTEXTURE_H__

typedef struct Texture * P_Texture;
typedef struct Texture{
 	unsigned int id;
 	char name[15];
	P_Texture next;
} Texture;
typedef struct LTextures{
	P_Texture first;
	P_Texture last;
} LTextures;

P_Texture allocTexture();
P_Texture getTexture(LTextures L, char name[]);
void deAllocTexture (P_Texture P);
void addTexturetToList(LTextures * L, P_Texture P);
void removeTextureFromList(LTextures * L, char name[]);
void initListTextures(LTextures * L);
void printListItemTextures(LTextures L);
P_Texture createInstanceTexture(char name[10], unsigned int id);

#endif
