#include "..\Include\Entities\Entity.h"
using namespace Entities;

Entity::Entity(sf::Vector2f size):
	size(size),
	body(size),
	vel(0.1f,0.1f)
{

}
Entity::~Entity()
{

}

const sf::RectangleShape* Entity::getBody()
{
	return &body;
}