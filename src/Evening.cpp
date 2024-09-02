#include "..\Include\Levels\Evening.h"
using namespace Levels;

#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

#include "..\Entities\Characters\Enemies\Scorpion.h"
using namespace Enemies;


Evening::Evening(StateMachine* psm):Level(psm, sID::Evening, bID::evening),
	levelTimer(0)
{
	setupLevel();
}

Evening::~Evening()
{

}

std::string Evening::getFileName()
{
	return "Assets/Evening.txt";
}

void Evening::Update()
{
	if (!isRuning)
	{
		isRuning = true;
		if (!twoPlayers)
			pPlayer2->setActive(false);
		clock.restart();
	}

	entityList.UpdateEntities();
	updateDeltaTime();
	levelTimer += dt;


	pCM->Manage();

	if (checkWipe())
	{
		changeState(sID::gameOver);
	}
	updateView();
	if (checkDone())
	{
		points += (int)(Player::getPoints() * (100 / levelTimer));
		points -= points % 10;
		Player::ResetPoints();
		changeState(sID::Dawn);
	}
}

void Evening::Reset()
{

}

void Evening::CreateEntity(char id, sf::Vector2f pos)
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
	case 'E':
		CreateScorpion(pos);
		break;
	case 'N':
		CreateNest(pos);
		break;
	case 'X':
		CreateGrass({pos.x, pos.y});
		break;
	case 'M':
		CreateNest(pos, true);
		break;
	case 'Y':
		CreateScorpion(pos, true);
		break;
	case 'S':
		CreateSnake(pos);
		break;
	case 'C':
		CreateSnake(pos, true);
		break;

	}
}

void Evening::CreateScorpion(sf::Vector2f pos, const bool random)
{
	srand((unsigned int)time(NULL) + rand());
	if (random && ((rand() % 2) > 0))
	{
		return;
	}

	Scorpion* aux = new Scorpion(pos);
	if (!aux)
	{
		std::cout << "ERROR: Failed to Allocate Memory (Scorpion)!" << std::endl;
		exit(1);
	}

	Entity* auxEntity = static_cast<Entity*>(aux);

	addEntity(auxEntity);

	aux = NULL;
	auxEntity = NULL;
}

void Evening::CreateNest(sf::Vector2f pos, const bool random)
{
	srand((unsigned int)time(NULL) + rand());
	if (random && ((rand() % 3) > 0))
	{
		CreateGround(pos);
		return;
	}
	Nest* aux = new Nest(this, pos);
	if (!aux)
	{
		std::cout << "ERROR: Failed to Allocate Memory (Nest)!" << std::endl;
		exit(1);
	}

	Entity* auxEntity = static_cast<Entity*>(aux);

	addEntity(auxEntity);

	aux = NULL;
	auxEntity = NULL;
}