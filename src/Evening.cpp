#include "..\Include\Levels\Evening.h"
using namespace Levels;

Evening::Evening(StateMachine* psm):Level(psm, sID::Evening),
	done(false)
{

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
	dinamicEntities.UpdateEntities();
	staticEntities.UpdateEntities();
	updateDeltaTime();
	//CollisionManager run
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
	dinamicEntities.insertFront(aux);
	aux = NULL;
}