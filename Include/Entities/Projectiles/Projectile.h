#pragma once

#include "../Entities/Entity.h"
#include "../Entities/Obstacles/Obstacle.h"

namespace Entities
{
	namespace Characters { class Player; }

	namespace Projectiles
	{
		class Projectile : public Entity
		{
		private:
			const unsigned int damage;
			const bool unstopable;
		public:
			Projectile(const unsigned int dmg, const bool unstop, sf::Vector2f size);
			virtual ~Projectile();

			virtual void Collide(Characters::Player* pPlayer) = 0;
			void Collide(Obstacles::Obstacle* pObstacle);
		};
	}
}