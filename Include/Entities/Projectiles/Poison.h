#pragma once

#include "Projectile.h"

namespace Entities
{
	namespace Projectiles
	{
		class Poison : public Projectile
		{
		private:
			bool detonated;
		public:
			Poison(sf::Vector2f velocity, sf::Vector2f position);
			~Poison();

			void Update();
			void Move();
			void Draw();

			void Collide(Characters::Player* pPlayer);


		};
	}
}