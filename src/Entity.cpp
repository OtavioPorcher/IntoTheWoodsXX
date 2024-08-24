#include "..\Include\Entities\Entity.h"
using namespace Entities;

Entity::Entity(sf::Vector2f size, bID id_) : Being(id_),
	active(true),
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

void Entity::updateDeltaTime(const float dt)
{
	deltaTime = dt;
}

float Entity::deltaTime(0);