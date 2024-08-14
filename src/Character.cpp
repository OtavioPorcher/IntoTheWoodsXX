#include "..\Entities\Characters\Character.h"

Entities::Characters::Character::Character(sf::Vector2f size, sf::Vector2f vel):
	body(size),
	vel(vel)
{

}

Entities::Characters::Character::~Character()
{

}