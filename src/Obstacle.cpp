#include "..\Include\Entities\Obstacles\Obstacle.h"
#include "..\Include\Entities\Characters\Player.h"
using namespace Entities;
using namespace Obstacles;

Obstacle::Obstacle(const bool sld, bID id_, sf::Vector2f size) : Entity(size,id_),
	solid(sld)
{
	grounded = true;
}

Obstacle::~Obstacle()
{

}

void Obstacle::Move()
{
	pos += vel * deltaTime;
}

void Obstacle::Draw()
{
	pGM->render(&body);
}

const bool Obstacle::Collide(Characters::Player* pPlayer)
{
	return solid;
}

void Obstacle::updateVelMultiplier(Characters::Player* pPlayer)
{
	pPlayer->setVelMultiplier(1.f);
}