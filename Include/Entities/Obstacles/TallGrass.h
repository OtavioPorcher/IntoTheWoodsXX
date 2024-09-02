#pragma once

#include "Obstacle.h"

namespace Entities
{
	namespace Obstacles
	{
		class TallGrass : public Obstacle
		{
		private:
			float speedRedution;
		public:
			TallGrass(sf::Vector2f position, float slow = 0.6);
			~TallGrass();

			void Update();

			void save(nlohmann::json& saveJson);

			void updateVelMultiplier(Characters::Player* pPlayer);
		};
	}
}