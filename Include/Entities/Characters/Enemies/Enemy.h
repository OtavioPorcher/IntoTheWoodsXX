#pragma once

#include "..\Character.h"

namespace Entities
{
	namespace Characters
	{
		class Player;
		namespace Enemies
		{
			class Enemy : public Character
			{
			private:
				Player* pPlayer;
			protected:
				float distanceEnemy;
			public:
				Enemy(Math::CoordF position = Math::CoordF(0.f, 0.f),
					Math::Coord size = Math::Coord(0.f, 0.f),
					ID id = empty,
					int life = 1
					Entities::Characters::Player * pP = NULL,
					const float atckCooldown = 1.0f);
				~Enemy();
				void setpPlayer(Entities::Character::Player* pP);
				Math::Coord getPlayerPosition();
				virtual void update(const float dt) = 0;
				virtual void initialize() = 0;
				virtual void collide(Entity* otherEntity, Math::CoordF intersect);
				virtual void updateSprite(const float dt) = 0;
			};

		}

	}

}