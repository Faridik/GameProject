#ifndef _INPUT_H_
#define _INPUT_H_

#include "Project.h"

class Input
{
private:
	SDL_Event evt;

public:
	void Update();

	bool IsMouseButtonDown(int key);
	bool IsMouseButtonUp(int key);
	int GetButtonDownX();
	int GetButtonDownY();

	bool IsKeyDown();
	bool IsKeyUp();
	bool IsKeyDown(int key);
	bool IsKeyUp(int key);
	int GetPressedKey();

	bool IsExit();
};

#endif