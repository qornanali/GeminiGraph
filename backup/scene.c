#include "scene.h"

#include "pendopo.h"

extern LTextures lTextures;
extern LConfigs lConfigs;

extern cJSON * jsonPendopo;

extern double rotate_y; 
extern double rotate_x;
extern double scale;

void onWorldDisplay(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,0, -5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
  	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
	  	glRotatef(rotate_x, 0.5, 0.0, 0.0 );
	  	glRotatef(rotate_y, 0.0, 0.5, 0.0 );
	  	glScalef(scale,scale,scale);
//		P_Texture P = getTexture(lTextures, "atap");
//		Color color[6] = {DEFAULT_COLOR, insColor(1.0, 0.0, 0.0), DEFAULT_COLOR, insColor(1.0, 0.0, 1.0), DEFAULT_COLOR, insColor(1.0, 1.0, 0.0)};
//		int bindings[6] = {TRUE, TRUE, FALSE, TRUE, TRUE, FALSE};
//		drawPrism4(DEFAULT_COORD, 3.0, 1.5, 2.0, color, P == NULL ? 0 : P->id, bindings);
//		P_Texture P2 = getTexture(lTextures, "lantai");
//		Color color2[6] = {DEFAULT_COLOR, insColor(1.0, 0.0, 0.0), DEFAULT_COLOR, insColor(1.0, 0.0, 1.0), DEFAULT_COLOR, insColor(1.0, 1.0, 0.0)};
//		int bindings2[6] = {TRUE, TRUE, FALSE, TRUE, TRUE, FALSE};
//		drawPrism4(insCoord(5.0, 5.0, 5.0), 3.0, 1.5, 2.0, color2, P2 == NULL ? 0 : P2->id, bindings2);
	  	drawCartesius(DEFAULT_COORD, 100.0);
	glPopMatrix();
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
    rotate_y += 1;
 
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 1;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 1;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 1;
    
    else if(key == GLUT_KEY_PAGE_UP){
    	scale+=0.1;
	} 
  else if(key == GLUT_KEY_PAGE_DOWN)
  	scale-=0.1;
  	
//  	else if(key == GLUT_KEY_F5)
//  	loadTexture();
 
  glutPostRedisplay();
} 

void onNormalKeyClicked(unsigned char key, int x, int y){
	glMatrixMode(GL_PROJECTION);
	switch (key){
		case 27 :
		case 'w':
			glTranslated(0,0,0.1);
			break;
		case 's':
			glTranslated(0,0,-0.1);
			break;
			
		case 'a':
			glTranslated(0.1,0,0);
			break;
		case 'd':
			glTranslated(-0.1,0,0);
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

