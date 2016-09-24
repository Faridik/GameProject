#include "Game_Play.h"

void Game_Play::Start()
{
	input = game->GetInput();
	graphics = game->GetGraphics();
	background = graphics->NewBackground(400, 300, 255, 0, 0, 0);
	player = graphics->NewImage("images\\player.png");
	graphics->DrawImage(background, 0, 0, 400, 300);
	graphics->DrawImage(player, 0, 0);
	graphics->Flip();
}

void Game_Play::Update()
{
	if (input->IsExit()) game->Exit();
}

void Game_Play::Destroy()
{
	player->Destroy();
}
