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
				bool originSet;
				bool facingRight;
				
				float range;
				float dist;

			public:
				Scorpion();
				~Scorpion();

				void Move();
				void Update();
				void Draw();

				void setOrigin(sf::Vector2f o);
			};
		}
	}
}
