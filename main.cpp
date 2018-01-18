#include "glinterface.h"
#include "jsonparser.h"
#include "textureloader.h"
#include "listjsonobject.h"

#define VIEWING_DISTANCE_MIN  3.0

static double rotate_y=0; 
static double rotate_x=0;
static double rotate_z=0;
static GLfloat g_fViewDistance = 3 * VIEWING_DISTANCE_MIN;
static float g_lightPos[4] = { 10, 10, -100, 1 };
static int g_yClick = 0;
static BOOL g_bButton1Down = FALSE;

int yoy = 0;


void onDisplay();
void onReshape(int w, int h); 
void onSpecialKeysClicked(int key, int x, int y ); 
void onRenderObjects(); 
void onMotionMouse(int x, int y);
void onMouseClicked(int button, int state, int x, int y);
void onKeysClicked(unsigned char key, int x, int y);
void onDrawScene();

int main(int argc, char** argv) {
//	for(int i = 0; i < 5; i++){
//		printf("%d ", i%2);
//	}
	glIntInit(argc, argv);
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
	gluLookAt(4.0, 4.0, 4.0, 0, 0, -1, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);
	onRenderObjects();
	glMatrixMode(GL_MODELVIEW);
  	glPushMatrix();
	  	glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	  	glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	  	glRotatef(rotate_z, 0.0, 0.0, 1.0 );
	  	glIntDrawCartesius(0.0, 0.0, 0.0, 100.0);
	  	glIntDrawPrism(insCoord(0.0, 0.0, 0.0), 1.0, 4, 2.0);
//		onDrawScene();
	glPopMatrix();
   	glutSwapBuffers();
}

void onDrawScene(){
	/* Depan */
	glIntDrawPrism4(-5.0, 0.0, 0.0, 10.0, 1.0, 1.0, insColor(1.0, 0.0, 0.0));
	glIntDrawPrism4(-6.0, 0.0, 1.0, 12.0, 8.0, 1.0, insColor(1.0, 0.0, 0.0));
	for(int i = 0; i < 2; i++){
		glIntDrawPrism4(-6.0 + (i * 11.5), -5.0, 1.0, 0.5, 0.25, 5.0, insColor(0.0, 1.0, 1.0));
		glIntDrawPrism4(-6.0 + (i * 11.5), -5.0, 8.0, 0.5, 0.25, 5.0, insColor(0.0, 1.0, 1.0));
		glIntDrawPrism4(-5.0 + (i * 9.5), -5.0, 2.0, 0.5, 0.25, 5.0, insColor(0.0, 1.0, 1.0));
		glIntDrawPrism4(-5.0 + (i * 9.5), -5.0, 8.0, 0.5, 0.25, 5.0, insColor(0.0, 1.0, 1.0));
	}
	
	/*tiang dinding*/
//	for(int i = 0; i < 8; i++){
//		glIntDrawPrism4(-6.0 + (i * 11.5), -5.0, 1.0, 0.5, 0.25, 5.0, insColor(0.0, 1.0, 1.0));
//		glIntDrawPrism4(-6.0 + (i * 11.5), -5.0, 8.0, 0.5, 0.25, 5.0, insColor(0.0, 1.0, 1.0));
//	}
//	for(int j = 0; j < 2; j++){
//	}
	
	/*Lantai*/
	glIntDrawPrism4(-25.0, -3.0, 9.0, 50.0, 70.0, 0.5, insColor(1.0, 2.0, 1.0));
	glIntDrawPrism4(-25.0, -5.0, 9.0, 50.0, 70.0, 2.0, insColor(0.0, 0.0, 1.0));
}

void onReshape(int w, int h){
	printf("Modul Reshape, w=%d, h=%d\n", w, h);
	glViewport(0.0, 0.0, w, h);
	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluPerspective(100.0, (float) w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void onRenderObjects(){
	
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
	  printf("%d %d g_yClick %f", x, y, g_yClick);
}

void onMotionMouse(int x, int y){
	if (g_bButton1Down)
    {
      g_fViewDistance = (y - g_yClick) / 3.0;
      if (g_fViewDistance < VIEWING_DISTANCE_MIN)
         g_fViewDistance = VIEWING_DISTANCE_MIN;
      glutPostRedisplay();
    }
    printf("%d %d g_bButton1Down %d g_fViewDistance %f", x, y, g_bButton1Down, g_fViewDistance);
}


void onKeysClicked(unsigned char key, int x, int y){
	
}
