#include "glinterface.h"

double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;

void onDisplay();
void onReshape(int w, int h);
void onSpecialKeysClicked(int key, int x, int y );
void onRotate();

int main(int argc, char** argv) {
	glIntInit(argc, argv);
	glutDisplayFunc(onDisplay);
	glutReshapeFunc(onReshape);
	glutSpecialFunc(onSpecialKeysClicked);
	glIntEnd();
	return 0;
}

void onDisplay(){
	printf("Modul Display\n");
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glIntDrawCartesius(0.0, 0.0, 0.0, 1.0);
	onRotate();
	
	glLoadIdentity();
	glFlush();
}

void onReshape(int w, int h){
	printf("Modul Reshape, w=%d, h=%d\n", w, h);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glOrtho(5,5,5,5,100,50);
}

void onRotate(){
	glMatrixMode(GL_MODELVIEW);
  	glPushMatrix();
	  glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	  glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	  glRotatef(rotate_z, 0.0, 0.0, 1.0 );
	glIntDrawCartesius(0.0, 0.0, 0.0, 1.0);
	glIntDrawCube(0.0, 5.0, 7.0, 1.0);
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
