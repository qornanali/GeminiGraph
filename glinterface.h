#ifndef  __GLINTERFACE_H__
#define  __GLINTERFACE_H__

#include <GL/freeglut_std.h>
#include "color.h"
#include "coord.h"
#include "textureloader.h"

void glIntBegin(int argcp, char **argv);
void glIntDrawCube(Coord coord, GLfloat radius, Color color, const char* textureImageName, BOOL showTexture);
void glIntDrawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color,  const char* textureImageName, BOOL showTexture);
void glIntDrawPrism3(Coord coord, GLfloat length, GLfloat width, GLfloat height,  Color color, const char* textureImageName, BOOL showTexture);
void glIntDrawPrismTrapezoid(Coord coord, GLfloat lengtha, GLfloat lengthb, GLfloat width, GLfloat height, Color color, const char* textureImageName, BOOL showTexture);
void glIntDrawCartesius(Coord coord, GLfloat radius);
void glIntLoadTexture(Image* image, GLuint * textureId);
void glIntEnd();

#endif
