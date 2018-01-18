#ifndef  __COLOR_H__
#define  __COLOR_H__

#define DEFAULT_COLOR insColor(1.0, 1.0, 1.0)

typedef struct Color{
	float r;
	float g;
	float b;
} Color;

Color insColor(float r, float g, float b);

#endif
