#pragma once

#include "..\Entity.h"

namespace Entities
{

	namespace Characters
	{

		class Character : public Entity
		{
		protected:
		
		public:
			Character(sf::Vector2f size = { 50.0f,50.0f });
			virtual ~Character();
			virtual void Move() = 0;
			virtual void setGrounded(bool a) = 0;

		
		};
	}
}