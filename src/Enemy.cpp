#include "..\Include\Entities\Characters\Player.h"
#include "..\Include\Entities\Characters\Enemies\Enemy.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

Enemy::Enemy(sf::Vector2f size, bID id_, const float atckCooldown) : Character(size, id_),
	atkCd(atckCooldown)
{
	
}

Enemy::~Enemy()
{

}
