#ifndef  __COLOR_H__
#define  __COLOR_H__

#define DEFAULT_COLOR WHITE
#define WHITE insColor(1.0, 1.0, 1.0)
#define PURPLE insColor(1.0, 0.0, 1.0)
#define GREEN  insColor(0.0, 1.0, 0.0) 
#define RED insColor(1.0, 0.0, 0.0)
#define BLUE insColor(0.0, 0.0, 1.0)

typedef struct Color{
	float r;
	float g;
	float b;
} Color;

Color insColor(float r, float g, float b);

#endif
