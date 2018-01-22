/*
Nama file : list_double.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi :
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#ifndef  __LISTDouble_H__
#define  __LISTDouble_H__

typedef struct Double * P_Double;
typedef struct Double{
 	char name[15];
 	double value;
	P_Double next;
} Double;
typedef struct LDoubles{
	P_Double first;
	P_Double last;
} LDoubles;

/* Method fungsi untuk mengalokasikan elemen baru pada memori. */
P_Double allocDouble();

/* Method fungsi untuk mencari satu elemen pada linked list double. */
P_Double getDouble(LDoubles L, char name[]);

/* Method prosedur untuk mengubah nilai suatu elemen pada linked list double. */
void setDouble(LDoubles * L, char name[], double value);

/* Method prosedur untuk menghapus suatu elemen pada linked list di memori. */
void deAllocDouble (P_Double P);

/* Method prosedur untuk menambah satu elemen baru pada linked list double. */
void addDoubleToList(LDoubles * L, P_Double P);

/* Method prosedur untuk menghapus satu elemen yang diinginkan pada linked list double. */
void removeDoubleFromList(LDoubles * L, char name[]);

/* Method prosedur untuk menginisiasikan struct LDoubles */
void initListDoubles(LDoubles * L);

/* Method prosedur untuk menampilkan isi masing-masing elemen yang ada pada linked list double. */
void printListItemDoubles(LDoubles L);

/* Method fungsi untuk memasukkan nilai kepada elemen yang sudah dialokasikan pada memori.. */
P_Double createInstanceDouble(char name[], double value);

#endif
