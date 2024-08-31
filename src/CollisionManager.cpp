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
		//CollisionPlayerProjectiles((*it));
	}
	it = projectileList.begin();
	for (it; it != projectileList.end(); it++) // Gerencia as colisões dos projéteis
	{
		//CollisionProjectileObstacles((*it));
	}
}

/*========================================================================================*/
//  CLASSE AUXILIAR PARA CALCULAR A COLISÃO DE DOIS OBJETOS

class Collision
{
private:
	Entities::Entity* pE1;
	Entities::Entity* pE2;

	sf::Vector2f Center1;
	sf::Vector2f Center2;

	sf::Vector2f distance; //Distância entre os centros.
	sf::Vector2f minDistance; //Distância mínima para os objetos não colidirem
	sf::Vector2f collisionDepth; //Profundidade da colisão

	bool collided;
	bool xAxis;
	bool positiveTrajectory;

public:
	Collision():
		pE1(NULL),
		pE2(NULL),
		Center1(),
		Center2(),
		distance(),
		minDistance(),
		collisionDepth(),
		collided(false),
		xAxis(false),
		positiveTrajectory(false)
	{

	}
	~Collision() {	}
	void setEntities(Entities::Entity* pe1, Entities::Entity* pe2)
	{
		pE1 = pe1;
		pE2 = pe2;

		sf::Vector2f halfSize1 = pE1->getSize() / 2.f;
		sf::Vector2f halfSize2 = pE2->getSize() / 2.f;

		Center1 = pE1->getPosition() - (halfSize1);
		Center2 = pE2->getPosition() - (halfSize2);

		distance = Center1 - Center2;
		minDistance = halfSize1 + halfSize2; 

		collided = ((fabs(distance.x) < minDistance.x) && (fabs(distance.y) < minDistance.y));

		if (collided)
			getCollisionDetails();
	}

	void getCollisionDetails()
	{

		collisionDepth.x = (distance.x > 0 ? minDistance.x : -minDistance.x) - distance.x;
		collisionDepth.y = (distance.y > 0 ? minDistance.y : -minDistance.y) - distance.y;

		xAxis = (fabs(collisionDepth.x) < fabs(collisionDepth.y));
		positiveTrajectory = (xAxis ? (collisionDepth.x < 0) : (collisionDepth.y < 0));

	}

	const bool Collide()
	{
		return collided;
	}

	const bool getXAxis()
	{
		return xAxis;
	}

	const bool getPositiveTrajectory()
	{
		return positiveTrajectory;
	}
};


void CollisionManager::CollisionPlayerObstacles(Entities::Entity* pPlayer)
{
	if (obstacleList.empty())
		return;
	if (!(pPlayer->getActive()))
		return;
	// TODO: DESACOPLAR A COLISÃO DA CLASSE
	Collision collision;

	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = obstacleList.begin();
	for (it; it != obstacleList.end(); it++)
	{
		if ((*it)->getActive())
		{
			collision.setEntities(pPlayer, (*it));
			if (collision.Collide())
				static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Entities::Obstacles::Obstacle*>((*it)), collision.getXAxis(), collision.getPositiveTrajectory());
		}
	}
}

void CollisionManager::CollisionPlayerEnemies(Entities::Entity* pPlayer)
{
	if (enemyList.empty())
		return;
	if (!(pPlayer->getActive()))
		return;
	
	Collision collision;

	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = enemyList.begin();
	for (it; it != enemyList.end(); it++)
	{
		if ((*it)->getActive())
		{
			collision.setEntities(pPlayer, (*it));
			if (collision.Collide())
				static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Entities::Characters::Enemies::Enemy*>((*it)), collision.getXAxis(), collision.getPositiveTrajectory());
		}
	}
}

void CollisionManager::CollisionPlayerProjectiles(Entities::Entity* pPlayer)
{

	/*if(projectileList.empty())
		return;
	bool positive;
	Lists::List<Entities::Entity>::Iterator<Entities::Entity> it = playerList.begin();
	for (it; it != playerList.end(); it++)
	{
		if (touchingX(pPlayer, (*it), &positive))
			static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Entities::Projectiles::Projectile*>((*it)), true, positive);
		if (touchingY(pPlayer, (*it), &positive))
			static_cast<Entities::Characters::Player*> (pPlayer)->Collision(static_cast<Entities::Projectiles::Projectile*>((*it)), false, positive);
	}*/
}

void CollisionManager::CollisionProjectileObstacles(Entities::Entity* pProjectile)
{

}