#include "..\Include\Managers\CollisionManager.h"
using namespace Managers;

#include <cmath>

CollisionManager::CollisionManager():
	playerList(),
	enemyList(),
	obstacleList(),
	projectileList()
{

}

CollisionManager::~CollisionManager()
{
	
}

void CollisionManager::addEntity(Entities::Entity* pEntity)
{
	switch (pEntity->getId())
	{
	case bID::player:
		playerList.insertFront(pEntity);
		break;

	case bID::scorpion:
	case bID::snake:
	case bID::bear:
		enemyList.insertFront(pEntity);
		break;

	case bID::ground:
	case bID::grass:
	case bID::nest:
	case bID::trap:
		obstacleList.insertFront(pEntity);
		break;

	case bID::projectile:
		projectileList.insertFront(pEntity);
		break;
	}
}

void CollisionManager::Manage()
{
	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = playerList.begin();
	for (it; it != playerList.end(); it++) // Gerencia as colisões dos players
	{
		CollisionPlayerObstacles((*it));
		CollisionPlayerEnemies((*it));
		CollisionPlayerProjectiles((*it));
	}
	it = projectileList.begin();
	for (it; it != projectileList.end(); it++) // Gerencia as colisões dos projéteis
	{
		CollisionProjectileObstacles((*it));
	}
}

/*========================================================================================*/
//  Funções auxiliares para calculo da colisão


void getCollisionDetails(sf::Vector2f distance, sf::Vector2f minDistance, bool* xAxis, bool* positiveTrajectory)
{

	sf::Vector2f collisionDepth;
	collisionDepth.x = (distance.x > 0 ? minDistance.x : -minDistance.x) - distance.x;
	collisionDepth.y = (distance.y > 0 ? minDistance.y : -minDistance.y) - distance.y;

	(*xAxis) = (fabs(collisionDepth.x) < fabs(collisionDepth.y));
	(*positiveTrajectory) = ((*xAxis) ? (collisionDepth.x < 0) : (collisionDepth.y < 0));

}

const bool Collide(Entities::Entity* pE1, Entities::Entity* pE2, bool* xAxis = NULL, bool* positiveTrajectory = NULL)
{

	sf::Vector2f halfSize1 = pE1->getSize() / 2.f;
	sf::Vector2f halfSize2 = pE2->getSize() / 2.f;

	sf::Vector2f Center1 = pE1->getPosition() + (halfSize1);
	sf::Vector2f Center2 = pE2->getPosition() + (halfSize2);

	sf::Vector2f distance = Center1 - Center2;
	sf::Vector2f minDistance = halfSize1 + halfSize2;

	const bool collided = ((fabs(distance.x) < minDistance.x) && (fabs(distance.y) < minDistance.y));

	if ((collided) && (xAxis && positiveTrajectory))
		getCollisionDetails(distance, minDistance, xAxis, positiveTrajectory);

	return collided;
}


void CollisionManager::CollisionPlayerObstacles(Entities::Entity* pPlayer)
{
	if (obstacleList.empty())
		return;
	if (!(pPlayer->getActive()))
		return;
	// TODO: DESACOPLAR A COLISÃO DA CLASSE
	bool xAxis, positiveTrajectory;

	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = obstacleList.begin();
	for (it; it != obstacleList.end(); it++)
	{
		if ((*it)->getActive())
		{
			if (Collide(pPlayer,(*it), &xAxis, &positiveTrajectory))
				static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Entities::Obstacles::Obstacle*>((*it)), xAxis, positiveTrajectory);
		}
	}
}

void CollisionManager::CollisionPlayerEnemies(Entities::Entity* pPlayer)
{
	if (enemyList.empty())
		return;
	if (!(pPlayer->getActive()))
		return;
	
	bool xAxis, positiveTrajectory;

	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = enemyList.begin();
	for (it; it != enemyList.end(); it++)
	{
		if ((*it)->getActive())
		{
			if (Collide(pPlayer, (*it), &xAxis, &positiveTrajectory))
				static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Entities::Characters::Enemies::Enemy*>((*it)), xAxis, positiveTrajectory);
		}
	}
}

void CollisionManager::CollisionPlayerProjectiles(Entities::Entity* pPlayer)
{
	if (projectileList.empty())
		return;
	if (!(pPlayer->getActive()))
		return;

	bool xAxis, positiveTrajectory;

	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = projectileList.begin();
	for (it; it != projectileList.end(); it++)
	{
		if ((*it)->getActive())
		{
			if (Collide(pPlayer, (*it)))
				static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Projectiles::Projectile*>((*it)));
		}
	}
}

void CollisionManager::CollisionProjectileObstacles(Entities::Entity* pProjectile)
{
	if (obstacleList.empty())
		return;
	if (!(pProjectile->getActive()))
		return;

	bool xAxis, positiveTrajectory;

	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = obstacleList.begin();
	for (it; it != obstacleList.end(); it++)
	{
		if ((*it)->getActive())
		{
			if (Collide(pProjectile, (*it)))
				static_cast<Entities::Projectiles::Projectile*> (pProjectile)->Collide(static_cast<Entities::Obstacles::Obstacle*>((*it)));
		}
	}
}