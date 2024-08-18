#include "..\Include\Entities\Characters\Enemies\Enemy.h"
#include "..\Include\Entities\Characters\Player.h"

using namespace Entities;
using namespace Characters;

Enemies::Enemy::Enemy(sf::Vector2f position, sf::Vector2f size, int life, Entities::Characters::Player* pP):
	Character(size)
{

}

Enemies::Enemy::~Enemy()
{
	pPlayer = nullptr;
}
