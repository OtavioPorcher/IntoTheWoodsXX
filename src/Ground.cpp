#define X 128.f
#define Y 128.f
#include "..\Include\Entities\Obstacles\Ground.h"

Entities::Obstacles::Ground::Ground():
	Obstacle(sf::Vector2f(X, Y))
{
	body.setFillColor(sf::Color::Green);
}
Entities::Obstacles::Ground::~Ground()
{
}

void Entities::Obstacles::Ground::Move()
{

}

void Entities::Obstacles::Ground::Update()
{
	pGM->render(&body);
}
