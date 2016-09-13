#include "Input.h"

void Input::Update()
{
	while (SDL_PollEvent(&evt));
}

bool Input::IsMouseButtonDown(int key)
{
	if (evt.type == SDL_MOUSEBUTTONDOWN)
		if (evt.button.button == key)
			return true;
	return false;
}

bool Input::IsMouseButtonUp(int key)
{
	if (evt.type == SDL_MOUSEBUTTONUP)
		if (evt.button.button == key)
			return true;
	return false;
}

int Input::GetButtonDownX()
{
	return evt.button.x;
}

int Input::GetButtonDownY()
{
	return evt.button.y;
}

bool Input::IsKeyDown()
{
	return (evt.type == SDL_KEYDOWN);
}

bool Input::IsKeyUp()
{
	return (evt.type == SDL_KEYUP);
}

bool Input::IsKeyDown(int key)
{
	return (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == key);
}

bool Input::IsKeyUp(int key)
{
	return (evt.type == SDL_KEYUP && evt.key.keysym.sym == key);
}

int Input::GetPressedKey()
{
	return evt.key.keysym.sym;
}

bool Input::IsExit()
{
	return (evt.type == SDL_QUIT);
}