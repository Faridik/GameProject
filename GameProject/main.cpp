#include "Project.h"

int SDL_main(int argc, char *argv[])
{
	Game game;
	return game.Execute(new Screen(), "GameProject", 800, 600);
}
