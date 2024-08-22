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
	Entities::Characters::Player* aux = new Entities::Characters::Player();
}

void Level::CreateGround()
{
	Entities::Obstacles::Ground* aux = new Entities::Obstacles::Ground();
}
