#include "../Entities/Characters/Player.h"
#include "../Include/Entities/Characters/Enemies/Snake.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

#include"../Include/Levels/Level.h"

#include<iostream>

Snake::Snake(Levels::Level* pL, sf::Vector2f position) : Enemy({50.f, 50.f}, bID::snake),
	projectileList(),
	pLevel(pL)
{
	body.setFillColor(sf::Color::Blue);
	pos = position;
}

Snake::~Snake()
{

}

void Snake::Shoot()
{
	Player* target;
	target = (getDistance(pPlayer1) < getDistance(pPlayer2) ? target = pPlayer1 : target = pPlayer2);
	Projectiles::Poison* auxPoison = new Projectiles::Poison(target->getPosition(), pos);
	pLevel->addEntity(static_cast<Entity*>(auxPoison));
	atkCdTimer = 0.f;
}

#include <cmath>
#include <climits>
const float Snake::getDistance(Player* pPlayer)
{
	if (!pPlayer->getActive())
		return (float)INT_MAX;

	sf::Vector2f halfSizePlayer = pPlayer->getSize() / 2.f;
	sf::Vector2f halfSizeEnemy = size / 2.f;

	sf::Vector2f CenterPlayer = pPlayer->getPosition() - (halfSizePlayer);
	sf::Vector2f CenterEnemy = pos - (halfSizeEnemy);

	sf::Vector2f distanceSquared; //Quadrado da distância em x e y
	distanceSquared.x = powf((CenterPlayer - CenterEnemy).x , 2);
	distanceSquared.y = powf((CenterPlayer - CenterEnemy).y, 2);

	return sqrt(distanceSquared.x + distanceSquared.y);
}

void Snake::Move()
{

}

void Snake::Update()
{
	atkCdTimer += deltaTime;
	if (atkCdTimer > 2.5f)
		Shoot();
	body.setPosition(pos);
}

void Snake::Draw()
{
	pGM->render(&body);
}

const std::vector<Projectiles::Poison*>* Snake::getProjetileList()
{
	return &projectileList;
}

void Snake::attack(Player* pPlayer)
{

}
