#include "..\Include\Entities\Characters\Enemies\Bear.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

#include "../Include/Entities//Characters/Player.h"
#include "../Include/Entities/Projectiles/Rock.h"

#include "../Include/Levels/Dawn.h"

Bear::Bear(Levels::Dawn* pL, sf::Vector2f position) : Enemy({100.f, 50.f}, bID::bear),
	timerRockCD(0.f),
	pLevel(pL)
{
	pos = position;
	body.setFillColor(sf::Color(162, 42, 42));

	vel.x = 150.f;
	lives = 2;
}

Bear::~Bear()
{

}

#include <cmath>
#include <climits>
const float Bear::getDistance(Player* pPlayer)
{
	if (!pPlayer->getActive())
		return (float)INT_MAX;

	sf::Vector2f halfSizePlayer = pPlayer->getSize() / 2.f;
	sf::Vector2f halfSizeEnemy = size / 2.f;

	sf::Vector2f CenterPlayer = pPlayer->getPosition() - (halfSizePlayer);
	sf::Vector2f CenterEnemy = pos - (halfSizeEnemy);

	sf::Vector2f distanceSquared; //Quadrado da distância em x e y
	distanceSquared.x = powf((CenterPlayer - CenterEnemy).x, 2);
	distanceSquared.y = powf((CenterPlayer - CenterEnemy).y, 2);

	return sqrt(distanceSquared.x + distanceSquared.y);
}

void Bear::Move()
{
	Player* target;
	target = (getDistance(pPlayer1) < getDistance(pPlayer2) ? target = pPlayer1 : target = pPlayer2);
	if (((target->getPosition().x - pos.x)* vel.x) < 0)
		vel.x *= -1;

	pos += vel * deltaTime;

}

void Bear::Update()
{

	atkCdTimer += deltaTime;
	dmgCdTimer += deltaTime;
	throwRock();

	body.setPosition(pos);
	body.setSize(size);

	Gravity();
	ThrustForce();
	Move();
}

void Bear::Draw()
{
	pGM->render(&body);
}

void Bear::save(nlohmann::json& saveJson)
{

}

void Bear::throwRock()
{
	if (timerRockCD < 1.f)
	{
		timerRockCD += deltaTime;
		return;
	}
	Projectiles::Rock* auxRock;

	if (pPlayer1->getActive())
	{
		auxRock = new Projectiles::Rock({ pPlayer1->getPosition().x , 51.f });
		pLevel->addEntity(static_cast<Entity*> (auxRock));
		auxRock = NULL;
	}
	if (pPlayer2->getActive())
	{
		auxRock = new Projectiles::Rock({ pPlayer2->getPosition().x , 51.f });
		pLevel->addEntity(static_cast<Entity*> (auxRock));
		auxRock = NULL;
	}
	timerRockCD = 0.f;
}

void Bear::attack(Player* pPlayer)
{
	if (atkCdTimer > 0.8f)
	{
		pPlayer->sufferDMG(3, true);
		atkCdTimer = 0;
	}
}

void Bear::sufferDMG()
{
	if (dmgCdTimer > 0.5f)
	{
		lives--;
		if (lives <= 0)
		{
			setActive(false);
			Player::Score(getId());
			pLevel->bearKilled();
		}
		dmgCdTimer = 0.f;
	}
}

