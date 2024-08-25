#pragma once

#include "Entities\Characters\Player.h" // Provisório enquanto não há fase implementada
#include "Entities/Characters/Enemies/Scorpion.h"
#include "Entities\Obstacles\Ground.h"

#include "States/StateMachine.h"
using namespace States;

#include "Managers\EventManager.h"
#include "Managers\GraphicManager.h"
#include "Managers\InputManager.h"
using namespace Managers;

#include "Menus/StateMenu.h"
#include "Menus/MainMenu.h"

#include "Levels/Evening.h"
using namespace Levels;

class Game : public StateMachine
{
private:
	static Game* instance;

	EventManager* pEM;
	GraphicManager* pGM;
	InputManager* pIM;
	

	Game();
	
public:
	static Game* getInstance();
	~Game();
	void executar();
};
