#include "..\Include\Entities\Entity.h"

Entities::Entity::Entity(sf::Vector2f size):
	id(counter++),
	size(size),
	body(size)
{

}
Entities::Entity::~Entity()
{

}

unsigned int Entities::Entity::counter(0);