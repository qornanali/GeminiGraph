#ifndef  __GLINTERFACE_H__
#define  __GLINTERFACE_H__

#include <math.h>
#include <stdio.h>

#include <GL/freeglut_std.h>
#include "color.h"
#include "coord.h"

void glIntBegin(int argcp, char **argv);
void glIntDrawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color);
void glIntDrawPrism3(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color);
void glIntDrawCartesius(Coord coord, GLfloat radius);
void glIntEnd();

#endif
