#pragma once

#include "States/StateMachine.h"
#include "States/GameOverState.h"
using namespace States;

#include "Managers/EventManager.h"
#include "Managers/GraphicManager.h"
#include "Managers/InputManager.h"
using namespace Managers;

#include "Menus/StateMenu.h"
using namespace Menus;

#include "Levels/Evening.h"
#include "Levels/Dawn.h"
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