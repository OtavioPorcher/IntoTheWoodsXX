#include "..\Include\Entities\Obstacles\TallGrass.h"
using namespace Entities;
using namespace Obstacles;

#include "..\Include\Entities\Characters\Player.h"

TallGrass::TallGrass(sf::Vector2f position, float slow) : Obstacle(false, bID::grass, {50.f,20.f}),
	speedRedution(slow)
{
	body.setFillColor(sf::Color::White);
	pos = position;
}

TallGrass::~TallGrass()
{

}

void TallGrass::Update()
{
	Gravity();
	ThrustForce();
	Move();
	body.setPosition(pos);
}

void TallGrass::updateVelMultiplier(Characters::Player* pPlayer)
{
	pPlayer->setVelMultiplier(speedRedution);
}