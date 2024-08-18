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
				Enemy(sf::Vector2f position = {0.0f , 0.0f},
					sf::Vector2f size = { 0.0f , 0.0f },
					int life = 1,
					Entities::Characters::Player * pP = NULL,
					const float atckCooldown = 1.0f);
				~Enemy();
				void setpPlayer(Entities::Characters::Player* pP);
				sf::Vector2f getPlayerPosition();
				virtual void update(const float dt) = 0;
				virtual void initialize() = 0;
			};

		}

	}

}