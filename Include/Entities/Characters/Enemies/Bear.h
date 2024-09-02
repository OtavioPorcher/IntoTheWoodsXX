#pragma once

#include "Enemy.h"

namespace Levels { class Dawn; }

namespace Entities
{
	namespace Characters
	{
			namespace Enemies
			{
				class Bear : public Enemy
				{
				private:
					float timerRockCD;

					Levels::Dawn* pLevel;
				public:
					Bear(Levels::Dawn* pL, sf::Vector2f position);
					~Bear();

					const float getDistance(Player* pPlayer);

					void Move();
					void Update();
					void Draw();

					void save();

					void throwRock();
					
					void attack(Player* pPlayer);
					void sufferDMG();
				};
			}
	}
}
