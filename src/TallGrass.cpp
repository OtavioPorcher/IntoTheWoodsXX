#include "..\Include\Entities\Obstacles\TallGrass.h"
using namespace Entities;
using namespace Obstacles;

#include "..\Include\Entities\Characters\Player.h"

TallGrass::TallGrass(sf::Vector2f position, float slow) : Obstacle(false, bID::grass, {50.f,25.f}),
	speedRedution(slow)
{
	body.setFillColor(sf::Color::White);
	pos.x = position.x;
	pos.y = position.y + 25.f;
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