/*
Nama file : list_string.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengolah linked list bertipe data string.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

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

/* Method fungsi untuk mengalokasikan elemen baru pada memori. */
P_String allocString();

/* Method fungsi untuk mencari satu elemen pada linked list integer */
P_String getString(LStrings L, char name[]);

/* Method prosedur untuk menghapus suatu elemen pada linked list di memori. */
void deAllocString (P_String P);

/* Method prosedur untuk menambah satu elemen baru pada linked list string */
void addStringToList(LStrings * L, P_String P);

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list string. */
void removeStringFromList(LStrings * L, char name[]);

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list string.. */
void initListStrings(LStrings * L);

/* Method prosedur untuk menampilkan isi masing-masing elemen yang ada pada linked list integer. */
void printListItemStrings(LStrings L);

/* Method fungsi untuk memasukkan nilai kepada elemen yang sudah dialokasikan pada memori. */
P_String createInstanceString(char name[], char value[]);

#endif
