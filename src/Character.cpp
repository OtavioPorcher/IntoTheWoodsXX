#include "..\Include\Entities\Characters\Character.h"

using namespace Entities;
using namespace Characters;

Character::Character(sf::Vector2f size, bID id_) : Entity(size, id_),
	lives(1)
{

}

Character::~Character()
{

}

const int Character::getLives()
{
	return lives;
}
