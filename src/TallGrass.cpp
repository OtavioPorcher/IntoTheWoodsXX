#include "..\Include\Entities\Obstacles\TallGrass.h"
using namespace Entities;
using namespace Obstacles;

#include "..\Include\Entities\Characters\Player.h"

TallGrass::TallGrass(sf::Vector2f position, float slow) : Obstacle(false, bID::grass, {20.f,50.f}),
	speedRedution(slow)
{

}

TallGrass::~TallGrass()
{

}

void TallGrass::Update()
{

}

void TallGrass::updateVelMultiplier(Characters::Player* pPlayer)
{
	pPlayer->setVelMultiplier(speedRedution);
}