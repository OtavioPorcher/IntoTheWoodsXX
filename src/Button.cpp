#include "..\Include\GraphicElements\Button.h"
using namespace Menus;

#include <iostream>

Button::Button(sf::Vector2f position, unsigned int pt, std::string txt) : Being(bID::button),
	pos(position),
	text(txt, pGM->getFont(), pt)
{
	setText(txt);
	hovering(false);
}

Menus::Button::Button(sf::Vector2f position) :
	pos(position),
	text("", pGM->getFont(), 30)
{
	hovering(false);
}

Button::~Button()
{

}

void Button::setText(std::string txt)
{
	text.setString(txt);

	sf::FloatRect aux = text.getLocalBounds();
	text.setOrigin(aux.width / 2, aux.height / 2);

	text.setPosition(pos);
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