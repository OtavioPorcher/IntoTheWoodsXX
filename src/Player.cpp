#include "..\Include\Entities\Characters\Player.h"

Entities::Characters::Player::Player(sf::Vector2f size, sf::Vector2f vel):Character(size,vel)
{
	body.setFillColor(sf::Color::Magenta);
}

Entities::Characters::Player::~Player()
{

}

void Entities::Characters::Player::move()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (body.getPosition().x>0))
		body.move(-vel.x, 0.0f);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (body.getPosition().x<(960-body.getSize().x)))
		body.move(vel.x, 0.0f);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (body.getPosition().y>0))
		body.move(0.0f, -vel.y);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))&&(body.getPosition().y<(540-body.getSize().y)))
		body.move(0.0f, vel.y);
}
