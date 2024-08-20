#include "..\Include\Game.h"
#include <iostream>

Game::Game() :
	pEM(EventManager::getInstance()),
	pGM(GraphicManager::getInstance()),
	pIM(InputManager::getInstance()),
	player(),
	pList()
	
{
	pList.insertFront(&player);
	std::cout << pList.getSize() << std::endl; 
	pList.remove(&player);
	std::cout << pList.getSize() << std::endl;
}
Game::~Game()
{

}
void Game::executar()
{
	while(pGM->isWindowOpen())
	{
		pEM->Run();
		pGM->clear();
		pGM->render((sf::RectangleShape*)player.getBody());
		pGM->display();
		player.Move();
	}
}