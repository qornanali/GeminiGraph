/*
Nama file : interface.c
Dibuat oleh : Ali Qornan Jaisyurrahman
Tanggal : 22 januari 2018 18:42 WIB
Fungsi : ADT yang berfungsi untuk mengimplementasikan fungsi yang ada di library freeglut untuk
membuat suatu bangun yang diinginkan.
Lisensi : https://github.com/qornanali/PendopoTonyAgung-OpenGL-C/blob/master/LICENSE
*/ 

#include "interface.h"

#include <math.h>
#include <stdio.h>

/* Method prosedur untuk menampilkan bangun ruang kubus */
void drawCube(Coord coord, GLfloat radius, Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat){
	drawPrism4(coord, radius, radius, radius, color, textureId, bindings, repeat);
}

/* Method prosedur untuk menampilkan bangun ruang prisma dengan alas segi empat */
void drawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, 
				Color color[],  GLuint textureId, BOOL bindings[], GLfloat repeat){
	if(textureId != 0){
		glBindTexture(GL_TEXTURE_2D, textureId);
	}
	glPushMatrix();
		glBegin(GL_POLYGON);
	  		glColor3f(color[0].r, color[0].g, color[0].b); 
			if(bindings[0]){
				glTexCoord2f(repeat, repeat);
			  }  
		  	glVertex3f(coord.x, coord.y, coord.z);   
	  		if(bindings[0]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x + length, coord.y, coord.z);  
			if(bindings[0]){
				glTexCoord2f(repeat, 0.0f);
			}
			glVertex3f(coord.x + length, coord.y + height, coord.z); 
			if(bindings[0]){
				glTexCoord2f(0.0f, 0.0f);
			  }  
			glVertex3f(coord.x, coord.y + height, coord.z);       
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[1].r, color[1].g, color[1].b); 
	  		if(bindings[1]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x, coord.y, coord.z);
			if(bindings[1]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x, coord.y, coord.z + width);  
			if(bindings[1]){
				glTexCoord2f(repeat, 0.0f);
			  }  
			glVertex3f(coord.x, coord.y + height, coord.z + width);     
			if(bindings[1]){
				glTexCoord2f(0.0f, 0.0f);
			}
			glVertex3f(coord.x, coord.y + height, coord.z);
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[2].r, color[2].g, color[2].b); 
	  		if(bindings[2]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x + length, coord.y, coord.z);
			if(bindings[2]){
				glTexCoord2f(0.0f, repeat);
			}
		  	glVertex3f(coord.x + length, coord.y, coord.z + width);
			if(bindings[2]){
				glTexCoord2f(repeat, 0.0f);
			  }
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width); 
			if(bindings[2]){
				glTexCoord2f(0.0f, 0.0f);
			  }  
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);    
		
	  	glEnd();
	  	
	  	glBegin(GL_POLYGON);
	  		glColor3f(color[3].r, color[3].g, color[3].b); 
	  		if(bindings[3]){
				glTexCoord2f(repeat, repeat);
			  }
		  	glVertex3f(coord.x, coord.y, coord.z);
			if(bindings[3]){
				glTexCoord2f(repeat, 0.0f);
			  }  
		  	glVertex3f(coord.x + length, coord.y, coord.z);
			if(bindings[3]){
				glTexCoord2f(0.0f, repeat);
			  }
		  	glVertex3f(coord.x + length, coord.y, coord.z + width); 
			if(bindings[3]){
				glTexCoord2f(0.0f, 0.0f);
			}
		  	glVertex3f(coord.x, coord.y, coord.z + width);
	  	glEnd();
		  
		glBegin(GL_POLYGON);
	  		glColor3f(color[4].r, color[4].g, color[4].b); 
	  		if(bindings[4]){
				glTexCoord2f(repeat, repeat);
			  }
		  	glVertex3f(coord.x, coord.y + height, coord.z);
			  if(bindings[4]){
				glTexCoord2f(repeat, 0.0f);
			  }  
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);
			if(bindings[4]){
				glTexCoord2f(0.0f, repeat);
			  }
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width);
			if(bindings[4]){
				glTexCoord2f(0.0f, 0.0f);
			}
		  	glVertex3f(coord.x, coord.y + height, coord.z + width);
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[5].r, color[5].g, color[5].b); 
	  		if(bindings[5]){
				glTexCoord2f(repeat, repeat);
			  }
	  		glVertex3f(coord.x, coord.y, coord.z + width);
			if(bindings[5]){
				glTexCoord2f(0.0f, repeat);
			  }
	  		glVertex3f(coord.x + length, coord.y, coord.z + width);
			  if(bindings[5]){
				glTexCoord2f(repeat, 0.0f);
			  }  
	  		glVertex3f(coord.x + length, coord.y + height, coord.z + width);   
			if(bindings[5]){
				glTexCoord2f(0.0f, 0.0f);
			}
	  		glVertex3f(coord.x, coord.y + height, coord.z + width);
	 	glEnd();
 	
	glPopMatrix();
}

/* Method prosedur untuk menampilkan bangun ruang prisma dengan alas trapezium */
void drawPrismTrapezoid(Coord coord, GLfloat lengtha, GLfloat lengthb, GLfloat width, GLfloat height, 
						Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat){
	if(textureId != 0){
		glBindTexture(GL_TEXTURE_2D, textureId);
	}
	glPushMatrix();
	
		glBegin(GL_POLYGON);
	  		glColor3f(color[0].r, color[0].g, color[0].b); 
	  		if(bindings[0]){
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z); 
	  		if(bindings[0]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x + lengthb, coord.y, coord.z); 
	  		if(bindings[0]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
	  		if(bindings[0]){
				glTexCoord2f(0.0f, 0.0f);
			  }
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[1].r, color[1].g, color[1].b); 
	  		if(bindings[1]){
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x + lengthb, coord.y, coord.z); 
	  		if(bindings[1]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z);
	  		if(bindings[1]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
	  		if(bindings[1]){
				glTexCoord2f(0.0f, 0.0f);
			  }
			glVertex3f(coord.x + lengthb, coord.y, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[2].r, color[2].g, color[2].b); 
	  		if(bindings[2]){
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
	  		if(bindings[2]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z+ width);
	  		if(bindings[2]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z);
	  		if(bindings[2]){
				glTexCoord2f(0.0f, 0.0f);
			  }
			glVertex3f(coord.x + lengtha + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[3].r, color[3].g, color[3].b); 
	  		if(bindings[3]){
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z); 
	  		if(bindings[3]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z); 
	  		if(bindings[3]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x + ((lengthb - lengtha)/2), coord.y + height, coord.z + width); 
	  		if(bindings[3]){
				glTexCoord2f(0.0f, 0.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[4].r, color[4].g, color[4].b); 
	  		if(bindings[4]){
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z); 
	  		if(bindings[4]){
				glTexCoord2f(repeat, repeat);
			  }
			glVertex3f(coord.x + lengthb, coord.y, coord.z); 
	  		if(bindings[4]){
				glTexCoord2f(0.0f, repeat);
			  }
			glVertex3f(coord.x + lengthb, coord.y, coord.z + width); 
	  		if(bindings[4]){
				glTexCoord2f(0.0f, 0.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z + width); 
		glEnd();
		
		glBegin(GL_POLYGON);
	  		glColor3f(color[5].r, color[5].g, color[5].b); 
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

/* Method prosedur untuk menampilkan garis kartesius 3D */
void drawCartesius(Coord coord, GLfloat radius){
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

/* Method prosedur untuk menampilkan bangun ruang balok */
void drawBox(GLfloat width, GLfloat height, GLfloat depth, GLuint textFront, GLuint textBack, GLuint textRight, GLuint textLeft, GLuint textTop, GLuint textBottom, GLfloat textKoor)
{
	width = width*0.5;
	depth = depth*0.5;
	height = height*0.5;
	GLfloat face[6][4][3]= {
		{{-width,-height, -depth},{width, -height, -depth},{width, height, -depth},{-width, height, -depth}}, //front
		{{-width,-height, depth},{width, -height, depth},{width, height, depth},{-width, height, depth}},		//back
		{{width, -height, -depth},{width, -height, depth},{width, height, depth},{width, height, -depth}},		//right
		{{-width, -height, depth},{-width, -height, -depth},{-width, height, -depth},{-width, height, depth}},	//left
		{{width, height, depth},{-width, height, depth},{-width, height, -depth},{width, height, -depth}},	//top
		{{-width, -height, depth},{width, -height, depth},{width, -height, -depth},{-width, -height, -depth}} //bottom
	};
	
	int i;
	for(i=0;i<6;i++){
		switch (i){
			case 0 :
				 glBindTexture(GL_TEXTURE_2D, textFront);
				 break;
			case 1 :
				glBindTexture(GL_TEXTURE_2D, textBack);
				break;
			case 2 :
				glBindTexture(GL_TEXTURE_2D, textRight);
				break;
			case 3 :
				glBindTexture(GL_TEXTURE_2D, textLeft);
				break;
			case 4 :
				glBindTexture(GL_TEXTURE_2D, textTop);
				break;
			case 5 :
				glBindTexture(GL_TEXTURE_2D, textBottom);
				break;	
		}
		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		glTexCoord2f(0,textKoor);
		glVertex3f(face[i][0][0], face[i][0][1], face[i][0][2]);
		glTexCoord2f(textKoor,textKoor);
		glVertex3f(face[i][1][0], face[i][1][1], face[i][1][2]);
		glTexCoord2f(textKoor,0);
		glVertex3f(face[i][2][0], face[i][2][1], face[i][2][2]);
		glTexCoord2f(0,0);
		glVertex3f(face[i][3][0], face[i][3][1], face[i][3][2]);
		glEnd();
		glPopMatrix();
	}
}


