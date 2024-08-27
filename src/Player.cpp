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
	velMultiplier(1),
	playerId(counter++),
	atkDurationTimer(0.f),
	atkCDTimer(0.f),
	attacking(false)
{
	maxVelocity = MAXVEL;
	lives = LIVES;
	pos = position;

	if (playerId == 1)
	{
		body.setFillColor(sf::Color::Magenta);
	}
	else if (playerId ==2)
	{
		body.setFillColor(sf::Color::Red);
	}
}

Player::~Player()
{
	counter--;
}

void Player::Move()
{
	maxVelocity = MAXVEL * velMultiplier;

	if (MovingLeft)
	{
		if (vel.x > -maxVelocity)
			vel.x -= ACCEL * deltaTime;
		if (vel.x < -maxVelocity)
			vel.x = -maxVelocity;
	}
	if (MovingRight)
	{
		if (vel.x < maxVelocity)
			vel.x += ACCEL * deltaTime;
		if (vel.x > maxVelocity)
			vel.x = maxVelocity;
	}

	if (vel.x < 0)
	{
		vel.x += FRICTION * deltaTime;
		if (vel.x > 0)
			vel.x = 0;
	}

	if (vel.x > 0)
	{
		vel.x -= FRICTION * deltaTime;
		if (vel.x < 0)
			vel.x = 0;
	}
	
	pos += vel * deltaTime * 10.f;

	body.setPosition(pos);
}
void Player::Jump(bool forced)
{
	if (forced || grounded)
	{
		vel.y = -sqrt(2.0f * GRAVITY * JUMPHEIGHT); // EQUA��O DE TORRICELLI APLICADA
		setGrounded(false);
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
	Move();
	Gravity();
	ThrustForce();

	setGrounded(false);
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

void atkDimentions(bool a, sf::Vector2f* pos, sf::Vector2f* size) // Fun��o auxiliar para mudar o tamanho da hitbox durante um ataque
{
	if (a)
	{
		(*size).x += 30.f;
	}
	else
	{
		(*size).x -= 30.f;
	}
}

void Player::attack(bool a)
{
	if (atkCDTimer < 0.5f)
		return;

	attacking = a;

	atkDimentions(a, &pos, &size);
	if (a)
	{
		atkDurationTimer = 0;
	}
	else
	{
		atkCDTimer = 0;
	}
}

void Player::attack()
{
	if (!attacking)
	{
		atkCDTimer += deltaTime;
		return;
	}

	atkDurationTimer += deltaTime;
	if (atkDurationTimer > 0.5f)
		attack(false);
}

void Player::sufferDMG(int damage, bool unstoppable)
{
	if (!unstoppable && (!Blocking && rand() % 2))
		lives-= damage;
}

void Player::Collision(Enemies::Enemy* pE, bool xAxis, bool positive)
{

}

void Player::Collision(Obstacles::Obstacle* pO, bool xAxis, bool positiveTrajectory)
{
	static bool touchingGrass;

	if ((!touchingGrass) && (pO->getId() == bID::grass))
	{
		touchingGrass = true;
		velMultiplier = 0.8f;
	}
	if ((touchingGrass) && (pO->getId() != bID::grass))
	{
		touchingGrass = false;
		velMultiplier = 1.f;
	}
	if (!xAxis)
	{
		vel.y = 0;
		pos.y = pO->getPosition().y + (positiveTrajectory ? -size.y + 0.0001f : size.y + 0.0001f);
		if ((positiveTrajectory) && (!grounded))
			setGrounded(true);
	}
	else
	{
		vel.x = 0;
		pos.x = pO->getPosition().x + (positiveTrajectory ? -size.x + 0.0001f : size.x - 0.0001f);
	}
	
	pO->Activate();
}
unsigned char Player::counter(1);
unsigned int Player::points(0);