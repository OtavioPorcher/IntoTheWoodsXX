#include "..\Include\Entities\Characters\Player.h"
#include "..\Include\Entities\Characters\Enemies\Enemy.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

Enemy::Enemy(sf::Vector2f size, bID id_) : Character(size, id_),
	atkCdTimer(0.f)
{
	vel = { 300.f, 0.f };
	grounded = true;
}

Enemy::~Enemy()
{

}

void Enemy::sufferDMG()
{
	lives--;
}