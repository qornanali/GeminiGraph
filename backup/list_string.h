#ifndef  __LIST_String_H__
#define  __LIST_String_H__

typedef struct String * P_String;
typedef struct String{
 	char name[15];
 	char value[50];
	P_String next;
} String;
typedef struct LStrings{
	P_String first;
	P_String last;
} LStrings;

P_String allocString();
P_String getString(LStrings L, char name[]);
void deAllocString (P_String P);
void addStringToList(LStrings * L, P_String P);
void removeStringFromList(LStrings * L, char name[]);
void initListStrings(LStrings * L);
void printListItemStrings(LStrings L);
P_String createInstanceString(char name[], char value[]);

#endif
