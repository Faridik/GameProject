#include "Project.h"

int main(int argc, char *argv[])
{
    Game game;
    return game.Execute(new Game_Play(), "GameProject", 800, 600);
}