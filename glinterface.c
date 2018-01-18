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
	glBegin(GL_LINES);
	  glColor3f(x, y, z + s);     
	  glVertex3f(x, y, z + s);    
	  glVertex3f(x, y, z - s);    
	glEnd();
}

void glIntInit(int argcp, char ** argv){
	printf("Modul Init\n");
	glutInit(&argcp,argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
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


void glIntDrawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat s, Color color){
	glIntDrawPrism4(x, y, z, s, s, s, color);
}

void glIntDrawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat s){
	Color color = insColor(1.0, 1.0, 0.0);
	glIntDrawPrism4(x, y, z, s, s, s, color);
}

void glIntDrawPrism3(GLfloat x, GLfloat y, GLfloat z, GLfloat a, GLfloat t, GLfloat T, Color color){
	glPushMatrix();
	printf("Draw Prism 3 (%.3f, %.3f, %.3f) %.3f %.3f %.3f\n", x, y, z, a, t, T);
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x, y, z); 
		glVertex3f(x+a, y, z); 
		glVertex3f(x+(a/2), y+t, z); 
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x, y, z+T); 
		glVertex3f(x+(a/2), y+t, z+T);
		glVertex3f(x+(a/2), y+t, z); 
		glVertex3f(x, y, z); 
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x+a, y, z+T); 
		glVertex3f(x+(a/2), y+t, z+T);
		glVertex3f(x+(a/2), y+t, z); 
		glVertex3f(x+a, y, z); 
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x, y, z+T); 
		glVertex3f(x+a, y, z+T); 
		glVertex3f(x+a, y, z); 
		glVertex3f(x, y, z); 
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x, y, z+T); 
		glVertex3f(x+a, y, z+T); 
		glVertex3f(x+(a/2), y+t, z+T); 
	glEnd();
	
	
	glPushMatrix();
}

void glIntDrawPrism3(GLfloat x, GLfloat y, GLfloat z, GLfloat a, GLfloat t, GLfloat T){
	Color color = insColor(1.0, 1.0, 0.0);
	glIntDrawPrism3(x, y, z, a, t, T, color);
}

void glIntDrawPrism(Coord coord, GLfloat radius, GLint nside, GLfloat height){
	printf("Draw Prism %d (%f, %f, %f) with radius %f and height %f\n", nside, coord.x, coord.y, coord.z, radius, height);
	int a = 0, i, j;
	GLfloat x1, y1, z1, angle;
	glPushMatrix();
//		for(int i = 0; i < 2; i++){
//			a++;
//			printf("draw #%d side\n", a);
//			glBegin(GL_POLYGON);
//				for(int j = 0; j < nside; j++){ 
//					angle = j * 360 / nside;
//					x1 = coord.x + radius * cos((M_PI/180) * angle);
//					y1 = coord.y + radius * sin((M_PI/180) * angle);
//					z1 = coord.z + (height * i);
//					printf("put vertext on (%f, %f, %f)\n", x1, y1, z1);
//					glVertex3f(x1, y1, z1);
//				}    
//			glEnd();
//		}
//		for(int i = 0; i < n; i++){
			a++;
			printf("draw #%d side\n", a);
			glBegin(GL_POLYGON);
				for(j = 0; j < 4; j++){
					angle = (60 * (j + ((j+1) % 2))) + (90 * (j + ((j) % 2)));
					x1 = coord.x + height * cos((M_PI/180) * angle);
					y1 = coord.y + height * sin((M_PI/180) * angle);
					z1 = coord.z + (height * 0);
					printf("put vertext on (%f, %f, %f) %d %d %d\n", x1, y1, z1, angle, (j + ((j+1) % 2)), (j + ((j) % 2)));
					glVertex3f(x1, y1, z1);
				}
			glEnd();
//		}
	glPopMatrix();
}

void glIntDrawPrism4(GLfloat x, GLfloat y, GLfloat z, GLfloat p, GLfloat l, GLfloat t, Color color){
	glPushMatrix();
	printf("Draw Prism 4 (%.3f, %.3f, %.3f) %.3f %.3f %.3f\n", x, y, z, p, l, t);
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b); 
	  	glVertex3f(x, y, z);     
		glVertex3f(x+p, y, z);        
		glVertex3f(x+p, y+t, z);       
		glVertex3f(x, y+t, z);       
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x, y, z);
		glVertex3f(x, y, z+l);
		glVertex3f(x, y+t, z+l); 
		glVertex3f(x, y+t, z);
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b);  
		glVertex3f(x+p, y, z);
	  	glVertex3f(x+p, y+t, z);
	  	glVertex3f(x+p, y+t, z+l);
	  	glVertex3f(x+p, y, z+l);
  	glEnd();
  	
  	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b); 
	  	glVertex3f(x, y, z);
	  	glVertex3f(x+p, y, z);
	  	glVertex3f(x+p, y, z+l);
	  	glVertex3f(x, y, z+l);
  	glEnd();
	  
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b); 
	  	glVertex3f(x, y+t, z);
	  	glVertex3f(x+p, y+t, z);
	  	glVertex3f(x+p, y+t, z+l);
	  	glVertex3f(x, y+t, z+l);
	glEnd();
	
	glBegin(GL_POLYGON);
  		glColor3f(color.r, color.g, color.b); 
  		glVertex3f(x, y, z+l);
  		glVertex3f(x, y+t, z+l);
  		glVertex3f(x+p, y+t, z+l);
  		glVertex3f(x+p, y, z+l);
 	glEnd();
 	
	glPopMatrix();
}

void glIntDrawPrism4(GLfloat x, GLfloat y, GLfloat z, GLfloat p, GLfloat l, GLfloat t){
	Color color = insColor(1.0, 1.0, 1.0);
	glIntDrawPrism4(x, y, z, p, l, t, color);
}

Coord insCoord(GLfloat x, GLfloat y, GLfloat z){
	Coord c;
	c.x = x;
	c.y = y;
	c.z = z;
	return c;
}
