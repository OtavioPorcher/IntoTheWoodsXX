#include "..\Include\Levels\Evening.h"
using namespace Levels;

#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

Evening::Evening(StateMachine* psm):Level(psm, sID::Evening),
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
		changeState(sID::gameOver);
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
	case 'S':
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

	Entity* auxEntities = static_cast<Entity*>(aux);

	entityList.insertFront(auxEntities);
	pCM->addEntity(auxEntities);

	aux = NULL;
	auxEntities = NULL;
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

	Entity* auxEntities = static_cast<Entity*>(aux);

	entityList.insertFront(auxEntities);
	pCM->addEntity(auxEntities);

	aux = NULL;
	auxEntities = NULL;
}