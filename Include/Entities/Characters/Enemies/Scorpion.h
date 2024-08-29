#pragma once

#include "Enemy.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Scorpion : public Enemy
			{
			private:
				sf::Vector2f origin;
				bool facingRight;
				
				float range;
				float dist;

			public:
				Scorpion(sf::Vector2f position);
				~Scorpion();

				void Move();
				void Update();
				void Draw();

				void attack(Player* pPlayer);
			};
		}
	}
}
