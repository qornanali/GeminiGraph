#include "glinterface.h"

#include <math.h>
#include <stdio.h>

void drawCartesius(Coord coord, GLfloat radius){
	printf("Draw Cartesius 3D on (%f, %f, %f)\n", coord.x, coord.y, coord.z);
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
}

void glIntBegin(int argcp, char ** argv){
	printf("========Glut Interface Begin========\n");
	glutInit(&argcp, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  	glutCreateWindow("Pendopo Tony Agung");
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}


void glIntEnd(){
	printf("========Glut Interface End========\n");
	glutMainLoop();
}


void glIntDrawPrismTrapezoid(Coord coord, GLfloat lengtha, GLfloat lengthb, GLfloat width, GLfloat height, Color color, const char* textureImageName, BOOL showTexture){
	printf("Draw Prism Trapezoid with first vertex is (%f, %f, %f) with la %f w %f h %f\n", coord.x, coord.y, coord.z, lengtha, lengthb, width, height);	
	if(showTexture){
		GLuint texture;
		Image * image = loadBMP(textureImageName);
		glIntLoadTexture(image, &texture);
		delete image;
	}
	glPushMatrix();
	
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + lengthb, coord.y, coord.z); 
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
			glTexCoord2f(0.0f, 1.0f);  
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x + lengthb, coord.y, coord.z); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z);
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
			glTexCoord2f(0.0f, 1.0f);  
			glVertex3f(coord.x + lengthb, coord.y, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z+ width);
			glTexCoord2f(1.0f, 1.0f);   
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z);
			glTexCoord2f(0.0f, 1.0f);  
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
			glTexCoord2f(1.0f, 1.0f);   
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
			glTexCoord2f(0.0f, 1.0f);  
			glVertex3f(coord.x, coord.y, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b);
			glTexCoord2f(0.0f, 0.0f); 
			glVertex3f(coord.x, coord.y, coord.z); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + lengthb, coord.y, coord.z); 
			glTexCoord2f(1.0f, 1.0f);   
			glVertex3f(coord.x + lengthb, coord.y, coord.z + width); 
			glTexCoord2f(0.0f, 1.0f);  
			glVertex3f(coord.x, coord.y, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  	glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f); 
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + lengthb, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 1.0f);   
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
			glTexCoord2f(0.0f, 1.0f);  
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
		glEnd();
		
	glPopMatrix();
}

void glIntDrawPrism3(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color, const char* textureImageName, BOOL showTexture){
	printf("Draw Prism 3 with first vertex is (%f, %f, %f) with l %f w %f h %f\n", coord.x, coord.y, coord.z, length, width, height);	
	if(showTexture){
		GLuint texture;
		Image * image = loadBMP(textureImageName);
		glIntLoadTexture(image, &texture);
		delete image;
	}
	glPushMatrix();
	
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + length, coord.y, coord.z); 
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON); 
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z + width);
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z); 
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(coord.x, coord.y, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON); 
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z + width);
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z); 
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(coord.x + length, coord.y, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + length, coord.y, coord.z); 
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(coord.x, coord.y, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON); 
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glTexCoord2f(1.0f, 1.0f);  
			glVertex3f(coord.x + (length / 2), coord.y + height, coord.z + width); 
		glEnd();
	
	glPushMatrix();
}


void glIntDrawCube(Coord coord, GLfloat radius, Color color, const char* textureImageName, BOOL showTexture){
	glIntDrawPrism4(coord, radius, radius, radius, color, textureImageName, showTexture);
}

void glIntDrawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, Color color, const char* textureImageName, BOOL showTexture){
	printf("Draw Prism 4 with first vertex is (%f, %f, %f) with l %f w %f h %f\n", coord.x, coord.y, coord.z, length, width, height);
	if(showTexture){
		GLuint texture;
		Image * image = loadBMP(textureImageName);
		glIntLoadTexture(image, &texture);
		printf("Texture Id %d---\n", texture);
		delete image;
	}
	glPushMatrix();
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
		  	glVertex3f(coord.x, coord.y, coord.z);   
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(coord.x + length, coord.y, coord.z);    
			glTexCoord2f(1.0f, 1.0f);   
			glVertex3f(coord.x + length, coord.y + height, coord.z); 
			glTexCoord2f(0.0f, 1.0f); 
			glVertex3f(coord.x, coord.y + height, coord.z);       
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x, coord.y, coord.z);
			glTexCoord2f(1.0f, 0.0f);  
			glVertex3f(coord.x, coord.y, coord.z + width);
			glTexCoord2f(1.0f, 1.0f);   
			glVertex3f(coord.x, coord.y + height, coord.z + width);     
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(coord.x, coord.y + height, coord.z);
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(coord.x + length, coord.y, coord.z);
			glTexCoord2f(1.0f, 0.0f);  
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);
			glTexCoord2f(1.0f, 1.0f);   
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width); 
			glTexCoord2f(0.0f, 1.0f);
		  	glVertex3f(coord.x + length, coord.y, coord.z + width);
	  	glEnd();
	  	
	  	glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
		  	glVertex3f(coord.x, coord.y, coord.z);
			glTexCoord2f(1.0f, 0.0f);  
		  	glVertex3f(coord.x + length, coord.y, coord.z);
			glTexCoord2f(1.0f, 1.0f);   
		  	glVertex3f(coord.x + length, coord.y, coord.z + width); 
			glTexCoord2f(0.0f, 1.0f);
		  	glVertex3f(coord.x, coord.y, coord.z + width);
	  	glEnd();
		  
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
		  	glVertex3f(coord.x, coord.y + height, coord.z);
			glTexCoord2f(1.0f, 0.0f);  
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);
			glTexCoord2f(1.0f, 1.0f);
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width);
			glTexCoord2f(0.0f, 1.0f);
		  	glVertex3f(coord.x, coord.y + height, coord.z + width);
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color.r, color.g, color.b); 
			glTexCoord2f(0.0f, 0.0f);
	  		glVertex3f(coord.x, coord.y, coord.z + width);
			glTexCoord2f(1.0f, 0.0f);
	  		glVertex3f(coord.x, coord.y + height, coord.z + width);
			glTexCoord2f(1.0f, 1.0f);  
	  		glVertex3f(coord.x + length, coord.y + height, coord.z + width);   
			glTexCoord2f(0.0f, 1.0f);
	  		glVertex3f(coord.x + length, coord.y, coord.z + width);
	 	glEnd();
 	
	glPopMatrix();
}


void glIntLoadTexture(Image* image, GLuint * textureId) {
	glGenTextures(1, textureId);
	glBindTexture(GL_TEXTURE_2D, *textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glGenerateMipmap(GL_TEXTURE_2D);
}
