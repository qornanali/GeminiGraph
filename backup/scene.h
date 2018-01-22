#ifndef  __SCENE_H__
#define  __SCENE_H__

void onWorldDisplay();
void onWorldIdle();
void onWorldReshape(int w, int h); 
void onSpecialKeyClicked(int key, int x, int y ); 
void onNormalKeyClicked(unsigned char key, int x, int y);
void onMotionMouseClicked(int x, int y);
void onButtonMouseClicked(int button, int state, int x, int y);
void onPassiveMouseActived(int x, int y);

#endif
