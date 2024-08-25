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

			static unsigned int points;
	
			bool MovingLeft;
			bool MovingRight;
			bool Falling;
			bool Blocking;
		public:
			Player(sf::Vector2f position);
			~Player();
			
			void Move();
			void Jump();
			void MoveRight(const bool b);
			void MoveLeft(const bool b);
			void Fall();
			void Block(bool b);

			void Update();
			void Draw();

			const unsigned char getPlayerId()const;

			static void Score(bID id_);
		};
	}

}