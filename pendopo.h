#ifndef  __PENDOPO_H__
#define  __PENDOPO_H__

#define GROUND_LEVEL 0.0

//void drawWalls(float length, float width, float height);
void drawPillars(float length, float width, float height);
void drawFront(float length, float width, float height);
//void drawRoof(float length, float width, float height);
//void drawLand(float length, float width, float height);
void drawLand();
void drawSky();
void drawFloors(float length, float width, float height);
//void drawWalls();
void drawStairs();
void drawVents();
void drawGapura();
void drawRoof();
void drawRoofMid();
void drawRoofTop();
void drawRoofBot();
void drawCoreBuilding(float width, float height, float depth, unsigned int textFront, unsigned int textBack, unsigned int textRight, unsigned int textLeft, unsigned int textTop, unsigned int textBottom, float textKoor);


#endif
