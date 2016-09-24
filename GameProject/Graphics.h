#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "Project.h"

#include "Image.h"
class Image;

class Graphics
{
private:
	SDL_Renderer* renderer;
	SDL_Window* window;

public:
	Graphics(char* windowname, int width, int height);
	
	Image* NewBackground(int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	Image* NewImage(char* file);
	Image* NewTextImage(char* message, char* fontFile, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int fontSize);
	bool DrawImage(Image* img, int x, int y);
	bool DrawImage(Image* img, int x, int y, int w, int h);
	bool DrawImagePart(Image* img, int startX, int startY, int width, int height, int x, int y);
	bool DrawImagePart(Image* img, int startX, int startY, int width, int height, int x, int y, int w, int h);

	void Destroy();
	void Flip();
	void Clear();
};

#endif