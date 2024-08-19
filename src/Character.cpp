#include "Entities\Characters\Character.h"

using namespace Entities;
using namespace Characters;

Character::Character(sf::Vector2f size) : 
	Entity(size),
	alive(true)
{

}

Character::~Character()
{

}
