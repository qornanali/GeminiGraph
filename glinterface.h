#ifndef  __GLINTERFACE_H__
#define  __GLINTERFACE_H__

#include <GL/freeglut_std.h>
#include "color.h"

#include <math.h>
#include <stdio.h>

typedef struct Coord{
	GLfloat x;
	GLfloat y;
	GLfloat z;
} Coord;

Coord insCoord(GLfloat x, GLfloat y, GLfloat z);
void glIntInit(int argcp, char **argv);
void glIntDrawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
void glIntDrawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat s, Color color);
void glIntDrawPrism(Coord coord, GLfloat radius, GLint nside, GLfloat height);
void glIntDrawPrism4(GLfloat x, GLfloat y, GLfloat z, GLfloat p, GLfloat l, GLfloat t, Color color);
void glIntDrawPrism4(GLfloat x, GLfloat y, GLfloat z, GLfloat p, GLfloat l, GLfloat t);
void glIntDrawPrism3(GLfloat x, GLfloat y, GLfloat z, GLfloat a, GLfloat t, GLfloat T, Color color);
void glIntDrawPrism3(GLfloat x, GLfloat y, GLfloat z, GLfloat a, GLfloat t, GLfloat T);
void glIntEnd();
void glIntDrawCartesius(GLfloat x, GLfloat y, GLfloat z, GLfloat s);

#endif
