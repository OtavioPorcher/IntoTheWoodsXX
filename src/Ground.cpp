#include "..\Include\Entities\Obstacles\Ground.h"
using namespace Entities;
using namespace Obstacles;

Ground::Ground(sf::Vector2f position):
	Obstacle(bID::ground)
{
	pos = position;
	body.setFillColor(sf::Color::Green);
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

void Ground::setGrounded(bool a)
{

}