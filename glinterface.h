#ifndef  __GLINTERFACE_H__
#define  __GLINTERFACE_H__

#include <GL/freeglut_std.h>

#include <math.h>
#include <stdio.h>

void glIntInit(int argcp, char **argv);
void glIntDrawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
void glIntEnd();
void glIntDrawCartesius(GLfloat x, GLfloat y, GLfloat z, GLfloat s);
void cube (GLfloat size);

#endif
