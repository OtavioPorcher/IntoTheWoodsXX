#pragma once

#include "Obstacle.h"

#include "..\..\Levels\Evening.h"
using namespace Levels;

namespace Entities
{
	namespace Obstacles
	{
		class Nest : public Obstacle
		{
		private:
			Evening* pLevel; 
			
			float internalclock; // Cooldown after collision
			bool activated;
		public:
			Nest(Evening* pL, sf::Vector2f position);
			~Nest();

			const bool Collide(Characters::Player* pPlayer);

			void Update();
		};
	}
}