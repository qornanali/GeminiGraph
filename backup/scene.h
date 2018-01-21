#ifndef  __SCENE_H__
#define  __SCENE_H__

#include "cJSON.h"
#include "list_string.h"
#include "list_int.h"
#include "list_double.h"

void onWorldDisplay();
void onWorldIdle();
void onWorldReshape(int w, int h); 
void onSpecialKeyClicked(int key, int x, int y ); 
void onNormalKeyClicked(unsigned char key, int x, int y);
void onMotionMouseClicked(int x, int y);
void onButtonMouseClicked(int button, int state, int x, int y);
void onPassiveMouseActived(int x, int y);

#endif
