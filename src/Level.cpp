#include "../include/Levels/Level.h"
using namespace Levels;

#include <fstream>
#include <ctime>

Level::Level(StateMachine* psm, sID id_) : State(psm, id_),
	pIM(Managers::InputManager::getInstance()),
	pPIO(NULL),
	pCM(NULL),
	clock(),
	dt(0),
	pPlayer1(NULL),
	pPlayer2(NULL),
	entityList(),
	end()
{
	try { pCM = new Managers::CollisionManager(); }
	catch (int error)
	{
		if (!error)
		{
			std::cout << "ERROR: Failed to Allocate Memory (CollisionManager)" << std::endl;
			exit(1);
		}
	}
}

Level::~Level()
{

}

void Level::Draw()
{
	//background.setPos(pGM->getViewCenter());
	//pGM->draw(background);
	entityList.DrawEntities();
}

void Level::setupLevel()
{
	createMap();
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
			if (line[j] == 'Q')
				CreateRandomPlatform(sf::Vector2f((float)j, (float)i), (line[j - 1] == ' '));
			if (line[j] == 'V')
				CreateRandomGrassPatch(sf::Vector2f((float)j, (float)i), (line[j - 1] != 'V'));
			else if (line[j] != ' ')
				CreateEntity(line[j], sf::Vector2f((float)j, (float)i));
		}
	Entities::Characters::Enemies::Enemy::setPlayers(pPlayer1, pPlayer2);
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
	}
	else
	{
		delete aux;
		return;
	}

	Entity* auxEntity = static_cast<Entity*>(aux);

	entityList.insertFront(auxEntity);
	pCM->addEntity(auxEntity);

	aux = NULL;
	auxEntity = NULL;
}

void Level::CreateGround(sf::Vector2f pos) // TEM QUE VER SE DÁ PRA COLOCAR TRYCATCH!
{
	Entities::Obstacles::Ground* aux = new Entities::Obstacles::Ground(pos);

	Entity* auxEntity = static_cast<Entity*>(aux);

	entityList.insertFront(auxEntity);
	pCM->addEntity(auxEntity);

	aux = NULL;
	auxEntity = NULL;
}

void Level::CreateRandomPlatform(sf::Vector2f pos, const bool first)
{
	static bool growing;

	srand((unsigned int)time(NULL)+rand());

	if (first)
	{
		growing = true;
	}

	if (growing)
	{
		if ((rand() % 7)>0)
		{
			CreateGround(pos * 50.f);
			return;
		}
		else
			growing = false;
	}
}

void Level::CreateGrass(sf::Vector2f pos)
{
	Entities::Obstacles::TallGrass* aux = new Entities::Obstacles::TallGrass(pos);

	Entity* auxEntity = static_cast<Entity*>(aux);

	entityList.insertFront(auxEntity);
	pCM->addEntity(auxEntity);

	aux = NULL;
	auxEntity = NULL;
}

void Level::CreateRandomGrassPatch(sf::Vector2f pos, const bool first)
{
	static bool growing;

	

	if (first)
	{
		growing = true;
	}

	if (growing)
	{
		if ((rand() % 7)>0)
		{
			CreateGrass(pos * 50.f);
			return;
		}
	}

	growing = false;
}

void Level::CreateSnake(sf::Vector2f pos, const bool random)
{
	srand((unsigned int)time(NULL) + rand());
	if (random && ((rand() % 2) > 0))
	{
		return;
	}

	Entities::Characters::Enemies::Snake* aux = new Entities::Characters::Enemies::Snake(this, pos);
	if (!aux)
	{
		std::cout << "ERROR: Failed to Allocate Memory (Snake)!" << std::endl;
		exit(1);
	}

	Entity* auxEntities = static_cast<Entity*>(aux);

	entityList.insertFront(auxEntities);
	pCM->addEntity(auxEntities);

	aux = NULL;
	auxEntities = NULL;
}

void Level::addEntity(Entities::Entity* pEntity)
{
	entityList.insertFront(pEntity);
	pCM->addEntity(pEntity);
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
	float maxX = end + (2* 50.f) - minX;
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
	if (auxView > maxX)
		auxView = maxX;


	pGM->centerView({auxView, RES_Y/2});
}

const bool Level::checkWipe()const
{
	if (!pPlayer1->getActive() && !pPlayer2->getActive())
		return true;
	return false;
}

const bool Level::checkDone()const
{
	if ((pPlayer1->getPosition().x >= end) || (pPlayer2->getPosition().x >= end))
		return true;
	return false;
}

const unsigned int Levels::Level::getPoints()
{
	return points;
}

void Level::setTwoPlayers(bool b)
{
	twoPlayers = b;
}

bool Level::twoPlayers(true);
unsigned int Level::points(0);