#include "..\Include\Entities\Obstacles\Trap.h"
using namespace Entities;
using namespace Obstacles;

#include "..\Include\Entities\Characters\Player.h"

Trap::Trap(sf::Vector2f position, unsigned int dmg) : Obstacle(false, bID::trap, {20.f,50.f}),
	sharpness(dmg)
{
	pos = position;
}

Trap::~Trap()
{

}

const bool Trap::Collide(Characters::Player* pPlayer)
{
	pPlayer->sufferDMG(sharpness);
	setActive(false);
	return solid;
}

void Trap::Update()
{

}