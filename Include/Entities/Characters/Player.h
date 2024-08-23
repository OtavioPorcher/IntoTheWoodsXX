#pragma once

#include "Character.h"

namespace Entities
{
	namespace Characters 
	{
		class Player : public Character
		{
		private:
			static unsigned char counter;
			const unsigned char playerId;

			unsigned int lives;
	
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

			void Update();
			void Draw();

			const unsigned char getCounter()const;
		};
	}

}