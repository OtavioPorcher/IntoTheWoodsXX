#pragma once

#include "Projectile.h"

namespace Entities
{
	namespace Projectiles
	{
		class Poison : public Projectile
		{
		private:
			float distance;
		public:
			Poison(sf::Vector2f targetPosition, sf::Vector2f position);
			~Poison();

			void setTrajectory(sf::Vector2f targetPosition);

			void Update();
			void Move();
			void Draw();

			void Collide(Characters::Player* pPlayer);


		};
	}
}