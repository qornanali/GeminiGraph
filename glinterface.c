#include "glinterface.h"


void glIntDrawCartesius(Coord coord, GLfloat radius){
	printf("Draw Cartesius 3D on (%f, %f, %f)\n", coord.x, coord.y, coord.z);
	glPushMatrix();
	
		glBegin(GL_LINES);
			glColor3f(coord.x + radius, coord.y, coord.z);    
		  	glVertex3f(coord.x + radius, coord.y, coord.z);    
		  	glVertex3f(coord.x - radius, coord.y, coord.z);    
		glEnd();
		
		glBegin(GL_LINES);
			glColor3f(coord.x, coord.y + radius, coord.z);   
		  	glVertex3f(coord.x, coord.y + radius, coord.z);      
		  	glVertex3f(coord.x, coord.y - radius, coord.z);    
		glEnd();
		
		glBegin(GL_LINES);
			glColor3f(coord.x, coord.y, coord.z + radius);     
		  	glVertex3f(coord.x, coord.y, coord.z + radius);    
		  	glVertex3f(coord.x, coord.y, coord.z - radius);    
		glEnd();
	
	glPopMatrix();
}

void glIntBegin(int argcp, char ** argv){
	printf("========Glut Interface Begin========\n");
	glutInit(&argcp, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  	glutCreateWindow("Pendopo Tony Agung");
  	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 0, 0, 0, 0, 0);
}


void glIntEnd(){
	printf("========Glut Interface End========\n");
	glutMainLoop();
}

void glIntDrawPrism3(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color){
	printf("Draw Prism 3 with first vertex is (%f, %f, %f) with l %f w %f h %f\n", coord.x, coord.y, coord.z, length, width, height);
	glPushMatrix();
	
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x, coord.y, coord.z); 
			glVertex3f(coord.x + length, coord.y, coord.z); 
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z + width);
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z); 
			glVertex3f(coord.x, coord.y, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z + width);
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z); 
			glVertex3f(coord.x + length, coord.y, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glVertex3f(coord.x + length, coord.y, coord.z); 
			glVertex3f(coord.x, coord.y, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z + width); 
		glEnd();
	
	glPushMatrix();
}

void glIntDrawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color){
	printf("Draw Prism 4 with first vertex is (%f, %f, %f) with l %f w %f h %f\n", coord.x, coord.y, coord.z, length, width, height);
	glPushMatrix();
	
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
		  	glVertex3f(coord.x, coord.y, coord.z);     
			glVertex3f(coord.x + length, coord.y, coord.z);        
			glVertex3f(coord.x +length, coord.y + height, coord.z);       
			glVertex3f(coord.x, coord.y + height, coord.z);       
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x, coord.y, coord.z);
			glVertex3f(coord.x, coord.y, coord.z + width);
			glVertex3f(coord.x, coord.y + height, coord.z + width); 
			glVertex3f(coord.x, coord.y + height, coord.z);
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);  
			glVertex3f(coord.x + length, coord.y, coord.z);
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width);
		  	glVertex3f(coord.x + length, coord.y, coord.z + width);
	  	glEnd();
	  	
	  	glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
		  	glVertex3f(coord.x, coord.y, coord.z);
		  	glVertex3f(coord.x + length, coord.y, coord.z);
		  	glVertex3f(coord.x + length, coord.y, coord.z + width);
		  	glVertex3f(coord.x, coord.y, coord.z + width);
	  	glEnd();
		  
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
		  	glVertex3f(coord.x, coord.y + height, coord.z);
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width);
		  	glVertex3f(coord.x, coord.y + height, coord.z + width);
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
	  		glVertex3f(coord.x, coord.y, coord.z + width);
	  		glVertex3f(coord.x, coord.y + height, coord.z + width);
	  		glVertex3f(coord.x + length, coord.y + height, coord.z + width);
	  		glVertex3f(coord.x + length, coord.y, coord.z + width);
	 	glEnd();
 	
	glPopMatrix();
}
