#include "..\Include\Entities\Characters\Enemies\Enemy.h"
#include "..\Include\Entities\Characters\Player.h"

Entities::Characters::Enemies::Enemy::Enemy(sf::Vector2f position, sf::Vector2f size, int life, Entities::Characters::Player* pP, const float atckCooldown)
{

}

Entities::Characters::Enemies::Enemy::~Enemy()
{
	pPlayer = nullptr;
}
