#include "../Include//Entities//Projectiles/Rock.h"
using namespace Entities;
using namespace Projectiles;

#include "../Include/Entities/Characters/Player.h"

Entities::Projectiles::Rock::Rock(sf::Vector2f position) : Projectile(2, true, {30.f, 30.f}),
	damage(2)
{
	body.setFillColor(sf::Color(146, 142, 133));
	pos = position;
	grounded = false;
}

Entities::Projectiles::Rock::~Rock()
{

}

void Entities::Projectiles::Rock::Update()
{
	Move();
	Gravity();
	ThrustForce();

	body.setPosition(pos);
}

void Entities::Projectiles::Rock::Move()
{
	pos += vel * deltaTime;
}

void Entities::Projectiles::Rock::Draw()
{
	pGM->render(&body);
}

void Entities::Projectiles::Rock::Collide(Characters::Player* pPlayer)
{
	pPlayer->sufferDMG(damage, true);
	setActive(false);
}
