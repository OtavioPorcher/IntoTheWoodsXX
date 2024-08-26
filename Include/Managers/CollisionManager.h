#pragma once

#include "..\Entities\Characters\Player.h"
#include "..\Entities\Characters\Enemies\Enemy.h"
#include "..\Entities\Obstacles\Obstacle.h"
//Projetil

#include "..\Utils\EntityList.h"

namespace Managers
{
	class CollisionManager
	{
	private:
		Lists::List<Entities::Entity> playerList;
		Lists::List<Entities::Entity> enemyList;
		Lists::List<Entities::Entity> obstacleList;
		Lists::List<Entities::Entity> projectileList;

		
	public:
		CollisionManager();
		~CollisionManager();

		void addEntity(Entities::Entity* pEntidade);

		void Manage();

		void CollisionPlayerObstacles(Entities::Entity* pPlayer);
		void CollisionPlayerEnemies(Entities::Entity* pPlayer);
		void CollisionPlayerProjectiles(Entities::Entity* pPlayer);
		void CollisionProjectileObstacles(Entities::Entity* pProjectile);
	};
}