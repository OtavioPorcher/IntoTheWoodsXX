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
	atkCDTimer(1.f),
	attacking(false),
	facingRight(true)
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

	if (vel.x > 0)
	{
		facingRight = true;
	}
	else if (vel.x < 0)
	{
		facingRight = false;
	}

	body.setPosition(pos);
}
void Player::Jump(bool forced)
{
	if (forced || grounded)
	{
		vel.y = -sqrt(2.0f * GRAVITY * JUMPHEIGHT); // EQUAÇÃO DE TORRICELLI APLICADA
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
	body.setSize(size);

	attack();

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

unsigned int Player::getPoints()
{
	return points;
}

void Player::setGrounded(bool a)
{
	grounded = a;	
}

void atkDimentions(bool a, sf::RectangleShape* body, sf::Vector2f* size, const bool facingRight) // Função auxiliar para mudar o tamanho da hitbox durante um ataque
{
	static bool atkDirection;
	if (a)
	{
		(*size).x += 30.f;
		atkDirection = facingRight;
		if (!atkDirection)
			body->setOrigin({ 30.f, 0.f});
	}
	else
	{
		(*size).x -= 30.f;
		if (!atkDirection)
			body->setOrigin({ 0.f, 0.f});
	}
}

void Player::attack(bool a)
{
	if (atkCDTimer < 0.5f)
		return;

	attacking = a;
	atkDimentions(a, &body, &size, facingRight);
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
	if (!unstoppable && (!Blocking || rand() % 2))
		lives -= damage;
	if (lives <= 0)
	{
		setActive(false);
	}
	std::cout <<"Player "<< (int)playerId << " Lifes: " << lives << std::endl;
}

void Player::Collision(Enemies::Enemy* pE, bool xAxis, bool positiveTrajectory)
{
	if (xAxis )
	{
		if (attacking && (positiveTrajectory == facingRight))
		{
			pE->sufferDMG();
		}
		else 
			pE->attack(this);
	}
	else if (positiveTrajectory)
	{
		Jump(true);
		pE->sufferDMG();
	}
}

void Player::Collision(Obstacles::Obstacle* pO, bool xAxis, bool positiveTrajectory)
{ 

	pO->updateVelMultiplier(this);

	if (pO->Collide(this))
	{
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
	}
}

void Player::Collision(Projectiles::Projectile* pP)
{
	pP->Collide(this);
}

void Player::setVelMultiplier(const float mult)
{
	velMultiplier = mult;
}

unsigned char Player::counter(1);
unsigned int Player::points(0);