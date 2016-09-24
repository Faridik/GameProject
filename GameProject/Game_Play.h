#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#include "Project.h"

#include "Screen.h"
class Screen;
#include "Input.h"
class Input;
#include "Graphics.h"
class Graphics;
#include "Image.h"
class Image;

class Game_Play : public Screen
{
private:

	Input* input;
	Graphics* graphics;

	Image* background;
	Image* player;

public:

	void Start();
	void Update();
	void Destroy();


};



#endif // !GAME_PLAY_H
