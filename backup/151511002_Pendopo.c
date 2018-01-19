//
// File:        mycube.c
// Author:      Matt Daisley
// Created:     4/25/2012
// Project:     Source code for Make a Cube in OpenGL
// Description: Creates an OpenGL window and draws a 3D cube
//              That the user can rotate using the arrow keys
// 
// Controls:    Left Arrow  - Rotate Left
//              Right Arrow - Rotate Right
//              Up Arrow    - Rotate Up
//              Down Arrow  - Rotate Down     
 
// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <SOIL.h>
#include "cJSON.h"
#include <GL/freeglut_std.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 768

 
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------

void display();
void specialKeys();
void reshape();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0; 
double rotate_x=0;
double scale=0.5;

int texRoof, texFloor, texPilar, texWall;
cJSON *objPendopo;
// ----------------------------------------------------------
// Pendopo Variables
// ----------------------------------------------------------
double xLantai=2.8;
double yLantai=0.1;
double zLantai;

double xPendopo;
double yPendopo=0.3;
double zPendopo;

double xPilar=0.05;
double zPilar=0.05;
double zAtapPilar;




// ----------------------------------------------------------
void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluPerspective(45,(float)w/(float)h,0.1,1000);
  	glMatrixMode(GL_MODELVIEW);
}
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void bangunan_utama(){
	xPendopo = xLantai - 0.6;
	zPendopo = xPendopo+0.3;
	glBindTexture(GL_TEXTURE_2D,texWall);
	glBegin(GL_POLYGON);
	glColor3f( 3.0, 4.0, 0.0 );
	glTexCoord2f(1,0);
	glVertex3f(  xPendopo, -(yPendopo-0.1), -0.2 );
	glTexCoord2f(1,1);
	glVertex3f(  xPendopo,  yPendopo, -0.2 );
	glTexCoord2f(0,1);
	glVertex3f( -(xPendopo),  yPendopo, -0.2 );
	glTexCoord2f(0,0);
	glVertex3f( -(xPendopo), -(yPendopo-0.1), -0.2 ); 
	glEnd();
 
  // White side - BACK
  glBindTexture(GL_TEXTURE_2D,0);
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  xPendopo, -(yPendopo-0.1), zPendopo );
  glVertex3f(  xPendopo,  yPendopo, zPendopo );
  glVertex3f( -(xPendopo),  yPendopo, zPendopo );
  glVertex3f( -(xPendopo), -(yPendopo-0.1), zPendopo );
  glEnd();
 
  // Purple side - RIGHT
  glBindTexture(GL_TEXTURE_2D,texWall);
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glTexCoord2f(1,0);
  glVertex3f( xPendopo, -(yPendopo-0.1), -0.2 );
  glTexCoord2f(1,1);
  glVertex3f( xPendopo,  yPendopo, -0.2 );
  glTexCoord2f(0,1);
  glVertex3f( xPendopo,  yPendopo,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f( xPendopo, -(yPendopo-0.1),  zPendopo );
  glEnd();
 
  // Green side - LEFT
  glBindTexture(GL_TEXTURE_2D,texWall);
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glTexCoord2f(1,0);
  glVertex3f( -(xPendopo), -(yPendopo-0.1),  zPendopo );
  glTexCoord2f(1,1);
  glVertex3f( -(xPendopo),  yPendopo,  zPendopo );
  glTexCoord2f(0,1);
  glVertex3f( -(xPendopo),  yPendopo, -0.2 );
  glTexCoord2f(0,0);
  glVertex3f( -(xPendopo), -(yPendopo-0.1), -0.2 );
  glEnd();
}

void rooftop(){
  
  //FRONT
  glBindTexture(GL_TEXTURE_2D,texRoof);
  glBegin(GL_POLYGON);
  
  glColor3f(   0.5,  1.04,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f( xPendopo*0.5,  -yPendopo, -yPendopo) ;
  glTexCoord2f(1,1);
  glVertex3f( (xPendopo*0.5)+0.5,  yPendopo,  zPendopo*0.5 );
  glTexCoord2f(0,1);
  glVertex3f(-(xPendopo*0.5)-0.5,  yPendopo, zPendopo*0.5);
  glTexCoord2f(0,0);
  glVertex3f(-xPendopo*0.5,  -yPendopo, -yPendopo);
  glEnd();
  
  //BACK
  glBindTexture(GL_TEXTURE_2D,texRoof);
  glBegin(GL_POLYGON);
  glColor3f(   0.5,  1.04,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f( xPendopo*0.5,  -yPendopo, zPendopo);
  glTexCoord2f(1,1);
  glVertex3f( (xPendopo*0.5)+0.5,  yPendopo, zPendopo*0.5 );
  glTexCoord2f(0,1);
  glVertex3f(-(xPendopo*0.5)-0.5,  yPendopo, zPendopo*0.5 );
  glTexCoord2f(0,0);
  glVertex3f(-xPendopo*0.5,  -yPendopo, zPendopo);
  glEnd();
  
  //LEFT
  glBegin(GL_POLYGON);
  glVertex3f( xPendopo*0.5,  -yPendopo, zPendopo);
  glVertex3f( (xPendopo*0.5)+0.5,  yPendopo, zPendopo*0.5 );
  glVertex3f( (xPendopo*0.5)+0.5,  yPendopo,  zPendopo*0.5 );
  glVertex3f( xPendopo*0.5,  -yPendopo, -yPendopo) ;
  glEnd();
  
  //RIGHT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  0.0 );
  glVertex3f(-xPendopo*0.5,  -yPendopo, -yPendopo);
  glVertex3f(-(xPendopo*0.5)-0.5,  yPendopo, zPendopo*0.5);
  glVertex3f(-(xPendopo*0.5)-0.5,  yPendopo, zPendopo*0.5 );
  glVertex3f(-xPendopo*0.5,  -yPendopo, zPendopo);
  glEnd();
  
  //BOTTOM
  
  glBegin(GL_POLYGON);
  glColor3f(   0,  0,  4.0 );
  glVertex3f( xPendopo*0.5,  -yPendopo, -0.3 );
  glVertex3f( xPendopo*0.5,  -yPendopo, zPendopo );
  glVertex3f(-xPendopo*0.5,  -yPendopo, zPendopo );
  glVertex3f(-xPendopo*0.5,  -yPendopo, -0.3);
  glEnd();
 
 
}

void second_atap(){
	//FRONT
	glBindTexture(GL_TEXTURE_2D,texRoof);
	glBegin(GL_POLYGON);
	glColor3f(   6.0,  3.0,  2.0 );
	glTexCoord2f(1,0);
	glVertex3f(  xPendopo, yPendopo, -0.6 );
	glTexCoord2f(1,1);
	glVertex3f(  xPendopo*0.5, yPendopo+1, -0.3 );
	glTexCoord2f(0,1); 
	glVertex3f( -xPendopo*0.5, yPendopo+1, -0.3 );
	glTexCoord2f(0,0);
	glVertex3f( -xPendopo, yPendopo, -0.6 );
	glEnd();
	
	//BACK
	glBindTexture(GL_TEXTURE_2D,texRoof);
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0,  1.0 );
	glTexCoord2f(1,0);
	glVertex3f(  xPendopo, yPendopo,  zLantai );
	glTexCoord2f(1,1);
	glVertex3f(  xPendopo*0.5, yPendopo+1,  zPendopo );
	glTexCoord2f(0,1);
	glVertex3f( -xPendopo*0.5, yPendopo+1,  zPendopo );
	glTexCoord2f(0,0);
	glVertex3f( -xPendopo, yPendopo,  zLantai );
	glEnd();
	
	// TOP
	glBindTexture(GL_TEXTURE_2D,texRoof);
	glBegin(GL_POLYGON);
	
  glColor3f(   0.0,  3.0,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f(  xPendopo*0.5, yPendopo+1, -0.3 );
  glTexCoord2f(1,1);
  glVertex3f(  xPendopo*0.5, yPendopo+1,  zPendopo );
  glTexCoord2f(0,1);
  glVertex3f( -xPendopo*0.5, yPendopo+1,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f( -xPendopo*0.5, yPendopo+1, -0.3 );
  glEnd();
  
  // White side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  6.0,  2.0 );
  glVertex3f(  xPendopo, yPendopo, -0.6 );
  glVertex3f(  xPendopo, yPendopo,  zLantai );
  glVertex3f( -xPendopo, yPendopo,  zLantai );
  glVertex3f( -xPendopo, yPendopo, -0.6 );
  glEnd();
  
  //KANAN
  glBindTexture(GL_TEXTURE_2D,texRoof);
  glBegin(GL_POLYGON);
  glColor3f(   6.0,  1.0,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f( -xPendopo, yPendopo, -0.6 );
  glTexCoord2f(1,1);
  glVertex3f( -xPendopo*0.5, yPendopo+1, -0.3 );
  glTexCoord2f(0,1);
  glVertex3f( -xPendopo*0.5, yPendopo+1,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f( -xPendopo, yPendopo,  zLantai );
  glEnd();
  
  //KIRI
  glBindTexture(GL_TEXTURE_2D,texRoof);
  glBegin(GL_POLYGON);
  glColor3f(   6.0,  1.0,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f(  xPendopo, yPendopo, -0.6 );
  glTexCoord2f(1,1);
  glVertex3f(  xPendopo*0.5, yPendopo+1, -0.3 );
  glTexCoord2f(0,1);
  glVertex3f(  xPendopo*0.5, yPendopo+1,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f(  xPendopo, yPendopo,  zLantai );
  glEnd();
}

void lantai(){
	zLantai = xLantai;
	glBegin(GL_POLYGON);
	glColor3f( 3.0, 4.0, 0.0 );
  	glVertex3f(  xLantai, -yLantai, -0.5 );  
  	glVertex3f(  xLantai,  yLantai, -0.5 );
  	glVertex3f( -xLantai,  yLantai, -0.5 );
  	glVertex3f( -xLantai, -yLantai, -0.5 );      
 
  	glEnd();
 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  xLantai, -yLantai, zLantai );
  glVertex3f(  xLantai,  yLantai, zLantai );
  glVertex3f( -xLantai,  yLantai, zLantai );
  glVertex3f( -xLantai, -yLantai, zLantai );
  glEnd();
 
//   Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( xLantai, -yLantai, -0.5 );
  glVertex3f( xLantai,  yLantai, -0.5 );
  glVertex3f( xLantai,  yLantai,  zLantai );
  glVertex3f( xLantai, -yLantai,  zLantai );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -xLantai, -yLantai,  zLantai );
  glVertex3f( -xLantai,  yLantai,  zLantai );
  glVertex3f( -xLantai,  yLantai, -0.5 );
  glVertex3f( -xLantai, -yLantai, -0.5 );
  glEnd();
 
  // Blue side - TOP
  glBindTexture(GL_TEXTURE_2D,texFloor);
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );
  glTexCoord2f(7,0);
  glVertex3f(  xLantai,  yLantai,  zLantai );
  glTexCoord2f(7,7);
  glVertex3f(  xLantai,  yLantai, -0.5 );
  glTexCoord2f(0,7);
  glVertex3f( -xLantai,  yLantai, -0.5 );
  glTexCoord2f(0,0);
  glVertex3f( -xLantai,  yLantai,  zLantai );
  glEnd();
 
  // Red side - BOTTOM
  glBindTexture(GL_TEXTURE_2D,0);
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  xLantai, -yLantai, -0.5 );
  glVertex3f(  xLantai, -yLantai,  zLantai );
  glVertex3f( -xLantai, -yLantai,  zLantai );
  glVertex3f( -xLantai, -yLantai, -0.5 );
  glEnd();
}

void atap(){
	
	//FRONT
	glBindTexture(GL_TEXTURE_2D,texRoof);
	glBegin(GL_POLYGON);
	glColor3f(   6.0,  3.0,  2.0 );
	glTexCoord2f(1,0);
	glVertex3f(  xLantai, yPendopo, -0.6 );
	glTexCoord2f(1,1);
	glVertex3f(  xPendopo, yPendopo+0.7, -0.3 ); 
	glTexCoord2f(0,1);
	glVertex3f( -xPendopo, yPendopo+0.7, -0.3 );
	glTexCoord2f(0,0);
	glVertex3f( -xLantai, yPendopo, -0.6 );
	glEnd();
	
	//BACK
	glBindTexture(GL_TEXTURE_2D,texRoof);
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0,  1.0 );
	glTexCoord2f(1,0);
	glVertex3f(  xLantai, yPendopo,  zLantai );
	glTexCoord2f(1,1);
	glVertex3f(  xPendopo, yPendopo+0.7,  zPendopo );
	glTexCoord2f(0,1);
	glVertex3f( -xPendopo, yPendopo+0.7,  zPendopo );
	glTexCoord2f(0,0);
	glVertex3f( -xLantai, yPendopo,  zLantai );
	glEnd();
	
	// TOP
	glBegin(GL_POLYGON);
	glBindTexture(GL_TEXTURE_2D,0);
  glColor3f(   0.0,  3.0,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f(  xPendopo, yPendopo+0.7, -0.3 );
  glTexCoord2f(1,1);
  glVertex3f(  xPendopo, yPendopo+0.7,  zPendopo );
  glTexCoord2f(0,1);
  glVertex3f( -xPendopo, yPendopo+0.7,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f( -xPendopo, yPendopo+0.7, -0.3 );
  glEnd();
  
  // White side - BOTTOM
  glBegin(GL_POLYGON);
  glBindTexture(GL_TEXTURE_2D,0);
  glColor3f(   0.0,  6.0,  2.0 );
  glVertex3f(  xLantai, yPendopo, -0.6 );
  glVertex3f(  xLantai, yPendopo,  zLantai );
  glVertex3f( -xLantai, yPendopo,  zLantai );
  glVertex3f( -xLantai, yPendopo, -0.6 );
  glEnd();
  
  //KANAN
  glBegin(GL_POLYGON);
  glBindTexture(GL_TEXTURE_2D,texRoof);
  glColor3f(   6.0,  1.0,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f( -xLantai, yPendopo, -0.6 );
  glTexCoord2f(1,1);
  glVertex3f( -xPendopo, yPendopo+0.7, -0.3 );
  glTexCoord2f(0,1);
  glVertex3f( -xPendopo, yPendopo+0.7,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f( -xLantai, yPendopo,  zLantai );
  glEnd();
  
  //KIRI
  glBegin(GL_POLYGON);
  glBindTexture(GL_TEXTURE_2D,texRoof);
  glColor3f(   6.0,  1.0,  2.0 );
  glTexCoord2f(1,0);
  glVertex3f(  xLantai, yPendopo, -0.6 );
  glTexCoord2f(1,1);
  glVertex3f(  xPendopo, yPendopo+0.7, -0.3 );
  glTexCoord2f(0,1);
  glVertex3f(  xPendopo, yPendopo+0.7,  zPendopo );
  glTexCoord2f(0,0);
  glVertex3f(  xLantai, yPendopo,  zLantai );
  glEnd();
  
  glBindTexture(GL_TEXTURE_2D,0);
} 

void tangga(){
	glPushMatrix();
	glTranslatef(0.2,0.0,-0.45);
	glBegin(GL_QUADS);
	glColor3f( 3.0, 4.0, 0.0 );     
  glVertex3f(  0.4, -0.1, -0.1 );      
  glVertex3f(  0.4,  0.1, -0.1 );      
  glVertex3f( -0.4,  0.1, -0.1 );      
  glVertex3f( -0.4, -0.1, -0.1 );      
 
  glEnd();
 
  // White side - BACK
  glBegin(GL_QUADS);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.4, -0.1, 0.05 );
  glVertex3f(  0.4,  0.1, 0.05);
  glVertex3f( -0.4,  0.1, 0.05 );
  glVertex3f( -0.4, -0.1, 0.05);
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_QUADS);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.4, -0.1, -0.1 );
  glVertex3f( 0.4,  0.1, -0.1 );
  glVertex3f( 0.4,  0.1,  0.05);
  glVertex3f( 0.4, -0.1,  0.05);
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_QUADS);
  glColor3f(   0.0,  1.0,  0.0 );
  glVertex3f( -0.4, -0.1,  0.05 );
  glVertex3f( -0.4,  0.1,  0.05);
  glVertex3f( -0.4,  0.1, -0.1 );
  glVertex3f( -0.4, -0.1, -0.1 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_QUADS);
  glColor3f(   3.0,  0.0,  1.0 );
  glVertex3f(  0.4,  0.1,  0.05 );
  glVertex3f(  0.4,  0.1, -0.1 );
  glVertex3f( -0.4,  0.1, -0.1 );
  glVertex3f( -0.4,  0.1,  0.05);
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_QUADS);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.4, -0.1, -0.1 );
  glVertex3f(  0.4, -0.1,  0.05);
  glVertex3f( -0.4, -0.1,  0.05);
  glVertex3f( -0.4, -0.1, -0.1 );
  glEnd();
	glPopMatrix();
}

void pilar(){
	glBindTexture(GL_TEXTURE_2D,texPilar);
	glBegin(GL_QUADS);
	glColor3f( 1.0, 1.0, 5.0 );   
	glTexCoord2f(3,0);  
  glVertex3f(  xPilar, -0.1, -zPilar);
  glTexCoord2f(3,3);     
  glVertex3f(  xPilar,  yPendopo, -zPilar);
  glTexCoord2f(0,3);    
  glVertex3f( -xPilar,  yPendopo, -zPilar);
  glTexCoord2f(0,0);    
  glVertex3f( -xPilar, -0.1, -zPilar);      
 
  glEnd();
 
  // White side - BACK
  glBindTexture(GL_TEXTURE_2D,texPilar);
  glBegin(GL_QUADS);
  glColor3f(   1.0,  1.0, 1.0 );
  glTexCoord2f(3,0);  
  glVertex3f(  xPilar, -0.1, zPilar);
  glTexCoord2f(3,3);  
  glVertex3f(  xPilar,  yPendopo, zPilar);
  glTexCoord2f(0,3);  
  glVertex3f( -xPilar,  yPendopo, zPilar);
  glTexCoord2f(0,0);  
  glVertex3f( -xPilar, -0.1, zPilar);
  glEnd();
 
  // Purple side - RIGHT
  glBindTexture(GL_TEXTURE_2D,texPilar);
  glBegin(GL_QUADS);
  glColor3f(  4.0,  0.0,  0.0 );
  glTexCoord2f(3,0);  
  glVertex3f( xPilar, -0.1, -zPilar);
  glTexCoord2f(3,3);  
  glVertex3f( xPilar,  yPendopo, -zPilar);
  glTexCoord2f(0,3);  
  glVertex3f( xPilar,  yPendopo,  zPilar);
  glTexCoord2f(0,0);  
  glVertex3f( xPilar, -0.1,  zPilar);
  glEnd();
 
  // Green side - LEFT
  glBindTexture(GL_TEXTURE_2D,texPilar);
  glBegin(GL_QUADS);
  glColor3f(   0.0,  1.0,  5.0 );
  glTexCoord2f(3,0);
  glVertex3f( -xPilar, -0.1,  zPilar);
  glTexCoord2f(3,3);  
  glVertex3f( -xPilar,  yPendopo,  zPilar);
  glTexCoord2f(0,3);
  glVertex3f( -xPilar,  yPendopo, -zPilar);
  glTexCoord2f(0,0);
  glVertex3f( -xPilar, -0.1, -zPilar);
  glEnd();
 
  // Blue side - TOP
  glBindTexture(GL_TEXTURE_2D,texPilar);
  glBegin(GL_QUADS);
  glColor3f(   0.0,  0.0,  1.0 );
  glTexCoord2f(3,0);
  glVertex3f( xPilar,  yPendopo, -zPilar);
  glTexCoord2f(3,3);
  glVertex3f( xPilar,  yPendopo,  zPilar);
  glTexCoord2f(0,3);
  glVertex3f( -xPilar,  yPendopo,  zPilar);
  glTexCoord2f(0,0);
  glVertex3f( -xPilar,  yPendopo, -zPilar);
  glEnd();
 
  // Red side - BOTTOM
  glBindTexture(GL_TEXTURE_2D,0);
  glBegin(GL_QUADS);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f( xPilar, -0.1, -zPilar);
  glVertex3f( xPilar, -0.1,  zPilar);
  glVertex3f( -xPilar, -0.1,  zPilar);
  glVertex3f( -xPilar, -0.1, -zPilar);
  glEnd();
}

void atap_pilar(){
	
	zAtapPilar = -zPendopo/2;
	//Atap Utama
	glPushMatrix();
	glTranslatef((xPendopo/10)-0.1,yPendopo*2.5,zAtapPilar);
	glScalef(10.0,0.2,18.0);
	pilar();
	glPopMatrix();
	
	//Samping Kanan
	glPushMatrix();
	glTranslatef(-xPendopo/4.2,yPendopo*2.5,zAtapPilar);
	glScalef(3.0,0.2,1.0);
	pilar();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-xPendopo/4.2,yPendopo*2.5,zAtapPilar-0.5);
	glScalef(3.0,0.2,1.0);
	pilar();
	glPopMatrix();
	
	//Samping kiri
	glPushMatrix();
	glTranslatef(xPendopo/3,yPendopo*2.5,zAtapPilar);
	glScalef(3.0,0.2,1.0);
	pilar();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(xPendopo/3,yPendopo*2.5,zAtapPilar-0.5);
	glScalef(3.0,0.2,1.0);
	pilar();
	glPopMatrix();
}

void pilar_pendopo(){
	//Pilar Pendopo Depan
	float j=0,i=0,k=0,l=0;
	for(i=0;i<3;i++){
		glPushMatrix();
		glScalef(1.3,1.8,0.5);
		glTranslated(j+(xPendopo/6)+0.14,0.16,-0.4);
		pilar();
		glPopMatrix();
		j = j+(xPendopo/6)+0.2;
	}
	
	for(k=0;k<3;k++){
		glPushMatrix();
		glScalef(1.3,2,0.5);
		glTranslated(l+(-xPendopo/6),0.16,-0.4);
		pilar();
		glPopMatrix();
		l = l-(xPendopo/6)-0.27;
	}

//Pendopo Kiri

	i=0,j=0,k=0,l=0;
	for(i=0;i<3;i++){
		glPushMatrix();
		glScalef(0.5,2,1);
		glTranslatef(xPendopo*2,0.16,zPendopo+j-0.05);
		pilar();
		glPopMatrix();
		j = j-(zPendopo/6);
	}
	
	for(k=0;k<3;k++){
		glPushMatrix();
		glScalef(0.5,2,1);
		glTranslatef(xPendopo*2,0.16,-(zPendopo/2)+l+1.05);
		pilar();
		glPopMatrix();
		l = l+(zPendopo/6);
	}
	
//Pendopo Kanan
	i=0,j=0,k=0,l=0;
	for(i=0;i<3;i++){
		glPushMatrix();
		glScalef(0.5,2,1);
		glTranslatef(-xPendopo*2,0.16,zPendopo+j-0.05);
		pilar();
		glPopMatrix();
		j = j-(zPendopo/6);
	}
	
	for(k=0;k<3;k++){
		glPushMatrix();
		glScalef(0.5,2,1);
		glTranslatef(-xPendopo*2,0.16,-(zPendopo/2)+l+1.05);
		pilar();
		glPopMatrix();
		l = l+(zPendopo/6);
	}
}

void all_pilar(){
	atap_pilar();
	pilar_pendopo();
	
	glPushMatrix();
	glScalef(1,2,1);
	glTranslatef((xPendopo/3)+0.2,yPendopo*0.35,zAtapPilar);
	pilar();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(1,2,1);
	glTranslatef((xPendopo/3)+0.2,yPendopo*0.35,zAtapPilar-0.5);
	pilar();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(1,2,1);
	glTranslatef(-(xPendopo/2.5)+0.2,yPendopo*0.35,zAtapPilar);
	pilar();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(1,2,1);
	glTranslatef(-(xPendopo/2.5)+0.2,yPendopo*0.35,zAtapPilar-0.5);
	pilar();
	glPopMatrix();
	
	
}

void readFile(){
	static int counter=1;
	static double tmpScale1, tmpScale2;
	char c;
	char content[5000];
	int i=0;
	
	FILE *fPendopo = fopen("pendopo.json","r");
	if (fPendopo != NULL){
		while ((c = fgetc(fPendopo)) != EOF) {
			content[i] = c;
			i++;
		}
	}
	
	content[i] = '\0';
	printf("%s",content);
	
	objPendopo = cJSON_Parse(content);
	if (counter == 1){
		printf("First Read\n");
		tmpScale1 = cJSON_GetObjectItem(objPendopo, "scale")->valuedouble;
		tmpScale2 = cJSON_GetObjectItem(objPendopo, "scale")->valuedouble;
		scale = tmpScale1;
		counter++;
	} else{
		tmpScale1 = cJSON_GetObjectItem(objPendopo, "scale")->valuedouble;
		printf("tmpScale : %lf\n",tmpScale1);
			printf("tmpScale2 : %lf\n",tmpScale2);
		if (tmpScale1 != tmpScale2){
			scale = tmpScale1;
			tmpScale2 = tmpScale1;
		}
	}
	printf("Zoom = %lf\n",scale);
	
    double xPendopo = cJSON_GetObjectItem(objPendopo, "xLantai")->valuedouble;
    yPendopo = cJSON_GetObjectItem(objPendopo, "yPendopo")->valuedouble; 
    xLantai = xPendopo;
    printf("%lf %lf",scale,xPendopo);
    
    fclose(fPendopo);
}

void loadTexture(){

 	readFile();
 	texRoof = SOIL_load_OGL_texture
	(
		cJSON_GetObjectItem(objPendopo, "atap")->valuestring,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
 	
 	texFloor = SOIL_load_OGL_texture
	(
		cJSON_GetObjectItem(objPendopo, "lantai")->valuestring,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	texWall = SOIL_load_OGL_texture
	(
		cJSON_GetObjectItem(objPendopo, "tembok")->valuestring,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	texPilar = SOIL_load_OGL_texture
	(
		cJSON_GetObjectItem(objPendopo, "pilar")->valuestring,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
 	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
 	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
 	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
 	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
 	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}


void display(){
 
  //  Clear screen and Z-buffer
  readFile();
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
  gluLookAt(0.0,0,-5.0,0.0,0.0,0.0,0.0,1.0,0.0);
  // Other Transformations
  // glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 0.5, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 0.5, 0.0 );
  glScalef(scale,scale,scale);
 
  //Lantai 
  glBindTexture(GL_TEXTURE_2D,0);
  lantai();
  
  all_pilar();
  
  //bangunan pendopo
  glPushMatrix();
  glTranslatef(0.0,yLantai*3,0.0);
  bangunan_utama();
  glPopMatrix();
  
  //atap
  glPushMatrix();
  glScalef(1.0,0.3,1.0);
  glTranslatef(0.0,(yLantai*3)+2.4,0.0);
  bangunan_utama();
  atap();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(0.8,0.4,0.85);
  glTranslatef(0.0,(yLantai*3)+2.15,0.2);
  atap();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(0.85,0.7,0.7);
  glTranslatef(0.0,(yLantai*3)+1.3,0.47);
  second_atap();
  glPopMatrix();
  
  glPushMatrix();
  glScalef(0.85,0.7,0.7);
  glTranslatef(0.0,(yLantai*3)+2.91,0.47);
  rooftop();
  glPopMatrix();
  
  glFlush();
  glutSwapBuffers();
 
}


// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 1;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 1;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 1;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 1;
    
    else if(key == GLUT_KEY_PAGE_UP){
    	scale+=0.1;
  	printf("Key = %lf\n",scale);
	} 
  else if(key == GLUT_KEY_PAGE_DOWN)
  	scale-=0.1;
  	
  	else if(key == GLUT_KEY_F5)
  	loadTexture();
 
  //  Request display update
  glutPostRedisplay();
 
}

void key(unsigned char key, int x, int y){
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


//initiate
void initGlutWindow(){
 	glutInitWindowSize(SCREEN_WIDTH,SCREEN_HEIGHT);
 	glutInitWindowPosition(0,0);
 	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Awesome Cube");
 }
 
// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
  initGlutWindow();
  glutReshapeFunc(reshape);
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
//  readFile();
  loadTexture();
  // Callback functions
  glutDisplayFunc(display);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
