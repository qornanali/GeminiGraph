#ifndef  __LIST_INT_H__
#define  __LIST_INT_H__

typedef struct Int * P_Int;
typedef struct Int{
 	unsigned int value;
 	char name[15];
	P_Int next;
} Int;
typedef struct LInts{
	P_Int first;
	P_Int last;
} LInts;

P_Int allocInt();
P_Int getInt(LInts L, char name[]);
void deAllocInt (P_Int P);
void addIntToList(LInts * L, P_Int P);
void removeIntFromList(LInts * L, char name[]);
void initListInts(LInts * L);
void printListItemInts(LInts L);
P_Int createInstanceInt(char name[10], unsigned int value);

#endif
