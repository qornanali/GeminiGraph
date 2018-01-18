#ifndef  __COORD_H__
#define  __COORD_H__

#define DEFAULT_COORD insCoord(0.0, 0.0, 0.0)

typedef struct Coord{
	float x;
	float y;
	float z;
} Coord;

Coord insCoord(float x, float y, float z);

#endif
