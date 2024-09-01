#include "../Include/Entities/Characters/Player.h"
#include "../Include/Entities/Projectiles/Projectile.h"
using namespace Entities;
using namespace Projectiles;

Projectile::Projectile(const unsigned int dmg, const bool unstop, sf::Vector2f size) : Entity(size, bID::projectile),
	damage(dmg),
	unstopable(unstop)
{
	grounded = true;
}

Projectile::~Projectile()
{

}

void Projectile::Collide(Obstacles::Obstacle* pObstacle)
{
	setActive(false);
}