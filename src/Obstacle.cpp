#include "..\Include\Entities\Obstacles\Obstacle.h"

using namespace Entities;
using namespace Obstacles;

Obstacle::Obstacle(bID id_) : Entity({50.0f,50.0f},id_)
{
	grounded = true;
}

Obstacle::~Obstacle()
{

}

void Obstacle::Activate()
{

}