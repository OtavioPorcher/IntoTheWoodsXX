#pragma once

#include "Obstacle.h"

#include "..\..\Levels\Evening.h"
using namespace Levels;

namespace Entities
{
	namespace Obstacles
	{
		class Nest : public Obstacle
		{
		private:
			float internalclock; //Para teste enquanto n�o tem colis�o
			Evening* pLevel;
		public:
			Nest(Evening* pL, sf::Vector2f position);
			~Nest();

			void Activate();

			void Update();
			void Move();
			void Draw();
		};
	}
}