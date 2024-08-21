#include "..\Include\Game.h"
#include <iostream>

Game::Game() :
	pEM(EventManager::getInstance()),
	pGM(GraphicManager::getInstance()),
	pIM(InputManager::getInstance()),
	player()
	
{
	addState(static_cast<State*>(new Menus::StateMenu()));
}
Game::~Game()
{

}

Game* Game::getInstance()
{
	if (!instance)
	{
		instance = new Game();
	}

	return instance;
}

void Game::executar()
{
	while(pGM->isWindowOpen())
	{
		
		pGM->clear();
		//runCurrentState();
		pGM->render((sf::RectangleShape*)player.getBody());
		pGM->display();
		pEM->Run();
		player.Move();
	}
}

Game* Game::instance(NULL);