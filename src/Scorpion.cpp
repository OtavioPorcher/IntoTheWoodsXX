#include <cmath>
#include "..\Include\Entities\Characters\Player.h"
#include "..\Include\Entities\Characters\Enemies\Scorpion.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

Scorpion::Scorpion(sf::Vector2f position) : Enemy({50.0f,50.0f}, bID::scorpion),
origin(position),
facingRight(true),
range(160.0f),
dist(0.0f)
{
	pos = position;
	body.setFillColor(sf::Color::Cyan);
}

Scorpion::~Scorpion()
{

}

void Scorpion::Move()
{
	if (!facingRight)
		vel.x *= -1;

	pos += vel * deltaTime;
	dist = std::fabs(pos.x - origin.x);
}

void Scorpion::Update()
{
	atkCdTimer += deltaTime;

	body.setPosition(pos);
	if (dist >= range)
		facingRight = (!facingRight);

	Gravity();
	ThrustForce();
	Move();
}

void Scorpion::Draw()
{
	pGM->render(&body);
}

void Scorpion::attack(Player* pPlayer)
{
	if (atkCdTimer > 0.8f)
	{
		pPlayer->sufferDMG();
		atkCdTimer = 0;
	}
}