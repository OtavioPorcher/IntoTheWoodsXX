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
			Ground();
			~Ground();

			void Move();
			void Draw();
		};
	}
}