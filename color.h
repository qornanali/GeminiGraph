/*
Nama file : color.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk menyimpan nilai float untuk perpaduan warna red, green, dan blue
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#ifndef  __COLOR_H__
#define  __COLOR_H__

#define DEFAULT_COLOR WHITE
#define WHITE insColor(1.0, 1.0, 1.0)
#define PURPLE insColor(1.0, 0.0, 1.0)
#define GREEN  insColor(0.0, 1.0, 0.0) 
#define RED insColor(1.0, 0.0, 0.0)
#define BLUE insColor(0.0, 0.0, 1.0)

typedef struct Color{
	float r;
	float g;
	float b;
} Color;

/* Mengembalikan nilai variabel baru yang sudah dimasukkan nilai ke dalam masing-masing
atributnya. */
Color insColor(float r, float g, float b);

#endif
