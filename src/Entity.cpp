#include "..\Include\Entities\Entity.h"

Entities::Entity::Entity(sf::Vector2f size):
	size(size),
	body(size),
	vel(0.1f,0.1f)
{

}
Entities::Entity::~Entity()
{

}