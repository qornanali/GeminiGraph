#include "glinterface.h"


void glIntDrawCartesius(GLfloat x, GLfloat y, GLfloat z, GLfloat s){
	printf("Draw Cartesius\n");
	glBegin(GL_LINES);
	  glColor3f(x + s, y, z);    
	  glVertex3f(x + s, y, z);    
	  glVertex3f(x - s, y, z);    
	glEnd();
	glBegin(GL_LINES);
	  glColor3f(x, y + s, z);   
	  glVertex3f(x, y + s, z);      
	  glVertex3f(x, y - s, z);    
	glEnd();
//	glBegin(GL_LINES);
//	  glColor3f(x, y, z + s);     
//	  glVertex3f(x, y, z + s);    
//	  glVertex3f(x, y, z - s);    
//	glEnd();
}

void glIntInit(int argcp, char ** argv){
	printf("Modul Init\n");
	glutInit(&argcp,argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH);
  	glutCreateWindow("Pendopo Tony");
  	
  	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
//     glEnable( GL_CULL_FACE );
//   glCullFace ( GL_BACK );
	glMatrixMode(GL_PROJECTION);
	glOrtho(5,5,5,5,5,5);
}

void glIntEnd(){
	printf("Modul End\n");
	glutMainLoop();
}


void glIntDrawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat s){
	glPushMatrix();
	s /= 2;
	printf("Draw Cube () %.3f\n", s);
	glBegin(GL_POLYGON);
  		glColor3f(1.0, 1.0, 0.0);  
  	  	glTexCoord2f(0.0f, 0.0f);  
	  	glVertex3f(x, y, z);   
	  	glTexCoord2f(1.0f, 0.0f);    
		glVertex3f(s, y, z);  
	  	glTexCoord2f(1.0f, 1.0f);      
		glVertex3f(s, s, z);     
	 	glTexCoord2f(0.0f, 1.0f);      
		glVertex3f(x, s, z);       
	glEnd();
	glPopMatrix();
}
