#ifndef  __INTERFACE_H__
#define  __INTERFACE_H__

#include <GL/glut.h>
#include "color.h"
#include "coord.h"

void drawCube(Coord coord, GLfloat radius, Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat);
void drawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color[],  GLuint textureId, BOOL bindings[], GLfloat repeat);
void drawPrismTrapezoid(Coord coord, GLfloat lengtha, GLfloat lengthb, GLfloat width, GLfloat height, Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat);
void drawCartesius(Coord coord, GLfloat radius);

#endif
