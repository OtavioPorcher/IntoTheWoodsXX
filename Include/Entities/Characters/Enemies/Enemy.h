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
			protected:
				float atkCdTimer;
			public:
				Enemy(sf::Vector2f size, bID id_);
				~Enemy();

				virtual void Move() = 0;
				virtual void Update() = 0;
				virtual void Draw() = 0;

				virtual void attack(Player* pPlayer) = 0;
				virtual void sufferDMG();
			};

		}

	}

}