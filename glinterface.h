#ifndef  __GLINTERFACE_H__
#define  __GLINTERFACE_H__

#include <GL/freeglut_std.h>
#include "color.h"
#include "coord.h"
#include "textureloader.h"

void glIntBegin(int argcp, char **argv);
void glIntDrawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color, GLuint textureId);
void glIntDrawPrism3(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color);
void glIntDrawCartesius(Coord coord, GLfloat radius);
GLuint glIntLoadTexture(Image* image);
void glIntEnd();

#endif
