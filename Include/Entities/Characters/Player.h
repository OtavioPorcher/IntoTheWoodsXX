#pragma once

#include "SFML/Graphics.hpp"
#include "..\Entities\Characters\Character.h"
namespace Entities
{
	namespace Characters 
	{
		class Player:public Character
		{
		public:
			Player(sf::Vector2f size = { 50.0f,50.0f }, sf::Vector2f vel = { 0.1f, 0.1f });
			~Player();
			
			void move();
		};
	}

}