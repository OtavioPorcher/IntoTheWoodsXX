#include "..\Include\Properties\PlayerProps.h"
#include "..\Include\Entities\Characters\Player.h"
using namespace Entities;
using namespace Characters;

Player::Player():Character({(float)SIZEX,(float)SIZEY}),
	friction(0),
	lives(LIVES),
	grounded(true),
	MovingLeft(false),
	MovingRight(false),
	Falling(false),
	Blocking(false)
{
	body.setFillColor(sf::Color::Magenta);
}

Player::~Player()
{

}

void Player::Move()
{/*
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (body.getPosition().x>0))
		body.move(-vel.x, 0.0f);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (body.getPosition().x<(960-body.getSize().x)))
		body.move(vel.x, 0.0f);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (body.getPosition().y>0))
		body.move(0.0f, -vel.y);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))&&(body.getPosition().y<(540-body.getSize().y)))
		body.move(0.0f, vel.y);*/
}
void Player::Jump()
{
	if (grounded)
	{
		vel.y = 0.1f;//JUMPHEIGHT;
	}
}

void Player::MoveLeft(const bool b)
{
	MovingLeft = b;
}

void Player::MoveRight(const bool b)
{
	MovingRight = b;
}

void Player::Fall()
{
	Falling = true;
}

void Player::Block(bool b)
{
	Blocking = b;
}

void Player::setGrounded(bool b)
{

}