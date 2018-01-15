#include "glinterface.h"
#include "jsonparser.h"
#include "textureloader.h"
#include "listjsonobject.h"


#define VIEWING_DISTANCE_MIN  3.0

typedef int BOOL;
#define TRUE 1
#define FALSE 0

double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;

static GLfloat g_fViewDistance = 3 * VIEWING_DISTANCE_MIN;
static float g_lightPos[4] = { 10, 10, -100, 1 };
static int g_yClick = 0;
static BOOL g_bButton1Down = FALSE;

int yoy = 0;

GLuint textureId[6];

void onDisplay(); //ketika gl display
void onReshape(int w, int h); //ketika gl reshape
void onSpecialKeysClicked(int key, int x, int y ); //ketika ada special key clicked
void onRenderObjects(); //ketika special key trigger rotasi
void onMotionMouse(int x, int y);
void onMouseClicked(int button, int state, int x, int y);
void onKeysClicked(unsigned char key, int x, int y);

int main(int argc, char** argv) {
//	char c;
//	scanf("%c", &c);
//	printf("%d", c);
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
	gluLookAt(0, 0, -g_fViewDistance, 0, 0, -1, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);
	onRenderObjects();
   	glutSwapBuffers();
}

void onReshape(int w, int h){
	printf("Modul Reshape, w=%d, h=%d\n", w, h);
	glViewport(0.0, 0.0, w, h);
	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluPerspective(45.0, (float) w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void onRenderObjects(){
	glMatrixMode(GL_MODELVIEW);
  	glPushMatrix();
	  	glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	  	glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	  	glRotatef(rotate_z, 0.0, 0.0, 1.0 );
		glIntDrawCartesius(0.0, 0.0, 0.0, 1.0);
		glIntDrawCube(0.0, 0.0, 0.0, 1.0);
		glIntDrawCube(0.0, 0.0, 0.0, 1.0);
	glPopMatrix();
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
