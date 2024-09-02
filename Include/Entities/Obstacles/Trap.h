#pragma once

#include "Obstacle.h"

namespace Entities
{
	namespace Obstacles
	{

		class Trap : public Obstacle
		{
		private:
			unsigned int sharpness;
		public:
			Trap(sf::Vector2f position, const unsigned int dmg = 1);
			~Trap();

			const bool Collide(Characters::Player* pPlayer);

			void Update();

			void save();
		};
	}
}
