#pragma once

#include <..\Entities\Player.h>

class Game
{
private:
	sf::RenderWindow window;
	Entities::Player player;
public:
	Game();
	~Game();
	void executar();
};
