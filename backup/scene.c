#include "scene.h"

#include "pendopo.h"
#include "cJSON.h"
#include "list_string.h"
#include "list_int.h"
#include "list_double.h"
#include "interface.h"

extern LInts lTextures;
extern LStrings lConfigs;
extern LDoubles lMeasures;

extern float xrot;
extern float yrot;
extern float zrot;
extern float xdiff;
extern float ydiff;
extern float scale;
extern BOOL mouseDown;
extern BOOL fullscreen;
extern GLfloat yObjek;

GLfloat widthTembok; 
 GLfloat heightTembok;
 GLfloat depthTembok;
 GLfloat widthBase;
 GLfloat  heightBase;
 GLfloat depthBase;
 GLfloat widthGapura;
 GLfloat heightGapura;
 GLfloat depthGapura;
 GLfloat widthTiang;
 GLfloat  heightTiang;
 GLfloat depthTiang;
 GLfloat widthTangga;
 GLfloat heightTangga;
 GLfloat depthTangga;
 GLfloat widthFentilasi;
 GLfloat heightFentilasi;
 GLfloat depthFentilasi;

void onWorldDisplay(){
	widthBase = 80;
	widthTembok = widthBase - 20;
	heightBase = 2;
	heightTembok = 13;
	depthBase = widthBase + 15;
	depthTembok = depthBase - 20;
	heightFentilasi = 1;
	depthFentilasi = 0.5;
	double scalex = getDouble(lMeasures, "width") == NULL ? 0 : getDouble(lMeasures, "width")->value;
	double scaley = getDouble(lMeasures, "height") == NULL ? 0 : getDouble(lMeasures, "height")->value;
	double scalez = getDouble(lMeasures, "depth") == NULL ? 0 : getDouble(lMeasures, "depth")->value;
	GLuint tRock = getInt(lTextures, "batu") == NULL ? 0 : getInt(lTextures, "batu")->value; 
	GLuint tFloor = getInt(lTextures, "lantai-2") == NULL ? 0 : getInt(lTextures, "lantai-2")->value; 
	GLuint tPlafon = getInt(lTextures, "interior") == NULL ? 0 : getInt(lTextures, "interior")->value; 
	GLuint tWall = getInt(lTextures, "tembok4") == NULL ? 0 : getInt(lTextures, "tembok4")->value; 
	GLuint tPilar = getInt(lTextures, "pilar") == NULL ? 0 : getInt(lTextures, "pilar")->value; 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(
		0.0f, 10.0f, 60.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
//	glPushMatrix();
  	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
	glRotatef(xrot, 0.1f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 0.1f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 0.1f);
	glPushMatrix();		
	drawCartesius(DEFAULT_COORD, 100.0);
	glScalef(scalex, scaley, scalez);
		//Base
		glPushMatrix();
		glTranslatef(0,heightBase * 0.5,0);
		drawBox(widthBase,heightBase,depthBase, tRock, tRock, tRock, tRock, tFloor, 0, 40.0);
		glPopMatrix();
		
		//Depan kiri
		glPushMatrix();
		glTranslatef(-widthTembok*0.5 + widthTiang * 3,heightBase * 0.5, depthBase * 0.5 + depthTiang);
		drawBox(widthBase - 48,heightBase, 5, 0,tRock,tRock,tRock,tFloor,0,4);
		glPopMatrix();
		
		//Depan kanan
		glPushMatrix();
		glTranslatef(widthTembok*0.5 - widthTiang * 3,heightBase * 0.5, depthBase * 0.5 + depthTiang);
		drawBox(widthBase - 48,heightBase, 5, 0,tRock,tRock,tRock,tFloor,0,4);
		glPopMatrix();
		
		//Kiri
		glPushMatrix();
		glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5, heightBase * 0.5, 0);
		drawBox(widthTangga * 0.5, heightBase, 10, tRock,tRock,tRock,0,tFloor,0,1);
		glPopMatrix();
		
		//	Bangunan Inti
		glPushMatrix();
		glTranslatef(0,heightTembok * 0.5 - heightFentilasi + heightBase - 0.25 ,0);
		drawCoreBuilding(widthTembok,heightTembok - heightFentilasi * 2.5,depthTembok, tPilar, tWall, tWall, tWall, tPlafon, tFloor, 1);
		glPopMatrix();
		
		//Kanan
		glPushMatrix();
		glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5, heightBase * 0.5, 0);
		drawBox(widthTangga * 0.5, heightBase, 10, tRock,tRock,0,tRock,tFloor,0,1);
		glPopMatrix();
		
		//	Bangunan Inti
		glPushMatrix();
		glTranslatef(0,heightTembok * 0.5 - heightFentilasi + heightBase - 0.25 ,0);
		drawCoreBuilding(widthTembok,heightTembok - heightFentilasi * 2.5,depthTembok, tPilar, tWall, tWall, tWall, tPlafon, tFloor, 1);
		glPopMatrix();
		
		// Atap
		drawRoof();
		
		//Ventilasi
		drawVents();
	
		//gapura
		drawGapura();
		
		//tanggaa
		drawStairs();
		
		//tanah
		drawLand();
		
		//langit
		drawSky();
	glPopMatrix();
  	glutSwapBuffers();
}

void onWorldIdle(){
//	if (!mouseDown){
//		xrot += 0.01f;
//		yrot += 0.01f;
//		zrot += 0.01f;
//	}
	 
//	glutPostRedisplay();
}

void onWorldReshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluPerspective(65.0f, 1.0f * (float)w / (float) h, 1.0, 1000);
  	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void onSpecialKeyClicked(int key, int x, int y ){
  	if (key == GLUT_KEY_RIGHT)
    	yrot++;
 
 	else if (key == GLUT_KEY_LEFT)
    	yrot--;
 
  	else if (key == GLUT_KEY_UP)
    	xrot++;
 
  	else if (key == GLUT_KEY_DOWN)
    	xrot--;
	
	else if(key == GLUT_KEY_PAGE_UP)
		glTranslated(0,-1,0);
    
  	else if(key == GLUT_KEY_PAGE_DOWN)
		glTranslated(0,1,0);
  	
//  	else if(key == GLUT_KEY_F5)
//  	loadTexture();
	glMatrixMode(GL_MODELVIEW);
  	glutPostRedisplay();
} 

void onNormalKeyClicked(unsigned char key, int x, int y){
	glMatrixMode(GL_PROJECTION);
	switch (key){
		case 27 :
		case 'w':
            glTranslatef(0, 0, 1);
			break;
		case 's':
	        glTranslatef(0, 0, -1);
			break;
		case 'a':
			glTranslatef(1, 0, 0);
			break;
		case 'd':
            glTranslatef(-1, 0, 0);
			break;
		case 61 :
			scale += 0.01;
			break;
		case 45 :
			scale -= 0.01;
			break;
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void onMotionMouseClicked(int x, int y){
	if (mouseDown){
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}

void onButtonMouseClicked(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = TRUE;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	} else{
		mouseDown = FALSE;
	}
}

void onPassiveMouseActived(int x, int y){
	
}

