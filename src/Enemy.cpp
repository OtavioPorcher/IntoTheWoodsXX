#include "..\Include\Entities\Characters\Enemies\Enemy.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;
#include "..\Include\Entities\Characters\Player.h"

Enemy::Enemy
(sf::Vector2f position, sf::Vector2f size, int life, Entities::Characters::Player* pP, const float atckCooldown):
	Character(size)
{

}

Enemy::~Enemy()
{
	pPlayer = nullptr;
}
