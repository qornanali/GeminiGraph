/*
Nama file : pendopo.h
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang befungsi untuk mengolah dan memadukan apa yang disediakan interface.c untuk membuat suatu bagian bangun dari pendopo
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#ifndef  __PENDOPO_H__
#define  __PENDOPO_H__

#define GROUND_LEVEL 0.0

/* Method prosedur untuk membuat dataran tanah */
void drawLand();

/* Method prosedur untuk membuat langit. */
void drawSky();

/* Method prosedur untuk membuat tangga */
void drawStairs();

/* Method prosedur untuk membuat ventilasi. */
void drawVents();

/* Method prosedur untuk membuat atap yang di tengah. */
void drawGapura();

/* Method prosedur untuk membuat alas atap. */
void drawRoof();

/* Method prosedur untuk membuat atap yang paling atas. */
void drawRoofMid();

/* Method prosedur untuk memanggil drawRoofMid(), drawRoofBot() dan drawRoofTop(). */
void drawRoofTop();

/* Method prosedur untuk membuat gapura */
void drawRoofBot();

/* Method prosedur untuk membuat pilar dan dinding bangunan. */
void drawCoreBuilding(float width, float height, float depth, unsigned int textFront, unsigned int textBack, unsigned int textRight, unsigned int textLeft, unsigned int textTop, unsigned int textBottom, float textKoor);


#endif
