#include "pendopo.h"
#include "scene.h"

#include <stdio.h>

#define VIEWING_DISTANCE_MIN  3.0

static double rotate_y=0; 
static double rotate_x=0;
static double rotate_z=0;
static GLfloat g_fViewDistance = 3 * VIEWING_DISTANCE_MIN;
//static float g_lightPos[4] = { 10, 10, -100, 1 };
static int g_yClick = 0;
static BOOL g_bButton1Down = FALSE;

int yoy = 0;

GLuint brickTextureId;

void pendopoStart(int argcp, char ** argv){
	printf("-----Pendopo Start-----\n");
	glIntBegin(argcp, argv);
		
		glutDisplayFunc(onWorldDisplay);
		glutReshapeFunc(onWorldReshape);
		glutMotionFunc (onMotionMouseClicked);
		glutMouseFunc(onButtonMouseClicked);
		glutSpecialFunc(onSpecialKeyClicked);
		glutKeyboardFunc(onNormalKeyClicked);
		glutPassiveMotionFunc(onPassiveMouseActived);
		glutIdleFunc(onWorldIdle);
		
	
	glIntEnd();
}

void onWorldDisplay(){
	printf("-----On World Display-----\n");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, -g_fViewDistance, 0.0, 0, 0, -1, 0, 1, 0);
//	glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);
	onLoadTexture();
	glMatrixMode(GL_MODELVIEW);
	onDrawScene();
   	glutSwapBuffers();
}

void onDrawScene(){
	printf("-----On Draw Scene-----\n");
	glPushMatrix();
	  	glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	  	glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	  	glRotatef(rotate_z, 0.0, 0.0, 1.0 );
	  	glIntDrawCartesius(DEFAULT_COORD, 100.0);
		glIntDrawPrism3(DEFAULT_COORD, 2.0, 1.0, 3.0, DEFAULT_COLOR);
		glIntDrawPrism4(insCoord(3.0, 3.0, 3.0), 2.0, 1.0, 3.0, DEFAULT_COLOR, brickTextureId);
	glPopMatrix();
//	drawScene(GLfloat length, GLfloat width, GLfloat height);
//	drawRoof(GLfloat length, GLfloat width, GLfloat height);
//	drawSky(GLfloat length, GLfloat width, GLfloat height);
//	drawWall(GLfloat length, GLfloat width, GLfloat height);
//	drawFloor(GLfloat length, GLfloat width, GLfloat height);
//	drawLand(GLfloat length, GLfloat width, GLfloat height);
//	drawFront(GLfloat length, GLfloat width, GLfloat height);
}

void onWorldIdle(){
//	printf("-----On World Idle-----\n");
}

void onWorldReshape(int w, int h){
	printf("-----On World Reshape-----\nw = %d, h = %d\n", w, h);
	glViewport(0.0, 0.0, w, h);
	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluPerspective(100.0, (float) w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void onLoadTexture(){
	printf("-----On Load Texture-----\n");
	Image* image = loadBMP("assets/brick.bmp");
	glIntLoadTexture(image, &brickTextureId);
	delete image;
}

void onSpecialKeyClicked(int key, int x, int y ){
//	printf("-----On Special Key Clicked-----\n%d %d %d", key, x, y);
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

void onNormalKeyClicked(unsigned char key, int x, int y){
//	printf("-----On Normal Key Clicked-----\n%c %d %d", key, x, y);
}

void onMotionMouseClicked(int x, int y){
//	printf("-----On Motion Mouse Clicked-----\n%d %d", x, y);
	if (g_bButton1Down){
		g_fViewDistance = (y - g_yClick) / 3.0;
		if (g_fViewDistance < VIEWING_DISTANCE_MIN){
			g_fViewDistance = VIEWING_DISTANCE_MIN;
		}
		glutPostRedisplay();
    }
}

void onButtonMouseClicked(int button, int state, int x, int y){
//	printf("-----On Button Mouse Clicked-----\n%d %d %d %d", button, state, x, y);
	if(button == GLUT_LEFT_BUTTON){
		g_bButton1Down = (state == GLUT_DOWN) ? TRUE : FALSE;
		g_yClick = y - 3 * g_fViewDistance;
	}
}

void onPassiveMouseActived(int x, int y){
//	printf("-----On Passive Mouse Actived-----\n%d %d", x, y);
}

