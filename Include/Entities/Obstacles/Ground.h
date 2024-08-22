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
			Ground(sf::Vector2f position = {0.f,0.f});
			~Ground();

			void Move();
			void Update();
			void Draw();
			void setGrounded(bool a);
		};
	}
}