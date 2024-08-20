#pragma once

#include "..\Include\Entities\Characters\Player.h"
#include "..\Include\Utils\List.h"

#include "..\Include\Managers\EventManager.h"
#include "..\Include\Managers\GraphicManager.h"
#include "..\Include\Managers\InputManager.h"
using namespace Managers;


class Game
{
private:
	EventManager* pEM;
	GraphicManager* pGM;
	InputManager* pIM;

	Entities::Characters::Player player;
	Utils::List<Entities::Characters::Player> pList;
public:
	Game();
	~Game();
	void executar();
};
