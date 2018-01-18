#ifndef  __COLOR_H__
#define  __COLOR_H__

#define WHITE insColor(255.0, 255.0, 255.0)
#define WHITE2 insColor(200.0, 204.0, 205.0)
#define WHITE3 insColor(122.0, 123.0, 125.0)
#define GRAY insColor(68, 69, 73)

typedef struct Color{
	float r;
	float g;
	float b;
} Color;

Color insColor(float r, float g, float b);

#endif
