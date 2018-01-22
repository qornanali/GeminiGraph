#include "backup.h"


 BOOL fullscreen;
 BOOL mouseDown;
 
 float xrot;
 float yrot;
 
 float xdiff;
 float ydiff;
 GLuint textureid;
 GLuint textureFloor;
 GLuint textureTembok;
 GLuint texturePondasi;
 GLuint textureTiang;
 GLuint textureVentilasi;
 GLuint texturePlafon;
	 
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

 GLfloat yObjek;

 cJSON *objPendopo;

void readFile(){
 static double tmpScale1, tmpScale2;
 char c;
 char content[5000];
 int i=0;
 
 FILE *fPendopo = fopen("input.json","r");
 if (fPendopo != NULL){
  while ((c = fgetc(fPendopo)) != EOF) {
   content[i] = c;
   i++;
  }
 }
 
 content[i] = '\0';
 printf("%s",content);
 
 objPendopo = cJSON_Parse(content);
    fclose(fPendopo);
}

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

void bangunanInti(GLfloat width, GLfloat height, GLfloat depth, GLuint textFront, GLuint textBack, GLuint textRight, GLuint textLeft, GLuint textTop, GLuint textBottom, GLfloat textKoor){
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

void atasAtap(){
	//atas atap Front
	glBindTexture(GL_TEXTURE_2D, textureid);
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
	glBindTexture(GL_TEXTURE_2D, textureid);
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

void bawahAtap(){
	//	Bawah atap top
	
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.05f, 0.0f, 1.05f);
	glVertex3f( 1.05f, 0.0f, 1.05f);
	glVertex3f( 1.05f, 0.0f, -1.05f);
	glVertex3f(-1.05f, 0.0f, -1.05f);
	glEnd();
	
	//Bawah atap bottom
	glBindTexture(GL_TEXTURE_2D, texturePlafon);
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

void atap(){
	
	
	//Back
	glBindTexture(GL_TEXTURE_2D, textureid);
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
	glBindTexture(GL_TEXTURE_2D, textureid);
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
	glBindTexture(GL_TEXTURE_2D, textureid);
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
	glBindTexture(GL_TEXTURE_2D, textureid);
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
	glBindTexture(GL_TEXTURE_2D, textureid);
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

void gapura(){
	
	widthGapura = widthBase*0.25;
	heightGapura = 2;
	depthGapura = 20;
	widthTiang = 2;
	heightTiang = heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5;
	depthTiang = 2;
	
	//Kanopi
	glPushMatrix();
	glTranslatef(0 ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 );
	drawBox(widthGapura, heightGapura, depthGapura, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kiri depan 1
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kiri depan 2
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 - widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kanan depan 1
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kanan depan 2
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kiri belakang 1
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kiri belakang 2
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 - widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kanan belakang 1
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang kanan belakang 2
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + widthTiang * 2 , (heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5) * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5 );
	drawBox(widthTiang, heightTiang , depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang atas depan kiri
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 + (-widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang atas depan kanan
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + (widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 + depthGapura * 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang atas belakang kiri
	glPushMatrix();
	glTranslatef(-widthGapura * 0.5 + (-widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
	//Tiang atas belakang kanan
	glPushMatrix();
	glTranslatef(widthGapura * 0.5 + (widthTiang * 3) * 0.5   ,heightBase + heightTembok - 0.05 *40 - heightGapura * 0.5, depthTembok* 0.5 + 5 + ((depthBase * 0.5) - (depthTembok * 0.5)) + 0.5 - depthTiang * 0.5);
	drawBox(widthTiang * 3, heightGapura, depthTiang, textureTiang, textureTiang, textureTiang, textureTiang,textureTiang, textureTiang,1);
	glPopMatrix();
	
}

void tangga (){
	
	widthTangga = widthBase - 64;
	heightTangga = 0.5;
	depthTangga = 1;
	
	//Tangga Depan
	int i;
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(0,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i *0.5 , depthBase *0.5 + 5 - depthTangga - i);
	drawBox(widthTangga, heightTangga, depthTangga, 0,texturePondasi,0,0,textureFloor,0,1);
	glPopMatrix();
	}
	
	//Tangga kiri depan
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, 8.5 - i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, texturePondasi,texturePondasi,0,texturePondasi,textureFloor,texturePondasi,1);
	glPopMatrix();
	}
	
	//Tangga kiri belakang
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, -8.5 + i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, texturePondasi,texturePondasi,0,texturePondasi,textureFloor,texturePondasi,1);
	glPopMatrix();
	}
	
	//Tangga kanan depan
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, 8.5 - i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, texturePondasi,texturePondasi,texturePondasi,0,textureFloor,texturePondasi,1);
	glPopMatrix();
	}
	
	//Tangga kanan belakang
	for(i=0;i<4; i++){
	glPushMatrix();
	glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5,heightBase * 0.5 - heightTangga * 2 + heightTangga * 0.5 + i * 0.5, -8.5 + i);
	drawBox(widthTangga * 0.5, heightTangga, depthTangga, texturePondasi,texturePondasi,texturePondasi,0,textureFloor,texturePondasi,1);
	glPopMatrix();
	}
}
 
bool init()
{
	readFile();
//	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	textureid = SOIL_load_OGL_texture("roof.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	textureFloor = SOIL_load_OGL_texture("floor.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	textureTembok = SOIL_load_OGL_texture("tembok4.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	texturePondasi = SOIL_load_OGL_texture("asset/rock.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	textureTiang = SOIL_load_OGL_texture("images.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	textureVentilasi = SOIL_load_OGL_texture("ventilasi.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
	texturePlafon = SOIL_load_OGL_texture("interior.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_TEXTURE_REPEATS);
 
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_LINEAR );
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	return true;
}
 
void display()
{
	readFile();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	 
	gluLookAt(
	0.0f, 15.0f, 80.0f,
	0.0f, 15.0f, 0.0f,
	0.0f, 40.0f, 0.0f);
	 
	
	
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	widthBase = 80;
	widthTembok = widthBase - 20;
	heightBase = 2;
	heightTembok = 13;
	depthBase = widthBase + 15;
	depthTembok = depthBase - 20;
	heightFentilasi = 1;
	depthFentilasi = 0.5;
	
	glPushMatrix();
	glScalef(cJSON_GetObjectItem(objPendopo, "width")->valuedouble, cJSON_GetObjectItem(objPendopo, "height")->valuedouble, cJSON_GetObjectItem(objPendopo, "depth")->valuedouble);
	//Base
	glPushMatrix();
	glTranslatef(0,heightBase * 0.5,0);
	drawBox(widthBase,heightBase,depthBase, texturePondasi, texturePondasi, texturePondasi, texturePondasi, textureFloor, 0, 40.0);
	glPopMatrix();
	
	//Depan kiri
	glPushMatrix();
	glTranslatef(-widthTembok*0.5 + widthTiang * 3,heightBase * 0.5, depthBase * 0.5 + depthTiang);
	drawBox(widthBase - 48,heightBase, 5, 0,texturePondasi,texturePondasi,texturePondasi,textureFloor,0,4);
	glPopMatrix();
	
	//Depan kanan
	glPushMatrix();
	glTranslatef(widthTembok*0.5 - widthTiang * 3,heightBase * 0.5, depthBase * 0.5 + depthTiang);
	drawBox(widthBase - 48,heightBase, 5, 0,texturePondasi,texturePondasi,texturePondasi,textureFloor,0,4);
	glPopMatrix();
	
	//Kiri
	glPushMatrix();
	glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5, heightBase * 0.5, 0);
	drawBox(widthTangga * 0.5, heightBase, 10, texturePondasi,texturePondasi,texturePondasi,0,textureFloor,0,1);
	glPopMatrix();
	
	//Kanan
	glPushMatrix();
	glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5, heightBase * 0.5, 0);
	drawBox(widthTangga * 0.5, heightBase, 10, texturePondasi,texturePondasi,0,texturePondasi,textureFloor,0,1);
	glPopMatrix();
	
	//	Bangunan Inti
	glPushMatrix();
	glTranslatef(0,heightTembok * 0.5 - heightFentilasi + heightBase - 0.25 ,0);
	bangunanInti(widthTembok,heightTembok - heightFentilasi * 2.5,depthTembok, textureTiang, textureTembok, textureTembok, textureTembok, texturePlafon, textureFloor, 1);
	glPopMatrix();
	
	// Atap
	glPushMatrix();
	glTranslatef(0, heightBase + heightTembok + 0.25 * 0.5 + 0.05 *40, 0);
	glScalef(42,40,44);
		glPushMatrix();
		glTranslatef(0,0.15,0);
		glScalef(0.65, 0.55, 0.65);
		atap();
		glPopMatrix();
		glPushMatrix();
		glScalef(0.7,1.8,0.7);
		atap();
		glPopMatrix();
	atap();
	bawahAtap();
		glPushMatrix();
		glTranslatef(0,0.2,0);
		atasAtap();
		glPopMatrix();
	glPopMatrix();
	
	//Ventilasi depan belakang
	int i;
	for (i=0;i<=2;i=i+2){
		
		glPushMatrix();
		glRotatef(90 * i, 0,1,0);
			glPushMatrix();
			glTranslatef(0, heightBase + heightTembok - heightFentilasi *0.5, depthTembok * 0.5);
			drawBox(widthTembok, heightFentilasi, depthFentilasi, textureVentilasi,textureVentilasi,0,0,0,0,5);
			glPopMatrix();
		
			glPushMatrix();
			glTranslatef(0, heightBase + heightTembok + 0.25 * 0.5 - heightFentilasi * 2 , depthTembok * 0.5);
			drawBox(widthTembok, heightFentilasi, depthFentilasi, textureVentilasi,textureVentilasi,0,0,0,0,5);
			glPopMatrix();
		glPopMatrix();
	}
	
	//Ventilasi samping
	for(i=0;i<=1;i++){
	
		glPushMatrix();
		glTranslatef(widthTembok * 0.5 * pow(-1,i), heightBase + heightTembok - heightFentilasi *0.5,0);
			glPushMatrix();
			glRotatef(90, 0,1,0);
			drawBox(depthTembok, heightFentilasi, depthFentilasi, textureVentilasi,textureVentilasi,0,0,0,0,5);
			glPopMatrix();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(widthTembok * 0.5 * pow(-1,i), heightBase + heightTembok + 0.25 * 0.5 - heightFentilasi * 2 ,0);
			glPushMatrix();
			glRotatef(90, 0,1,0);
			drawBox(depthTembok, heightFentilasi, depthFentilasi, textureVentilasi,textureVentilasi,0,0,0,0,5);
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
	
	gapura();
	tangga();
	glPopMatrix();
	
	glutSwapBuffers();
}

void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	 
	glViewport(0, 0, w, h);
	 
	gluPerspective(45.0f, 1.0f * w / h, 1.0f, 1000.0f);
	 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
 
void idle()
{
//	if (!mouseDown)
//	{
//		xrot += 0.3f;
//		yrot += 0.4f;
//	}
//	 
//	glutPostRedisplay();
}
 
static void 
key(unsigned char key, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
    switch (key) 
    {
        case 27 : 
        case 'w':
            glTranslatef(0,0,1);
            break;
        case 's':
	        glTranslatef(0,0,-1);
	        break;
		case 'a':
			glTranslated(1,0,0);
            break;
        case 'd':
            glTranslated(-1,0,0);
            break;
    }
	glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y){
	glMatrixMode(GL_PROJECTION);
    switch (key){
    	case GLUT_KEY_PAGE_UP : 
				glTranslated(0,-1,0);
				yObjek = yObjek + 1;
    		break;
    	case GLUT_KEY_PAGE_DOWN :
    		if (yObjek == heightBase + 1){
    			break;
			}else {
				glTranslated(0,1,0);
				yObjek = yObjek - 1;	
			}
			printf("yObjek = %f", yObjek);
    		break;
    	case GLUT_KEY_F5 :
    		init();
    		break;
	}
		glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
 
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		 
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}
 
void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
	 
	glutPostRedisplay();
	}
}
 
int start(int argc, char *argv[])
{
	glutInit(&argc, argv);
	 
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1366, 768);
	 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	 
	glutCreateWindow("Pendopo Agung");
	 
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);
	glutIdleFunc(idle);
	
	
	init();
//	 
//	if (!init())
//	return 1;
//	 
	glutMainLoop();
}

