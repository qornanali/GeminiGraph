/*
Nama file : color.c
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk menyimpan nilai float untuk perpaduan warna red, green, dan blue
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#include "color.h"

/* Mengembalikan nilai variabel baru yang sudah dimasukkan nilai ke dalam masing-masing
atributnya. */
Color insColor(float r, float g, float b){
	Color c;
	c.r = r;
	c.g = g;
	c.b = b;
	return c;
}

