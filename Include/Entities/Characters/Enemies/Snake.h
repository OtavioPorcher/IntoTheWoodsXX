#pragma once

#include "Enemy.h"

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
				Player* pPlayer1;
				Player* pPlayer2;
				float atkCDTimer;
			public:
				Snake(Player* pP1, Player* pP2);
				~Snake();

				void Shot();
				void Move();
				void Update();
				void Draw();
			};
		}
	}
}