#pragma once

#include "Obstacle.h"
namespace Entities 
{
	namespace Obstacles
	{
		class Ground : public Obstacle
		{
		private:

		public:
			Ground(sf::Vector2f position);
			~Ground();

			void Move();
			void Update();
			void Draw();
			
		};
	}
}