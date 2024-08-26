#include "..\Include\Properties\PlayerProps.h"
#include "..\Include\Entities\Characters\Player.h"
using namespace Entities;
using namespace Characters;
#include <iostream>

Player::Player(sf::Vector2f position):Character({(float)SIZEX,(float)SIZEY}, bID::player),
	MovingLeft(false),
	MovingRight(false),
	Falling(false),
	Blocking(false),
	playerId(counter++)
{
	vel = { 300.f, 300.f };
	lives = LIVES;
	pos = position;
	body.setFillColor(sf::Color::Magenta);
}

Player::~Player()
{
	counter--;
}

void Player::Move()
{
	if ((MovingLeft) && (body.getPosition().x>0))
		body.move((-vel.x)*deltaTime, 0.0f);
	if ((MovingRight) && (body.getPosition().x < (960 - body.getSize().x)))
		body.move(vel.x*deltaTime, 0.0f);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (body.getPosition().y>0))
		body.move(0.0f, -vel.y*deltaTime);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (body.getPosition().y < (540 - body.getSize().y)))
		body.move(0.0f, vel.y*deltaTime);
}
void Player::Jump()
{
	if (grounded)
	{
		//vel.y = -sqrt(2.0f * GRAVITY * JUMPHEIGHT); // EQUAÇÃO DE TORRICELLI APLICADA
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

void Player::Update()
{
	//Gravity();
	//ThrustForce();
	Move();
}

void Player::Draw()
{
	pGM->render(&body);
}

const unsigned char Player::getPlayerId()const
{
	return playerId;
}

void Player::Score(bID id_)
{
	switch (id_)
	{
	case bID::scorpion:
		points += 1000;
		break;
	case bID::snake:
		points += 3000;
		break;
	case bID::bear:
		points += 20000;
		break;
	}
}

void Player::setGrounded(bool a)
{
	grounded = a;
}

unsigned char Player::counter(1);
unsigned int Player::points(0);