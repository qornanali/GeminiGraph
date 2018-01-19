#ifndef  __PENDOPO_H__
#define  __PENDOPO_H__

#include "glinterface.h"

void pendopoStart(int argcp, char ** argv);

void onWorldDisplay();
void onWorldIdle();
void onWorldReshape(int w, int h); 
void onSpecialKeyClicked(int key, int x, int y ); 
void onNormalKeyClicked(unsigned char key, int x, int y);
void onMotionMouseClicked(int x, int y);
void onButtonMouseClicked(int button, int state, int x, int y);
void onPassiveMouseActived(int x, int y);
void onDrawScene();
void initialize();

void drawRoof(GLfloat length, GLfloat width, GLfloat height);
void drawSky(GLfloat length, GLfloat width, GLfloat height);
void drawWall(GLfloat length, GLfloat width, GLfloat height);
void drawFloor(GLfloat length, GLfloat width, GLfloat height);
void drawLand(GLfloat length, GLfloat width, GLfloat height);
void drawFront(GLfloat length, GLfloat width, GLfloat height);


#endif
