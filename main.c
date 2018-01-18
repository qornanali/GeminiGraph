#include "pendopo.h"
#include <stdio.h>

#define VIEWING_DISTANCE_MIN  3.0

static double rotate_y=0; 
static double rotate_x=0;
static double rotate_z=0;
static GLfloat g_fViewDistance = 3 * VIEWING_DISTANCE_MIN;
static float g_lightPos[4] = { 10, 10, -100, 1 };
static int g_yClick = 0;
static BOOL g_bButton1Down = FALSE;

int yoy = 0;

GLuint brickTextureId;

void onDisplay();
void onReshape(int w, int h); 
void onSpecialKeysClicked(int key, int x, int y ); 
void onLoadTexture(); 
void onMotionMouse(int x, int y);
void onMouseClicked(int button, int state, int x, int y);
void onKeysClicked(unsigned char key, int x, int y);
void onDrawScene();

int main(int argc, char** argv) {
	glIntBegin(argc, argv);
		glutDisplayFunc(onDisplay);
		glutReshapeFunc(onReshape);
		glutMotionFunc (onMotionMouse);
		glutMouseFunc (onMouseClicked);
		glutSpecialFunc(onSpecialKeysClicked);
		glutKeyboardFunc (onKeysClicked);
	glIntEnd();
	return 0;
}


/*GL Interfaces*/
void onDisplay(){
	printf("Modul Display\n");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, -g_fViewDistance, 0.0, 0, 0, -1, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);
	onLoadTexture();
	glMatrixMode(GL_MODELVIEW);
  	glPushMatrix();
	  	glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	  	glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	  	glRotatef(rotate_z, 0.0, 0.0, 1.0 );
	  	glIntDrawCartesius(DEFAULT_COORD, 100.0);
		onDrawScene();
	glPopMatrix();
   	glutSwapBuffers();
}

void onDrawScene(){
	glIntDrawPrism3(DEFAULT_COORD, 2.0, 1.0, 3.0, DEFAULT_COLOR);
	glIntDrawPrism4(insCoord(3.0, 3.0, 3.0), 2.0, 1.0, 3.0, DEFAULT_COLOR, brickTextureId);
}

void onReshape(int w, int h){
	glViewport(0.0, 0.0, w, h);
	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluPerspective(100.0, (float) w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void onLoadTexture(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	Image* image = loadBMP("assets/brick.bmp");
	brickTextureId = glIntLoadTexture(image);
	delete image;
}

void onSpecialKeysClicked(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
	
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	else if (key == GLUT_KEY_PAGE_UP)
		rotate_z += 5;
	else if(key == GLUT_KEY_PAGE_DOWN)
		rotate_z-= 5;
	else if(key == GLUT_KEY_END)
		exit(0);
	
	glutPostRedisplay();
}

void onMouseClicked(int button, int state, int x, int y){
 
  if (button == GLUT_LEFT_BUTTON){
      g_bButton1Down = (state == GLUT_DOWN) ? TRUE : FALSE;
      g_yClick = y - 3 * g_fViewDistance;
	  }
}

void onMotionMouse(int x, int y){
	if (g_bButton1Down)
    {
      g_fViewDistance = (y - g_yClick) / 3.0;
      if (g_fViewDistance < VIEWING_DISTANCE_MIN)
         g_fViewDistance = VIEWING_DISTANCE_MIN;
      glutPostRedisplay();
    }
}


void onKeysClicked(unsigned char key, int x, int y){
	
}
