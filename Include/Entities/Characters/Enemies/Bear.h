#pragma once

#include "Enemy.h"

namespace Entities
{
	namespace Characters
	{
			namespace Enemies
			{
				class Bear : public Enemy
				{
				private:
					float timerFightMode;

				public:
					Bear();
					~Bear();

					void Move();
					void Update();
					void Draw();
					
					void attack(Player* pPlayer);
					void sufferDMG();
				};
			}
	}
}
