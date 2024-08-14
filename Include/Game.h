#pragma once

#include "..\Include\Entities\Characters\Player.h"
#include "..\Include\Properties\GameProps.h"
#include "SFML/Graphics.hpp"
//#include "..\Include\Utils\List.h"


class Game
{
private:
	sf::RenderWindow window;
	Entities::Characters::Player player;
	//Utils::List<Entities::Characters::Player> pList;
public:
	Game();
	~Game();
	void executar();
};
