#pragma once

#include "Projectile.h"

namespace Entities
{
	namespace Projectiles
	{
		class Rock : public Projectile
		{
		private:
			unsigned int damage;
		public:
			Rock(sf::Vector2f position);
			~Rock();

			void Update();
			void Move();
			void Draw();

			void Collide(Characters::Player* pPlayer);
		};
	}
}