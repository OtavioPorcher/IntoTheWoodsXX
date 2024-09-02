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
				static Player* pPlayer1;
				static Player* pPlayer2;
				float atkCdTimer;
				float dmgCdTimer;
			public:
				Enemy(sf::Vector2f size, bID id_);
				~Enemy();

				virtual void attack(Player* pPlayer) = 0;
				virtual void sufferDMG();

				static void setPlayers(Player* pP1, Player* pP2);
			};

		}

	}

}