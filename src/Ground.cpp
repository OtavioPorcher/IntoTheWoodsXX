#include "..\Include\Entities\Obstacles\Ground.h"
using namespace Entities;
using namespace Obstacles;

Ground::Ground(sf::Vector2f position):
	Obstacle(true, bID::ground)
{
	pos = position;
	body.setFillColor(sf::Color(4, 82, 12));
}
Ground::~Ground()
{
}

void Ground::Move()
{
	pos += vel * deltaTime;
}

void Ground::Update()
{
	Gravity();
	ThrustForce();
	Move();
	body.setPosition(pos);
}

void Ground::Draw()
{
	pGM->render(&body);
}

void Ground::save()
{

}

