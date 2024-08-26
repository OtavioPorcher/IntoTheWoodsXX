#include "..\Include\Levels\Evening.h"
using namespace Levels;

#include "..\Include\Entities\Obstacles\Nest.h"
using namespace Entities;
using namespace Obstacles;

Evening::Evening(StateMachine* psm):Level(psm, sID::Evening)
{
	CreatePlayer({ 0.f,0.f });
	CreatePlayer({ 400.0f, 400.0f });
	CreateScorpion({ 480.0f, RES_Y - 50.0f });
	CreateGround({ RES_X - 50.f,RES_Y - 50.f });
	CreateNest({ 455.f, (RES_Y/2)-25.f });

	setupLevel();

}

Evening::~Evening()
{

}

std::string Evening::getFileName()
{
	return "MAP FILE";
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
		//next level
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