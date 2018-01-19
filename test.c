
#include <GL/freeglut_std.h>


typedef struct Coord{
	float x;
	float y;
	float z;
} Coord;

Coord insCoord(float x, float y, float z){
	Coord c;
	c.x = x;
	c.y = y;
	c.z = z;
	return c;
}

void display();
void respahe();

int main(int argc, char** argv){
	glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  	glutCreateWindow("Pendopo Tony Agung");
  	
		glutDisplayFunc(display);
		glutReshapeFunc(respahe);
	
	glutMainLoop();
	return 0;
}

void respahe(int w, int h){
	glViewport(0.0, 0.0, w, h);
}


void display(){
	
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Coord coord = insCoord(0.0, 0.0, 0.0);
	GLfloat radius = 100;
	
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		//x
		glBegin(GL_LINES);
			glColor3f(coord.x + radius, coord.y, coord.z);    
		  	glVertex3f(coord.x + radius, coord.y, coord.z);    
		  	glVertex3f(coord.x - radius, coord.y, coord.z);    
		glEnd();
		
		//y
		glBegin(GL_LINES);
			glColor3f(coord.x, coord.y + radius, coord.z);   
		  	glVertex3f(coord.x, coord.y + radius, coord.z);      
		  	glVertex3f(coord.x, coord.y - radius, coord.z);    
		glEnd();
		
		//z
		glBegin(GL_LINES);
			glColor3f(coord.x, coord.y, coord.z + radius);     
		  	glVertex3f(coord.x, coord.y, coord.z + radius);    
		  	glVertex3f(coord.x, coord.y, coord.z - radius);    
		glEnd();
	
	glPopMatrix();
   	glutSwapBuffers();
} 
