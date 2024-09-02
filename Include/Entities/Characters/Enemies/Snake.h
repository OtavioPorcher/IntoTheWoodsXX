#pragma once

#include "Enemy.h"
#include "../../Projectiles/Poison.h"
#include <vector>

namespace Levels { class Level; }

namespace Entities
{
	namespace Characters
	{
		class Player;

		namespace Enemies
		{
			class Snake : public Enemy
			{
			private:
				std::vector <Projectiles::Poison*> projectileList;
				Levels::Level* pLevel;

			public:
				Snake(Levels::Level* pL, sf::Vector2f position);
				~Snake();

				void Shoot();
				const float getDistance(Player* pPlayer);

				void Move();
				void Update();
				void Draw();

				void save();

				const std::vector<Projectiles::Poison*>* getProjetileList();

				void attack(Player* pPlayer);
			};
		}
	}
}