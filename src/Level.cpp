#include "../include/Levels/Level.h"

Levels::level::Level(sf::Vector2f size):
{
}

Levels::level::~Level()
{
}

void Levels::level::CreatePlayer()
{
	Entities::Obstacles::Ground* aux = new Entities::Obstacles::Ground(pos);

}

void Levels::level::CreateGround()
{
	
}
