/*
Nama file : interface.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengimplementasikan fungsi yang ada di library freeglut untuk
membuat suatu bangun yang diinginkan.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#ifndef  __INTERFACE_H__
#define  __INTERFACE_H__

#include <GL/glut.h>
#include "color.h"
#include "coord.h"

/* Method prosedur untuk menampilkan bangun ruang kubus */
void drawCube(Coord coord, GLfloat radius, Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat);

/* Method prosedur untuk menampilkan bangun ruang prisma dengan alas segi empat */
void drawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color[],  GLuint textureId, BOOL bindings[], GLfloat repeat);

/* Method prosedur untuk menampilkan bangun ruang prisma dengan alas trapezium */
void drawPrismTrapezoid(Coord coord, GLfloat lengtha, GLfloat lengthb, GLfloat width, GLfloat height, Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat);

/* Method prosedur untuk menampilkan garis kartesius 3D */
void drawCartesius(Coord coord, GLfloat radius);

/* Method prosedur untuk menampilkan bangun ruang balok */
void drawBox(GLfloat width, GLfloat height, GLfloat depth, GLuint textFront, GLuint textBack, GLuint textRight, GLuint textLeft, GLuint textTop, GLuint textBottom, GLfloat textKoor);

#endif
