#pragma once

#include "..\..\SFML-2.6.1\include\SFML\Graphics.hpp"

namespace Entities
{
	class Entities
	{
	private:
		unsigned int id;
		static unsigned int counter;
	protected:
		sf::Vector2f size;
		sf::Vector2f pos;
		sf::Vector2f vel;

	public:
		Entities();
		~Entities();

		virtual void move() = 0;
	};
}