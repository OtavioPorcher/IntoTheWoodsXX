#include "..\Include\Game.h"
#include <iostream>

Game::Game() :
	window(sf::VideoMode(RES_X, RES_Y), "Into The Woods++"),
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
	
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		window.clear();
		window.draw(player.getBody());
		window.display();

		player.Move();
		
	}

}