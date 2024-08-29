#pragma once

#include "Character.h"

#include "Enemies\Enemy.h"
#include "..\Obstacles\Obstacle.h"
//Projetil

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
	
			float velMultiplier;
			float maxVelocity;

			bool MovingLeft;
			bool MovingRight;
			bool Falling;
			bool Blocking;

			bool attacking;
			float atkDurationTimer;
			float atkCDTimer;
		public:
			Player(sf::Vector2f position);
			~Player();
			
			void Move();
			void Jump(bool forced = false);
			void MoveRight(const bool b);
			void MoveLeft(const bool b);
			void Fall();
			void Block(bool b);

			void Update();
			void Draw();

			const unsigned char getPlayerId()const;

			static void Score(bID id_);

			void setGrounded(bool a);

			void attack(bool a);
			void attack();
			void sufferDMG(int damage = 1, bool unstoppable = false);

			void setVelMultiplier(const float mult);

			void Collision(Enemies::Enemy* pE, bool xAxis, bool positiveTrajectory);
			void Collision(Obstacles::Obstacle* pO, bool xAxis, bool positiveTrajectory);
			//void Collision(Projectiles::Projectile, bool xAxis, bool positiveTrajectory);
		};
	}

}