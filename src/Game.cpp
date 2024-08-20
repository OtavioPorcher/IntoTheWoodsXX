#include "..\Include\Game.h"
#include <iostream>

Game::Game() :
	pEM(EventManager::getInstance()),
	pGM(GraphicManager::getInstance()),
	pIM(InputManager::getInstance()),
	player()
	
{
	addState(new Menus::MainMenu());
}
Game::~Game()
{

}
void Game::executar()
{
	while(pGM->isWindowOpen())
	{
		
		pGM->clear();
		runCurrentState();
		//pGM->render((sf::RectangleShape*)player.getBody());
		pGM->display();
		pEM->Run();
		//player.Move();
	}
}