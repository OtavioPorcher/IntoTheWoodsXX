#include "../Include/Entities/Characters/Player.h"
#include "../Include/Entities/Projectiles/Poison.h"
using namespace Entities;
using namespace Projectiles;

Poison::Poison(sf::Vector2f targetPosition, sf::Vector2f position) : Projectile(1, false, {5.f,5.f}),
	distance(0.f)
{
	vel.x = 200.f;
	pos = position;
	body.setFillColor(sf::Color::Blue);
	setTrajectory(targetPosition);

}

Poison::~Poison()
{

}

void Poison::Update()
{
	Move();
	Gravity();
	ThrustForce();

	if (distance > 500.f)
		setActive(false);
	
	body.setPosition(pos);
	body.setSize(size);

}

void Poison::Move()
{
	pos += vel * deltaTime;
	distance += sqrtf(powf(vel.x*deltaTime, 2) + powf(vel.y*deltaTime, 2));
}

void Poison::Draw()
{
	pGM->render(&body);
}
#include <iostream>
void Poison::Collide(Characters::Player* pPlayer)
{
	pPlayer->sufferDMG();
	setActive(false);
}


void Poison::setTrajectory(sf::Vector2f targetPosition)
{
	const float distX = targetPosition.x - pos.x;	
	const float distY = targetPosition.y - pos.y;

	const float dist = sqrtf((distX * distX) + (distY * distY));
	const float airTime = dist / 300.f; // Dist dividido pela velocidade

	//const float airTime = distX / vel.x;
	vel.x = distX / airTime;
	vel.y = distY / airTime;
	//vel.y = (targetPosition.y - pos.y) / airTime + (GRAVITY * airTime / 2);
	//vel.y = (((pos.y - targetPosition.y) + (GRAVITY / 2 * airTime * airTime)) / airTime);
}