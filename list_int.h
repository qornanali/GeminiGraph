/*
Nama file : list_int.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengolah linked list bertipe data integer.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 


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

/* Method fungsi untuk mengalokasikan elemen baru pada memori. */
P_Int allocInt();

/* Method fungsi untuk mencari satu elemen pada linked list integer. */
P_Int getInt(LInts L, char name[]);

/* Method prosedur untuk menghapus suatu elemen pada linked list di memori. */
void deAllocInt (P_Int P);

/* Method prosedur untuk menambah satu elemen baru pada linked list integer. */
void addIntToList(LInts * L, P_Int P);

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list integer. */
void removeIntFromList(LInts * L, char name[]);

/* Method prosedur untuk menginisiasikan struct LInts. */
void initListInts(LInts * L);

/* Method prosedur untuk menampilkan isi masing-masing elemen yang ada pada linked list integer. */
void printListItemInts(LInts L);

/* Method fungsi untuk memasukkan nilai kepada elemen yang sudah dialokasikan pada memori. */
P_Int createInstanceInt(char name[], unsigned int value);

#endif
