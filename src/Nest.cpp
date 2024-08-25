#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

Nest::Nest(Evening* pL, sf::Vector2f position): Obstacle(bID::nest),
	pLevel(pL),
	internalclock(0.f)
{
	pos = position;
	body.setFillColor(sf::Color::Yellow);
}

Nest::~Nest()
{

}

void Nest::Activate()
{
	pLevel->CreateScorpion(pos);
	setActive(false);
}

void Nest::Move()
{
	pos += vel * deltaTime;
}

void Nest::Update()
{
	body.setPosition(pos);

	internalclock += deltaTime;
	if (internalclock >= 5.f)
		Activate();

	Gravity();
	ThrustForce();
}

void Nest::Draw()
{
	pGM->render(&body);
}