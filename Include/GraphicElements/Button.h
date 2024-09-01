#pragma once

#include "..\Being.h"
#include <string>

namespace Menus
{
	class Button : public Being
	{
	private:
		sf::Vector2f pos;
		sf::Text text;
		sf::Font font;
	public:
		Button(sf::Vector2f position, unsigned int pt, std::string txt);
		Button(sf::Vector2f position);
		~Button();

		void setText(std::string txt);

		void hovering(const bool a);

		void Draw();
		void Update();
	};
}