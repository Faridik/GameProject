#ifndef _PROJECT_H_
#define _PROJECT_H_

#pragma comment(lib,"SDL2.lib")
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif defined __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif
#include "Game.h"
#include "Graphics.h"
#include "Image.h"

#include "Game_Play.h"

#endif
