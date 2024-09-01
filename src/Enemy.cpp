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
	if (lives <= 0)
	{
		setActive(false);
		Player::Score(getId());
	}
}

void Enemy::setPlayers(Player* pP1, Player* pP2)
{
	pPlayer1 = pP1;
	pPlayer2 = pP2;
}

Player* Enemy::pPlayer1(NULL);
Player* Enemy::pPlayer2(NULL);