#include "../Include/Entities/Characters/Enemies/Bear.h"
#include "../Include/Entities/Obstacles/Trap.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;
using namespace Obstacles;

#include "../Include/Levels/Dawn.h"
using namespace Levels;

Dawn::Dawn(StateMachine* pSM) : Level(pSM, sID::Dawn),
	bossDead(false)
{
	setupLevel();
}

Levels::Dawn::~Dawn()
{

}

void Levels::Dawn::Update()
{
	if (!isRuning)
	{
		isRuning = true;
		if (!twoPlayers)
			pPlayer2->setActive(false);
	}

	entityList.UpdateEntities();
	updateDeltaTime();

	pCM->Manage();

	if (checkWipe())
	{
		changeState(sID::gameOver);
	}

	updateView();

	if (checkDone())
	{
		points += (int)(Player::getPoints());
		changeState(sID::gameOver);
	}
}

void Dawn::Reset()
{

}

std::string Dawn::getFileName()
{
	return "Assets/Dawn.txt";
}

void Dawn::CreateEntity(const char id, sf::Vector2f pos)
{
	pos.x *= 50.f;
	pos.y *= 50.f;

	switch (id)
	{
	case 'G':
		CreateGround(pos);
		break;
	case 'P':
		CreatePlayer(pos);
		break;
	case 'X':
		CreateGrass({ pos.x, pos.y });
		break;
	case 'S':
		CreateSnake(pos);
		break;
	case 'C':
		CreateSnake(pos, true);
		break;
	case 'B':
		CreateBear(pos);
		break;
	/*case 'R':
		CreateBear(pos,true);
		break;
		*/
	case 'T':
		CreateTrap(pos);
		break;
	case 'A':
		CreateTrap(pos, true);
		break;
	}
}

void Dawn::CreateBear(sf::Vector2f pos)
{

}

void Dawn::CreateTrap(sf::Vector2f pos, const bool random)
{
	srand((unsigned int)time(NULL) + rand());
	if (random && ((rand() % 3) > 0))
	{
		CreateGround(pos);
		return;
	}
	Trap* aux = new Trap(pos, rand()%2+1);
	if (!aux)
	{
		std::cout << "ERROR: Failed to Allocate Memory (Trap)!" << std::endl;
		exit(1);
	}

	Entity* auxEntity = static_cast<Entity*>(aux);

	addEntity(auxEntity);
}
