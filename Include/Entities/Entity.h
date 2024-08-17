#pragma once

#include "..\..\SFML-2.6.1\include\SFML\Graphics.hpp"

namespace Entities
{
	class Entity
	{
	private:
		unsigned int id;
		static unsigned int counter;
	protected:
		sf::Vector2f size;
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::RectangleShape body;

	public:
		Entity(sf::Vector2f size = { 50.0f,50.0f });
		~Entity();

		virtual void Move() = 0;
		virtual void setGrounded(bool a) = 0;
		void Gravity();

		const sf::RectangleShape getBody() { return body; }
	};
}