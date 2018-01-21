#include "scene.h"

#include "pendopo.h"

extern LInts lTextures;
extern LStrings lConfigs;
extern LDoubles lMeasures;

extern cJSON * jsonPendopo;

extern double rotate_y; 
extern double rotate_x;
extern double rotate_z;
extern double scale;


void onWorldDisplay(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
  	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
	  	glRotatef(rotate_x, 0.5, 0.0, 0.0);
		glRotatef(rotate_y, 0.0, 0.5, 0.0);
		glRotatef(rotate_z, 0.0, 0.0, 0.5);
		glPushMatrix();		
		  	glScalef(scale,scale,scale);
		  	drawWalls();
			drawPillars();
			drawFront();
			drawRoof();
			drawLand();
			drawSky();
		glPopMatrix();
	  	drawCartesius(DEFAULT_COORD, 100.0);
	glPopMatrix();
	
	glFlush();
  	glutSwapBuffers();
}

void onWorldIdle(){
	
}

void onWorldReshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluPerspective(65, (float)w / (float) h, 0.1, 1000);
  	glMatrixMode(GL_MODELVIEW);
}

void onSpecialKeyClicked(int key, int x, int y ){
  	if (key == GLUT_KEY_RIGHT)
    	rotate_y++;
 
 	else if (key == GLUT_KEY_LEFT)
    	rotate_y--;
 
  	else if (key == GLUT_KEY_UP)
    	rotate_x++;
 
  	else if (key == GLUT_KEY_DOWN)
    	rotate_x--;
	
	else if(key == GLUT_KEY_PAGE_UP)
    	rotate_z++;
    
  	else if(key == GLUT_KEY_PAGE_DOWN)
  		rotate_z--;
  	
//  	else if(key == GLUT_KEY_F5)
//  	loadTexture();
 
  glutPostRedisplay();
} 

void onNormalKeyClicked(unsigned char key, int x, int y){
	glMatrixMode(GL_PROJECTION);
	switch (key){
		case 27 :
		case 'w':
			glTranslated(0, 0, 0.1);
			break;
		case 's':
			glTranslated(0, 0, -0.1);
			break;
		case 'a':
			glTranslated(0.1, 0, 0);
			break;
		case 'd':
			glTranslated(-0.1, 0, 0);
			break;
		case 61 :
			scale += 0.1;
			break;
		case 45 :
			scale -= 0.1;
			break;
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void onMotionMouseClicked(int x, int y){
	
}

void onButtonMouseClicked(int button, int state, int x, int y){
	
}

void onPassiveMouseActived(int x, int y){
	
}

