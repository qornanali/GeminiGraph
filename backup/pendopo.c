#include "pendopo.h"

#include "interface.h"
#include "list_string.h"
#include "list_int.h"
#include "list_double.h"

extern LInts lTextures;
extern LStrings lConfigs;
extern LDoubles lMeasures;

extern GLfloat widthTembok; 
extern GLfloat heightTembok;
extern  GLfloat depthTembok;
extern GLfloat widthBase;
extern GLfloat  heightBase;
extern GLfloat depthBase;
extern GLfloat widthGapura;
extern GLfloat heightGapura;
extern GLfloat depthGapura;
extern GLfloat widthTiang;
extern GLfloat  heightTiang;
extern GLfloat depthTiang;
extern GLfloat widthTangga;
extern GLfloat heightTangga;
extern GLfloat depthTangga;
extern GLfloat widthFentilasi;
extern GLfloat heightFentilasi;
extern GLfloat depthFentilasi;
//
//void drawWalls(float length, float width, float height){
//	
//}

void drawPillars(float length, float width, float height){
	
}

void drawFront(float length, float width, float height){
	
}

//void drawRoof(float length, float width, float height){
//	
//}

void drawLand(){
	Color colors[6] = {DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR};
	BOOL bindings[6] = {FALSE, FALSE, FALSE, FALSE, TRUE, FALSE};
	P_Int Asphalt = getInt(lTextures, "asphalt");
	glPushMatrix();
	glTranslatef(-300.0, -0.75, -300.0);
	drawPrism4(DEFAULT_COORD, 600.0, 600.0, 0.25, colors, Asphalt == NULL ? 0 : Asphalt->value, bindings, 32);
	glPopMatrix();
}

void drawSky(){
	Color colors[6] = {DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_COLOR};
	BOOL bindings[6] = {TRUE, TRUE, TRUE, FALSE, FALSE, TRUE};
	P_Int sky = getInt(lTextures, "sky");
	glPushMatrix();
	glTranslatef(-300.0, -20.0, -300.0);
	drawPrism4(DEFAULT_COORD, 600.0, 600.0, 600.0, colors, sky == NULL ? 0 : sky->value, bindings, 1);
	glPopMatrix();
}

void drawFloors(float length, float width, float height){
	
}

void drawStairs(){
	GLuint tRock = getInt(lTextures, "batu") == NULL ? 0 : getInt(lTextures, "batu")->value;
	GLuint tFloor = getInt(lTextures, "lantai") == NULL ? 0 : getInt(lTextures, "lantai")->value;
	
	widthTangga = widthBase - 64;
	heightTangga = 0.5;
	depthTangga = 1;
	
	//Tangga Depan
	int i;
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(0,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i *0.5 , getDouble(lMeasures, "width_base")->value *0.5 + 5 - depthTangga - i);
	drawBox(widthTangga, heightTangga, depthTangga, 0,tRock,0,0,tFloor,0,1);
	glPopMatrix();
	}
	
	//Tangga kiri depan
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, 8.5 - i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, tRock,tRock,0,tRock,tFloor,tRock,1);
	glPopMatrix();
	}
	
	//Tangga kiri belakang
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, -8.5 + i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, tRock,tRock,0,tRock,tFloor,tRock,1);
	glPopMatrix();
	}
	
	//Tangga kanan depan
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, 8.5 - i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, tRock,tRock,tRock,0,tFloor,tRock,1);
	glPopMatrix();
	}
	
	//Tangga kanan belakang
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, -8.5 + i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, tRock,tRock,tRock,0,tFloor,tRock,1);
	glPopMatrix();
	}	
}

void drawVents(){
	GLuint tVent = getInt(lTextures, "ventilasi") == NULL ? 0 : getInt(lTextures, "ventilasi")->value;
	int i;
	for (i=0;i<=2;i=i+2){
		
		glPushMatrix();
		glRotatef(90 * i, 0,1,0);
			glPushMatrix();
			glTranslatef(0, heightBase + heightTembok - heightFentilasi *0.5, depthTembok * 0.5);
			drawBox(widthTembok, heightFentilasi, depthFentilasi, tVent,tVent,0,0,0,0,5);
			glPopMatrix();
		
			glPushMatrix();
			glTranslatef(0, heightBase + heightTembok + 0.25 * 0.5 - heightFentilasi * 2 , depthTembok * 0.5);
			drawBox(widthTembok, heightFentilasi, depthFentilasi, tVent,tVent,0,0,0,0,5);
			glPopMatrix();
		glPopMatrix();
	}
	
	//Ventilasi samping
	for(i=0;i<=1;i++){
	
		glPushMatrix();
		glTranslatef(widthTembok * 0.5 * pow(-1,i), heightBase + heightTembok - heightFentilasi *0.5,0);
			glPushMatrix();
			glRotatef(90, 0,1,0);
			drawBox(depthTembok, heightFentilasi, depthFentilasi, tVent,tVent,0,0,0,0,5);
			glPopMatrix();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(widthTembok * 0.5 * pow(-1,i), heightBase + heightTembok + 0.25 * 0.5 - heightFentilasi * 2 ,0);
			glPushMatrix();
			glRotatef(90, 0,1,0);
			drawBox(depthTembok, heightFentilasi, depthFentilasi, tVent,tVent,0,0,0,0,5);
			glPopMatrix();
		glPopMatrix();
	}
	
	GLfloat deltaWidth = widthTembok / 5;
	GLfloat deltaDepth = depthTembok / 5;
	
			for(i=0; i<=5; i++){
			glPushMatrix();
			glTranslatef(widthTembok *0.5 - deltaWidth * i, heightTembok * 0.5 + heightBase * 0.5 + heightFentilasi * 0.5 + 0.5, depthTembok * 0.5);
			drawBox(1.5, heightTembok, 1, 0,0,0,0,0,0,1);
			glPopMatrix();
			}
	int j;
	for (j=0;j<=1;j++){
		for(i=0; i<=5; i++){
			glPushMatrix();
			glRotatef(90, 0,1,0);
			glPushMatrix();
			glTranslatef(depthTembok *0.5 - deltaDepth * i, heightTembok * 0.5 + heightBase * 0.5 + heightFentilasi * 0.5 + 0.5, widthTembok * 0.5  * pow(-1,j));
			drawBox(1.5, heightTembok, 1, 0,0,0,0,0,0,1);
			glPopMatrix();
			glPopMatrix();
			}
	}
}

void drawGapura(){
	GLuint tPilar = getInt(lTextures, "pilar-2") == NULL ? 0 : getInt(lTextures, "pilar-2")->value;
	
	widthGapura = widthBase*0.25;
	heightGapura = 2;
	depthGapura = 20;
	widthTiang = 2;
	heightTiang = heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5;
	depthTiang = 2;
	
	//Kanopi
	glPushMatrix();
	glTranslatef(0 ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 );
	drawBox(widthGapura, heightGapura, depthGapura, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kiri depan 1
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kiri depan 2
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 - widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kanan depan 1
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kanan depan 2
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kiri belakang 1
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kiri belakang 2
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 - widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kanan belakang 1
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang kanan belakang 2
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang atas depan kiri
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 + (-widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang atas depan kanan
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + (widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang atas belakang kiri
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 + (-widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
	
	//Tiang atas belakang kanan
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + (widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, tPilar, tPilar, tPilar, tPilar,tPilar, tPilar,1);
	glPopMatrix();
}

void drawRoofMid(){
	GLuint tRoof = getInt(lTextures, "atap") == NULL ? 0 : getInt(lTextures, "atap")->value;
		//Back
	glBindTexture(GL_TEXTURE_2D, tRoof);
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0,5);
	glVertex3f( 1.0f, 0.0f, -1.0f);
	glTexCoord2f(5,5);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glTexCoord2f(5,0);
	glVertex3f(-0.3f, 0.25f, -0.2f);
	glTexCoord2f(0,0);
	glVertex3f(0.3f, 0.25f, -0.2f);
	glEnd();
	
	//Front
	glBindTexture(GL_TEXTURE_2D, tRoof);
	glBegin(GL_POLYGON);
	glColor3f(3.0f, 0.0f, 3.0f);
	glTexCoord2f(0,5);
	glVertex3f( 1.0f, 0.0f, 1.0f);
	glTexCoord2f(5,5);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glTexCoord2f(5,0);
	glVertex3f(-0.3f, 0.25f, 0.2f);
	glTexCoord2f(0,0);
	glVertex3f(0.3f, 0.25f, 0.2f);
	glEnd();
	
	// LEFT
	glBindTexture(GL_TEXTURE_2D, tRoof);
 	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0,5.0);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glTexCoord2f(10.0,5.0);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glTexCoord2f(5.0,0.0);
	glVertex3f(-0.3f, 0.25f, 0.2f);
	glTexCoord2f(0.0,0.0);
	glVertex3f(-0.3f, 0.25f, -0.2f);
	glEnd();
	
	// RIGHT
	glBindTexture(GL_TEXTURE_2D, tRoof);
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0,5.0);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glTexCoord2f(5.0,5.0);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glTexCoord2f(5.0,0.0);
	glVertex3f(0.3f, 0.25f, 0.2f);
	glTexCoord2f(0.0,0.0);
	glVertex3f(0.3f, 0.25f, -0.2f);
	glEnd();
	
	//Top
	glBindTexture(GL_TEXTURE_2D, tRoof);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0,5);
	glVertex3f(0.3f, 0.25f, 0.2f);
	glTexCoord2f(5,5);
	glVertex3f(-0.3f, 0.25f, 0.2f);
	glTexCoord2f(5,0);
	glVertex3f(-0.3f, 0.25f, -0.2f);
	glTexCoord2f(0,0);
	glVertex3f(0.3f, 0.25f, -0.2f);	
	glEnd();
}

void drawRoofTop(){
	GLuint tRoof = getInt(lTextures, "atap") == NULL ? 0 : getInt(lTextures, "atap")->value;
	//atas atap Front
	glBindTexture(GL_TEXTURE_2D, tRoof);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glTexCoord2f(0,0);
	glVertex3f(-0.21f, 0.25f, 0.14f);
	glTexCoord2f(2,0);
	glVertex3f(0.21f, 0.25f, 0.14f);
	glTexCoord2f(2,2);
	glVertex3f(0.3f, 0.3f, 0.0f);
	glTexCoord2f(0,2);
	glVertex3f(-0.3f, 0.3f, 0.0f);
	glEnd();
	
	//atas atap back
	glBindTexture(GL_TEXTURE_2D, tRoof);
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0,0);
	glVertex3f(0.21f, 0.25f, -0.14f);
	glTexCoord2f(2,0);
	glVertex3f(-0.21f, 0.25f, -0.14f);
	glTexCoord2f(2,2);
	glVertex3f(-0.3f, 0.3f, -0.0f);
	glTexCoord2f(0,2);
	glVertex3f(0.3f, 0.3f, -0.0f);
	
	glEnd();
	
	//atas atap right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.21f, 0.25f, 0.14f);
	glVertex3f(0.21f, 0.25f, -0.14f);
	glVertex3f(0.3f, 0.3f, 0.0f);
	glEnd();
	
	//atas atap left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.21f, 0.25f, -0.14f);
	glVertex3f(-0.21f, 0.25f, 0.14f);
	glVertex3f(-0.3f, 0.3f, -0.0f);
	glEnd();

}

void drawRoofBot(){
	GLuint tPlafon = getInt(lTextures, "interior") == NULL ? 0 : getInt(lTextures, "interior")->value;
	//	Bawah atap top
	
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.05f, 0.0f, 1.05f);
	glVertex3f( 1.05f, 0.0f, 1.05f);
	glVertex3f( 1.05f, 0.0f, -1.05f);
	glVertex3f(-1.05f, 0.0f, -1.05f);
	glEnd();
	
	//Bawah atap bottom
	glBindTexture(GL_TEXTURE_2D, tPlafon);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0,20);
	glVertex3f(-1.05f, -0.05f, 1.05f);
	glTexCoord2f(20,20);
	glVertex3f( 1.05f, -0.05f, 1.05f);
	glTexCoord2f(20,0);
	glVertex3f( 1.05f, -0.05f, -1.05f);
	glTexCoord2f(0,0);
	glVertex3f(-1.05f, -0.05f, -1.05f);
	glEnd();
	
	//Bawah atap front
	glBindTexture(GL_TEXTURE_2D, 0);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.05f, -0.05f, 1.05f);
	glVertex3f( 1.05f, -0.05f, 1.05f);
	glVertex3f( 1.05f, -0.0f, 1.05f);
	glVertex3f(-1.05f, -0.0f, 1.05f);
	glEnd();
	
	//Bawah atap back
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f( 1.05f, -0.05f, -1.05f);
	glVertex3f(-1.05f, -0.05f, -1.05f);
	glVertex3f(-1.05f, -0.0f, -1.05f);
	glVertex3f( 1.05f, -0.0f, -1.05f);
	
	glEnd();
	
	//Bawah atap right
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.05f, -0.05f, 1.05f);
	glVertex3f( 1.05f, -0.05f, -1.05f);
	glVertex3f( 1.05f, -0.0f, -1.05f);
	glVertex3f( 1.05f, -0.0f, 1.05f);
	glEnd();
	
	//Bawah atap left
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.05f, -0.05f, -1.05f);
	glVertex3f(-1.05f, -0.05f, 1.05f);
	glVertex3f(-1.05f, -0.0f, 1.05f);
	glVertex3f(-1.05f, -0.0f, -1.05f);
	glEnd();
}
void drawCoreBuilding(float width, float height, float depth, unsigned int textFront, unsigned int textBack, unsigned int textRight, unsigned int textLeft, unsigned int textTop, unsigned int textBottom, float textKoor){
	width = width*0.5;
	depth = depth*0.5;
	height = height*0.5;
	GLfloat face[4][4][3]= {
		{{-width,-height, -depth},{width, -height, -depth},{width, height, -depth},{-width, height, -depth}}, //front
		{{-width,-height, depth},{width, -height, depth},{width, height, depth},{-width, height, depth}},		//back
		{{width, -height, -depth},{width, -height, depth},{width, height, depth},{width, height, -depth}},		//right
		{{-width, -height, depth},{-width, -height, -depth},{-width, height, -depth},{-width, height, depth}},	//left
	};
	
	int i;
	for(i=0;i<4;i++){
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

void drawRoof(){
	glPushMatrix();
		glTranslatef(0, heightBase + heightTembok + 0.25 * 0.5 + 0.05 *40, 0);
		glScalef(42,40,44);
			glPushMatrix();
			glTranslatef(0,0.15,0);
			glScalef(0.65, 0.55, 0.65);
			drawRoofMid();
			glPopMatrix();
			glPushMatrix();
			glScalef(0.7,1.8,0.7);
			drawRoofMid();
			glPopMatrix();
		drawRoofMid();
		drawRoofBot();
			glPushMatrix();
			glTranslatef(0,0.2,0);
			drawRoofTop();
			glPopMatrix();
		glPopMatrix();
}

