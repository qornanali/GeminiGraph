#include "interface.h"

#include <math.h>
#include <stdio.h>

void drawCube(Coord coord, GLfloat radius, Color color[], GLuint textureId, BOOL bindings[], GLfloat repeat){
	drawPrism4(coord, radius, radius, radius, color, textureId, bindings, repeat);
}

void drawPrism4(Coord coord, GLfloat length, GLfloat width, GLfloat height, 
				Color color[],  GLuint textureId, BOOL bindings[], GLfloat repeat){
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
			glVertex3f(coord.x + length, coord.y, coord.z);    
			if(bindings[0]){
				glTexCoord2f(0.0f, repeat);
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
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z);
			if(bindings[1]){
				glTexCoord2f(repeat, 1.0f);
			  }
			glVertex3f(coord.x, coord.y, coord.z + width);  
			if(bindings[1]){
				glTexCoord2f(0.0f, repeat);
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
				glTexCoord2f(repeat, 0.0f);
			  }
			glVertex3f(coord.x + length, coord.y, coord.z);
			if(bindings[2]){
				glTexCoord2f(repeat, repeat);
			  }
		  	glVertex3f(coord.x + length, coord.y + height, coord.z);
			if(bindings[2]){
				glTexCoord2f(0.0f, repeat);
			  }  
		  	glVertex3f(coord.x + length, coord.y + height, coord.z + width);     
			if(bindings[2]){
				glTexCoord2f(0.0f, 0.0f);
			}
		  	glVertex3f(coord.x + length, coord.y, coord.z + width);
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
				glTexCoord2f(repeat, 0.0f);
			  }
		  	glVertex3f(coord.x, coord.y + height, coord.z);
			if(bindings[4]){
				glTexCoord2f(repeat, repeat);
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
				glTexCoord2f(repeat, 0.0f);
			  }
	  		glVertex3f(coord.x, coord.y, coord.z + width);
			if(bindings[5]){
				glTexCoord2f(repeat, repeat);
			  }
	  		glVertex3f(coord.x, coord.y + height, coord.z + width);
			  if(bindings[5]){
				glTexCoord2f(0.0f, repeat);
			  }  
	  		glVertex3f(coord.x + length, coord.y + height, coord.z + width);   
			if(bindings[5]){
				glTexCoord2f(0.0f, 0.0f);
			}
	  		glVertex3f(coord.x + length, coord.y, coord.z + width);
	 	glEnd();
 	
	glPopMatrix();
}

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


