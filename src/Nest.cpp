#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

Nest::Nest(Evening* pL, sf::Vector2f position): Obstacle(true, bID::nest),
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

const bool Nest::Collide(Characters::Player* pPlayer)
{
	activated = true;
	return solid;
}

void Nest::Update()
{
	body.setPosition(pos);

	if (activated)
	{
		internalclock += deltaTime;
		if (internalclock >= 0.6f)
		{
			pLevel->CreateScorpion({ pos.x,pos.y - size.y });
			pLevel->CreateGround(pos);
			setActive(false);
		}
	}

	Gravity();
	ThrustForce();
}

void Nest::save(nlohmann::json& saveJson)
{

}
