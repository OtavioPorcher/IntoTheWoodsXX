#pragma once

#include "..\Being.h"

namespace Entities
{
	class Entity : public Being
	{
	protected:
		sf::Vector2f size;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::RectangleShape body;

	public:
		Entity(sf::Vector2f size = { 50.0f,50.0f });
		~Entity();

		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Move() = 0;
		virtual void setGrounded(bool a) = 0;

		void Gravity();

		const sf::RectangleShape* getBody();
	};
}