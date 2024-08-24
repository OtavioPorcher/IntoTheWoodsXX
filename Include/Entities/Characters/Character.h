#pragma once

#include "..\Entity.h"

namespace Entities
{

	namespace Characters
	{

		class Character : public Entity
		{
		protected:
			unsigned int lives;
		public:
			Character(sf::Vector2f size, bID id_);
			virtual ~Character();

			virtual void Move() = 0;
			virtual void Update() = 0;
			virtual void Draw() = 0;


		};
	}
}