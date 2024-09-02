#pragma once

#include "..\Entity.h"

namespace Entities
{

	namespace Characters
	{

		class Character : public Entity
		{
		protected:
			int lives;
		public:
			Character(sf::Vector2f size, bID id_);
			virtual ~Character();

			const int getLives();
		};
	}
}