#include "..\Include\Game.h"
#include <iostream>

Game::Game() :
	pEM(EventManager::getInstance()),
	pGM(GraphicManager::getInstance()),
	pIM(InputManager::getInstance())
{
	StateMachine* pAux = static_cast<StateMachine*>(this);
	addState(static_cast<State*>(new Evening(pAux)));
	addState(static_cast<State*> (new StateMenu(pAux, sID::MainMenu)));
	changeCurrentState(sID::MainMenu);
}
Game::~Game()
{

}

Game* Game::getInstance()
{
	if (!instance)
	{
		try { instance = new Game(); }
		catch (int error)
		{
			if (!error)
			{
				std::cout << "ERROR: Failed to Allocate Memory" << std::endl;
				exit(1);
			}
		}
	}

	return instance;
}

void Game::executar()
{
	while(pGM->isWindowOpen())
	{
		pGM->clear();
		runCurrentState();
		pGM->display();
		pEM->Run();
	}
}

Game* Game::instance(NULL);