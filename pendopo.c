#include "pendopo.h"

#include <stdio.h>
#include <math.h>

//#define VIEWING_DISTANCE_MIN  3.0
#define GROUND_HEIGHT 0.0


static GLfloat rotatex, rotatey, rotatez, translatex, translatey, translatez, angle;

//static double rotate_y=0; 
//static double rotate_x=0;
//static double rotate_z=0;
//static GLfloat g_fViewDistance = 3 * VIEWING_DISTANCE_MIN;
//static float g_lightPos[4] = { 10, 10, -100, 1 };
//static int g_yClick = 0;
//static BOOL g_bButton1Down = FALSE;

//int yoy = 0;

void initialize(){
//	camera = insCoord(0.0, 0.0, 10);
//	cameraFocus = insCoord(0.0, 0.0, -10);	
//	angleUpBot = 0;
//	angleLefRig = 0;
	
	rotatex = 0.0;
	rotatey = 0.0;
	rotatez = 0.0;
	translatex = 0.0;
	translatey = 0.0;
	translatez = 0.0;
}


void pendopoStart(int argcp, char ** argv){
	printf("-----Pendopo Start-----\n");
	initialize();
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
//	gluLookAt(camera.x, camera.y, camera.z, cameraFocus.x, cameraFocus.y, cameraFocus.z, 0, 1, 0);
	gluLookAt(0.0, 50.0, 10.0, 0, 10.0, -5, 0, 1, 0);
//	glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);
	glMatrixMode(GL_MODELVIEW);
	onDrawScene();
   	glutSwapBuffers();
}

void onDrawScene(){
	printf("-----On Draw Scene-----\n");
	glPushMatrix();
	  	glRotatef(rotatex, 1.0, 0.0, 0.0 );
	  	glRotatef(rotatey, 0.0, 1.0, 0.0 );
	  	glRotatef(rotatez, 0.0, 0.0, 1.0 );
	  	glIntDrawCartesius(DEFAULT_COORD, 100.0);
	//	drawScene(GLfloat length, GLfloat width, GLfloat height);
	//	drawRoof(GLfloat length, GLfloat width, GLfloat height);
//		drawSky(300.0, 300.0, 300.0);
//		drawWall(55.0, 55.0, 55.0);
//		drawFloor(60.0, 80.0, 8.0);
//		drawLand(100.0, 100.0, 2.0);
//		drawFront(20.0, 20.0, 10.0);
		glIntDrawCube(DEFAULT_COORD, 3.0, DEFAULT_COLOR, "assets/brick.bmp", TRUE);
	glPopMatrix();
}

void onWorldIdle(){
//	printf("-----On World Idle-----\n");
}

void onWorldReshape(int w, int h){
	printf("-----On World Reshape-----\nw = %d, h = %d\n", w, h);
	glViewport(0.0, 0.0, w, h);
	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluPerspective(65.0, (float) w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void onSpecialKeyClicked(int key, int x, int y ){
	printf("-----On Special Key Clicked-----\n%d %d %d", key, x, y);
	if (key == GLUT_KEY_RIGHT)
		rotatey += 5;
	else if (key == GLUT_KEY_LEFT)
		rotatey -= 5;
	else if (key == GLUT_KEY_UP)
		rotatex += 5;
	else if (key == GLUT_KEY_DOWN)
		rotatex -= 5;
	else if(key == GLUT_KEY_END)
		exit(0);
	
	glutPostRedisplay();
}

void onNormalKeyClicked(unsigned char key, int x, int y){
	printf("-----On Normal Key Clicked-----\n%c %d %d", key, x, y);
	switch(key){
		case 'w' :
			break;
		case 's' :
			break;
		case 'a' :
			break;
		case 'd' :
			break;
	}
}

void onMotionMouseClicked(int x, int y){
	printf("-----On Motion Mouse Clicked-----\n%d %d", x, y);
//	if (g_bButton1Down){
//		g_fViewDistance = (y - g_yClick) / 3.0;
//		if (g_fViewDistance < VIEWING_DISTANCE_MIN){
//			g_fViewDistance = VIEWING_DISTANCE_MIN;
//		}
//		glutPostRedisplay();
//    }
}

void onButtonMouseClicked(int button, int state, int x, int y){
	printf("-----On Button Mouse Clicked-----\n%d %d %d %d", button, state, x, y);
//	if(button == GLUT_LEFT_BUTTON){
//		g_bButton1Down = (state == GLUT_DOWN) ? TRUE : FALSE;
//		g_yClick = y - 3 * g_fViewDistance;
//	}
}

void onPassiveMouseActived(int x, int y){
//	printf("-----On Passive Mouse Actived-----\n%d %d", x, y);
}

void drawRoof(GLfloat length, GLfloat width, GLfloat height){
	printf("/////draw roof/////\nw = %f, l = %f, h = %f\n", width, length, height);
	glIntDrawPrismTrapezoid(DEFAULT_COORD, 1.0, 3.0, 2.0, 0.5, DEFAULT_COLOR, "assets/brick.bmp", 0);
	glIntDrawPrismTrapezoid(insCoord(-1.0, -0.5, -1.0), 3.0, 5.0, 4.0, 0.5, DEFAULT_COLOR, "assets/brick.bmp", 0);
}

void drawSky(GLfloat length, GLfloat width, GLfloat height){
	printf("/////draw sky/////\nw = %f, l = %f, h = %f\n", width, length, height);
	glPushMatrix();
		glTranslatef(-150.0, 0.0, -150.0);
		glIntDrawPrism4(DEFAULT_COORD, 300.0, 300.0, 153.0, BLUE, "assets/brick.bmp", 0);
	glPopMatrix();
}

void drawWall(GLfloat length, GLfloat width, GLfloat height){
	printf("/////draw wall/////\nw = %f, l = %f, h = %f\n", width, length, height);
	int i, j;
	for(i = 0; i < 2; i++){	
		for(int j = 0; j < 3; j++){
			glPushMatrix();
				glTranslatef(-25.0 + (i * 50), 6.0, -27.0 - (j * 12));
				glIntDrawPrism4(DEFAULT_COORD,  1.0, 2.5, 12.0, WHITE, "assets/brick.bmp", 1);
			glPopMatrix();
		}
	}
	for(i = 0; i < 2; i++){	
		for(int j = 0; j < 3; j++){
			glPushMatrix();
				glTranslatef(-25.0 + (i * 50), 6.0, -71.0 - (j * 12));
				glIntDrawPrism4(DEFAULT_COORD,  1.0, 2.5, 12.0, WHITE, "assets/brick.bmp", 1);
			glPopMatrix();
		}
	}
}

void drawFloor(GLfloat length, GLfloat width, GLfloat height){
	printf("/////draw floor/////\nw = %f, l = %f, h = %f\n", width, length, height);
	int i, j;
	glPushMatrix();
		glTranslatef(-10.0, 2.0, -18.0);
		glIntDrawPrism4(DEFAULT_COORD, 20.0, 1.0, 4.0, PURPLE, "assets/brick.bmp", 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10.0, 2.0, -95.0);
		glIntDrawPrism4(DEFAULT_COORD, 20.0, 77.0, 4.0, RED, "assets/brick.bmp", 1);
	glPopMatrix();
	for(i = 0; i < 2; i++){
		glPushMatrix();
			glTranslatef(-30.0 + (i * 40), 2.0, -95.0);
			glIntDrawPrism4(DEFAULT_COORD, 23.0, 84.0, 4.0, BLUE, "assets/brick.bmp", 1);
		glPopMatrix();
	}
}

void drawLand(GLfloat length, GLfloat width, GLfloat height){
	printf("/////draw land/////\nw = %f, l = %f, h = %f\n", width, length, height);
	glPushMatrix();
		glTranslatef(-150.0, -2.0, -150);
		glIntDrawPrism4(DEFAULT_COORD, 300.0, 300.0, 2.0, WHITE, "assets/brick.bmp", 1);
	glPopMatrix();
}

void drawFront(GLfloat length, GLfloat width, GLfloat height){
	printf("/////draw front/////\nw = %f, l = %f, h = %f\n", width, length, height);
	int i, j;
	glPushMatrix();
		glTranslatef(-10.0, 10.0, 5.0);
		glIntDrawPrism4(DEFAULT_COORD, 20.0, 3.0, 2.0, WHITE, "assets/brick.bmp", 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-11.0, 10.0, -11.0);
		glIntDrawPrism4(DEFAULT_COORD, 22.0, 16.0, 2.0, WHITE, "assets/brick.bmp", 1);
	glPopMatrix();
	for(i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			glPushMatrix();	
				glTranslatef(11.0 - (j * 23.0), 0.0, 0.0 - (i * 10.0));
				glIntDrawPrism4(DEFAULT_COORD, 1.0, 2.5, 12.0, WHITE, "assets/brick.bmp", 1);
			glPopMatrix();
			glPushMatrix();		
				glTranslatef(8.0 - (j * 17.0), 0.0, 0.0 - (i * 10.0));
				glIntDrawPrism4(DEFAULT_COORD, 1.0, 2.5, 11.0, WHITE, "assets/brick.bmp", 1);
			glPopMatrix();
		}
	}
}

