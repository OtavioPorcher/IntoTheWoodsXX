#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

Nest::Nest(Evening* pL, sf::Vector2f position): Obstacle(bID::nest),
	pLevel(pL),
	internalclock(0.f),
	activated(false)
{
	pos = position;
	body.setFillColor(sf::Color::Yellow);
}

Nest::~Nest()
{

}

void Nest::Activate()
{
	if (!activated)
	{
		activated = true;
		return;
	}
	internalclock += deltaTime;
	if (internalclock >= 0.6f)
	{
		pLevel->CreateScorpion({ pos.x,pos.y - size.y });
		pLevel->CreateGround(pos);
		setActive(false);
	}
}

void Nest::Move()
{
	pos += vel * deltaTime;
}

void Nest::Update()
{
	body.setPosition(pos);

	if (activated)
		Activate();

	Gravity();
	ThrustForce();
}

void Nest::Draw()
{
	pGM->render(&body);
}