#include "Graphics.h"

Graphics::Graphics(char* windowname, int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(windowname, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	TTF_Init();

	SDL_RenderClear(renderer);
}

Image* Graphics::NewBackground(int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Image* image = new Image();
	SDL_Rect rect;

	rect.w = w;
	rect.h = h;

	image->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
	SDL_SetRenderTarget(renderer, image->texture);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, image->texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	image->angle = 0;

	return image;
}

Image* Graphics::NewImage(char* file)
{
	Image* image = new Image();

	image->texture = IMG_LoadTexture(renderer, file);
	image->angle = 0;

	return image;
}

Image* Graphics::NewTextImage(char* message, char* fontFile, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int fontSize)
{
	TTF_Font* font = TTF_OpenFont(fontFile, fontSize);

	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;

	SDL_Surface* surf = TTF_RenderText_Blended(font, message, color);

	Image* image = new Image();
	image->texture = SDL_CreateTextureFromSurface(renderer, surf);
	image->angle = 0;

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);

	return image;
}

bool Graphics::DrawImage(Image *img, int x, int y)
{
	if (renderer == NULL || img->texture == NULL || window == NULL)
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;

	SDL_QueryTexture(img->texture, NULL, NULL, &Area.w, &Area.h);
	SDL_RenderCopyEx(renderer, img->texture, NULL, &Area, img->angle, NULL, SDL_FLIP_NONE);

	return true;
}

bool Graphics::DrawImage(Image* img, int x, int y, int w, int h)
{
	if (renderer == NULL || img->texture == NULL || window == NULL)
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;
	Area.w = w;
	Area.h = h;

	SDL_RenderCopyEx(renderer, img->texture, NULL, &Area, img->angle, NULL, SDL_FLIP_NONE);

	return true;
}

bool Graphics::DrawImagePart(Image * img, int startX, int startY, int width, int height, int x, int y)
{
	if (renderer == NULL || img->texture == NULL || window == NULL)
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;
	SDL_QueryTexture(img->texture, NULL, NULL, &Area.w, &Area.h);

	SDL_Rect AreaF;
	AreaF.x = startX;
	AreaF.y = startY;
	AreaF.w = width;
	AreaF.h = height;

	SDL_RenderCopyEx(renderer, img->texture, &AreaF, &Area, img->angle, NULL, SDL_FLIP_NONE);

	return true;
}

bool Graphics::DrawImagePart(Image * img, int startX, int startY, int width, int height, int x, int y, int w, int h)
{
	if (renderer == NULL || img->texture == NULL || window == NULL)
		return false;

	SDL_Rect Area;
	Area.x = x;
	Area.y = y;
	Area.w = w;
	Area.h = h;

	SDL_Rect AreaF;
	AreaF.x = startX;
	AreaF.y = startY;
	AreaF.w = width;
	AreaF.h = height;

	SDL_RenderCopyEx(renderer, img->texture, &AreaF, &Area, img->angle, NULL, SDL_FLIP_NONE);

	return true;
}

void Graphics::Destroy()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Graphics::Flip()
{
	SDL_RenderPresent(renderer);
}

void Graphics::Clear()
{
	SDL_RenderClear(renderer);
}
