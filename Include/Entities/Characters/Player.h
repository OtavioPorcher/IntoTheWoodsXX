#pragma once

#include "Entities\Characters\Character.h"

namespace Entities
{
	namespace Characters 
	{
		class Player:public Character
		{
		private:
			unsigned int lives;
			float friction;
			bool grounded;
			bool MovingLeft;
			bool MovingRight;
			bool Falling;
			bool Blocking;
		public:
			Player();
			~Player();
			
			void Move();
			void Jump();
			void MoveRight(const bool b);
			void MoveLeft(const bool b);
			void Fall();
			void Block(bool b);
			void setGrounded(bool b);
		};
	}

}