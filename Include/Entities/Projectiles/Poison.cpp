#include "Poison.h"
using namespace Entities;
using namespace Projectiles;

Poison::Poison(sf::Vector2f velocity, sf::Vector2f position) : Projectile(1, false, {5.f,5.f}),
	detonated(false)
{
	pos = position;
	vel = velocity;
}

Poison::~Poison()
{

}

void Poison::Update()
{
	Move();
	Gravity();
	ThrustForce();

	body.setPosition(pos);
	body.setSize(size);

	if (detonated)
		setActive(false);
}

void Poison::Move()
{
	pos += vel * deltaTime;
}

void Poison::Draw()
{
	pGM->render(&body);
}

void Poison::Collide(Characters::Player* pPlayer)
{
	if (!detonated)
	{
		detonated = true;
		size *= 10.f;
		return;
	}
	pPlayer->sufferDMG();
}
