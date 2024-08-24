#include "..\Include\Game.h"
#include <iostream>

Game::Game() :
	pEM(EventManager::getInstance()),
	pGM(GraphicManager::getInstance()),
	pIM(InputManager::getInstance()),
	player({0.f,0.f}),
	scorpion({ 480.0f, RES_Y - 50.0f }),
	ground({RES_X-50.f,RES_Y-50.f})
{
	
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
		//runCurrentState();
		player.Draw();
		scorpion.Draw();
		ground.Draw();
		player.Update();
		scorpion.Update();
		ground.Update();
		pGM->display();
		pEM->Run();
	}
}

Game* Game::instance(NULL);