#include "..\Include\GraphicElements\Button.h"
using namespace Menus;

#include <iostream>


Button::Button(sf::Vector2f position, unsigned int pt, std::string txt) : Being(bID::button),
	pos(position)
{
	text.setPosition(pos);
	text.setFont(pGM->getFont());
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