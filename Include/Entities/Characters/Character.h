#pragma once

#include "..\Entities\Entities.h"

namespace Entities
{

	namespace Characters
	{

		class Character
		{
		protected:
			sf::RectangleShape body;
			sf::Vector2f vel;
		public:
			Character(sf::Vector2f size = { 50.0f,50.0f }, sf::Vector2f vel = { 0.1f, 0.1f });
			virtual ~Character();
			virtual void move() = 0;

			const sf::RectangleShape getBody() { return body; }
		};
	}
}