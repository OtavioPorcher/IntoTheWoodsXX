#include "../include/Levels/Level.h"

using namespace Levels;

Level::Level(sf::Vector2f size):
	pIM(pIM),
	pPlayer(NULL)
{
}

Level::~Level()
{
}

void Level::CreatePlayer()
{
	player.Draw();
}

void Level::CreateGround()
{
	
}
