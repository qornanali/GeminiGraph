#ifndef  __TEXTURELOADER_H__
#define  __TEXTURELOADER_H__

class Image {
	public:
		Image(char* ps, int w, int h);
		~Image();
		char* pixels;
		int width;
		int height;
};

Image* loadBMP(const char* filename);

#endif
