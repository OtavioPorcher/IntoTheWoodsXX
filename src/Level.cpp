#include "../include/Levels/Level.h"
using namespace Levels;

#include <fstream>

Level::Level(StateMachine* psm, sID id_) : State(psm, id_),
	pIM(InputManager::getInstance()),
	pPIO(NULL),
	clock(),
	dt(0),
	pPlayer1(NULL),
	pPlayer2(NULL),
	dinamicEntities(),
	staticEntities(),
	end()
{
	
}

Level::~Level()
{

}

void Level::Draw()
{
	//background.setPos(pGM->getViewCenter());
	//pGM->draw(background);
	dinamicEntities.DrawEntities();
	staticEntities.DrawEntities();
}

void Level::setupLevel()
{
	//createMap();
	try
	{
		pPIO = new Observers::PlayerInputObserver(pPlayer1, pPlayer2, static_cast<State*>(this));
		pIM->setObserver(static_cast<Observer*>(pPIO));
	}
	catch (int error)
	{
		if (!error)
		{
			std::cout << "ERROR: Failed to Allocate Memory (PlayerInputObserver)" << std::endl;
			exit(1);
		}
	}
}

void Level::createMap()
{
	std::ifstream Map;
	std::string line;
	Map.open(getFileName());
	if (!Map.is_open())
	{
		std::cout << "ERROR: Failed to open Map File!" << std::endl;
		exit(1);
	}

	for(unsigned int i = 0; std::getline(Map,line); i++)
		for (unsigned int j = 0; j < line.size(); j++)
		{
			if (line[j] == '*')
				end = j * 50.0f;
			else if (line[j] != ' ')
				CreateEntity(line[j], sf::Vector2f((float)j, (float)i));
		}

}

void Level::CreatePlayer(sf::Vector2f pos) // TEM QUE VER SE DÁ PRA COLOCAR TRYCATCH!
{
	Entities::Characters::Player* aux = new Entities::Characters::Player(pos);
	if (!aux)
	{
		std::cout << "ERROR: Failed to Allocate Memory (Player)" << std::endl;
		exit(1);
	}

	if (aux->getPlayerId() == 1)
	{
		pPlayer1 = aux;
	}
	else if (aux->getPlayerId() == 2)
	{
		pPlayer2 = aux;
		if (!twoPlayers)
			pPlayer2->setActive(false);
	}
	else
	{
		delete aux;
		return;
	}
	dinamicEntities.insertFront(static_cast<Entity*>(aux));
	aux = NULL;
}

void Level::CreateGround(sf::Vector2f pos) // TEM QUE VER SE DÁ PRA COLOCAR TRYCATCH!
{
	Entities::Obstacles::Ground* aux = new Entities::Obstacles::Ground(pos);
	staticEntities.insertFront(static_cast<Entity*>(aux));
	aux = NULL;
}

void Level::updateDeltaTime()
{
	dt = clock.getElapsedTime().asSeconds();
	Entity::updateDeltaTime(dt);
	pGM->checkStutter(dt);
	clock.restart();
}

void Level::updateView()
{
	float auxView = 0.f;
	float minX = RES_X / 2;
	//float maxX = end - minX;
	unsigned int auxCounter = 0;

	if (pPlayer1->getActive())
	{
		auxView += pPlayer1->getPosition().x;
		auxCounter++;
	}
	if (pPlayer2->getActive())
	{
		auxView += pPlayer2->getPosition().x;
		auxCounter++;
	}
	auxView /= auxCounter;
	if (auxView < minX)
		auxView = minX;
	//if (auxView > maxX)
	//	auxView = maxX;


	pGM->centerView({auxView, RES_Y/2});
}

const bool Level::checkWipe()const
{
	if (!pPlayer1->getActive() && (!twoPlayers || !pPlayer2->getActive()))
		return 1;
	return 0;
}

const bool Level::checkDone()const
{
	if ((pPlayer1->getPosition().x >= end) || (pPlayer2->getPosition().x >= end))
		return true;
	return false;
}

void Level::setTwoPlayers(bool b)
{
	twoPlayers = b;
}

bool Level::twoPlayers(false);