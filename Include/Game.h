#pragma once

#include "Entities\Characters\Player.h" // Provisório enquanto não há fase implementada

#include "States/StateMachine.h"
using namespace States;

#include "Managers\EventManager.h"
#include "Managers\GraphicManager.h"
#include "Managers\InputManager.h"
using namespace Managers;

#include "Menus/StateMenu.h"
#include "Menus/MainMenu.h"



class Game : public StateMachine
{
private:
	EventManager* pEM;
	GraphicManager* pGM;
	InputManager* pIM;

	Entities::Characters::Player player;
	
public:
	Game();
	~Game();
	void executar();
};
