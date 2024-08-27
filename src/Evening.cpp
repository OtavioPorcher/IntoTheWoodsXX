#include "..\Include\Levels\Evening.h"
using namespace Levels;

#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

Evening::Evening(StateMachine* psm):Level(psm, sID::Evening)
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
	}



	entityList.UpdateEntities();
	updateDeltaTime();
	pCM->Manage();

	if (checkWipe())
	{
		//game over
	}
	updateView();
	if (checkDone())
	{
		pGM->closeWindow();
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
	}
}

void Evening::CreateScorpion(sf::Vector2f pos)
{
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

void Evening::CreateNest(sf::Vector2f pos)
{
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