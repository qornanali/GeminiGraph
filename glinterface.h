#ifndef  __GLINTERFACE_H__
#define  __GLINTERFACE_H__

#include <GL/freeglut_std.h>
#include "color.h"
#include "coord.h"
#include "textureloader.h"

void drawCube(Coord coord, GLfloat radius, Color color, const char* textureImageName, BOOL showTexture);
void drawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color,  const char* textureImageName, BOOL showTexture);
void drawPrism3(Coord coord, GLfloat length, GLfloat width, GLfloat height,  Color color, const char* textureImageName, BOOL showTexture);
void drawPrismTrapezoid(Coord coord, GLfloat lengtha, GLfloat lengthb, GLfloat width, GLfloat height, Color color, const char* textureImageName, BOOL showTexture);
void drawCartesius(Coord coord, GLfloat radius);

#endif
