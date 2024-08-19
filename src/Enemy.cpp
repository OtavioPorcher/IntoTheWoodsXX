#include "..\Include\Entities\Characters\Enemies\Enemy.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;
#include "..\Include\Entities\Characters\Player.h"

<<<<<<< HEAD
Enemy::Enemy
(sf::Vector2f position, sf::Vector2f size, int life, Entities::Characters::Player* pP, const float atckCooldown):
=======
using namespace Entities;
using namespace Characters;

Enemies::Enemy::Enemy(sf::Vector2f position, sf::Vector2f size, int life, Entities::Characters::Player* pP):
>>>>>>> d71d84066cff1a98c4cfd0457e19fac1071f1d8a
	Character(size)
{

}

<<<<<<< HEAD
Enemy::~Enemy()
=======
Enemies::Enemy::~Enemy()
>>>>>>> d71d84066cff1a98c4cfd0457e19fac1071f1d8a
{
	pPlayer = nullptr;
}
