#ifndef  __BACKUP_H__
#define  __BACKUP_H__

#include <math.h>
#include "cJSON.h"
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <SOIL.h>
#include <stdbool.h>

void readFile();
void drawBox(GLfloat width, GLfloat height, GLfloat depth, GLuint textFront, GLuint textBack, GLuint textRight, GLuint textLeft, GLuint textTop, GLuint textBottom, GLfloat textKoor);
void bangunanInti(GLfloat width, GLfloat height, GLfloat depth, GLuint textFront, GLuint textBack, GLuint textRight, GLuint textLeft, GLuint textTop, GLuint textBottom, GLfloat textKoor);
void atasAtap();
void bawahAtap();
void atap();
void gapura();
void tangga ();
bool init();
void display();
void resize(int w, int h);
void idle();
static void 
key(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
int start(int argc, char *argv[]);

#endif
