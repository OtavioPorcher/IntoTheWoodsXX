#include "..\Include\GraphicElements\Button.h"
using namespace Menus;

#include <iostream>


Button::Button(sf::Vector2f position, unsigned int pt, std::string txt) : Being(bID::button),
	pos(position)
{
	try { font.loadFromFile("Assets/arialbd.ttf"); }
	catch (int error)
	{
		if (!error)
		{
			std::cout << "ERROR: Unable to open font file!" << std::endl;
		}
	}
	text.setPosition(pos);
	text.setFont(font);
	text.setCharacterSize(pt);
	setText(txt);
	hovering(false);
}

Button::~Button()
{

}

void Button::setText(std::string txt)
{
	text.setString(txt);
}

void Button::hovering(const bool a)
{
	if (a)
		text.setFillColor(sf::Color::Yellow);
	else
		text.setFillColor(sf::Color::White);
}

void Button::Draw()
{
	pGM->render(&text);
}

void Button::Update()
{

}