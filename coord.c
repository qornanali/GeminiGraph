/*
Nama file : coord.c
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk menyimpan nilai float kordinat x, y, dan z.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#include "coord.h"

/* Method fungsi untuk mengembalikan nilai variabel baru yang sudah dimasukkan nilai ke dalam
masing-masing atributnya. */
Coord insCoord(float x, float y, float z){
	Coord c;
	c.x = x;
	c.y = y;
	c.z = z;
	return c;
}
