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
				float atkCd;
			public:
				Enemy(sf::Vector2f size = { 0.0f , 0.0f }, const float atckCooldown = 1.0f);
				~Enemy();

				virtual void update(const float dt) = 0;
				virtual void initialize() = 0;
			};

		}

	}

}