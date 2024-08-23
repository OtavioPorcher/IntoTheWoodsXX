#include "../include/Levels/Level.h"
using namespace Levels;

Level::Level(StateMachine* psm, sID id_) : State(psm, id_),
	pIM(InputManager::getInstance()),
	pPIO(NULL),
	clock(),
	dt(0),
	pPlayer1(NULL),
	pPlayer2(NULL),
	dinamicEntities(),
	staticEntities()
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

void Level::CreatePlayer(sf::Vector2f pos) // TEM QUE VER SE DÁ PRA COLOCAR TRYCATCH!
{
	Entities::Characters::Player* aux = new Entities::Characters::Player();
	if (aux->getCounter() == 1)
	{
		pPlayer1 = aux;
	}
	else if (aux->getCounter() == 2)
	{
		pPlayer2 = aux;
	}
	else
		return;

	dinamicEntities.insertFront(static_cast<Entity*>(aux));
}

void Level::CreateGround(sf::Vector2f pos) // TEM QUE VER SE DÁ PRA COLOCAR TRYCATCH!
{
	Entities::Obstacles::Ground* aux = new Entities::Obstacles::Ground();
	staticEntities.insertFront(static_cast<Entity*>(aux));
}

void Level::updateDeltaTime()
{
	dt = clock.getElapsedTime().asSeconds();
	Entity::updateDeltaTime(dt);
	pGM->checkStutter(dt);
	clock.restart();
}