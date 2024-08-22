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
				Enemy(sf::Vector2f size = { 50.0f , 50.0f }, const float atckCooldown = 1.0f);
				~Enemy();

				virtual void Move() = 0;
				virtual void Update() = 0;
				virtual void Draw() = 0;

				//virtual void initialize() = 0;
			};

		}

	}

}