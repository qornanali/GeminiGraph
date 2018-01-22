/*
Nama file : coord.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk menyimpan nilai float kordinat x, y, dan z.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#ifndef  __COORD_H__
#define  __COORD_H__

#define DEFAULT_COORD insCoord(0.0, 0.0, 0.0)

typedef struct Coord{
	float x;
	float y;
	float z;
} Coord;

/* Method fungsi untuk mengembalikan nilai variabel baru yang sudah dimasukkan nilai ke dalam
masing-masing atributnya. */
Coord insCoord(float x, float y, float z);

#endif
