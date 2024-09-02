#include "..\Include\Entities\Obstacles\Trap.h"
using namespace Entities;
using namespace Obstacles;

#include "..\Include\Entities\Characters\Player.h"

Trap::Trap(sf::Vector2f position, unsigned int dmg) : Obstacle(false, bID::trap, {50.f,20.f}),
	sharpness(dmg)
{
	body.setFillColor(sf::Color(122,127,128));
	pos = position;
	pos.y += 30.f;
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
	body.setPosition(pos);
}

void Trap::save()
{

}
