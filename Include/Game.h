#pragma once

#include "Entities\Characters\Player.h" // Provis�rio enquanto n�o h� fase implementada
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



class Game : public StateMachine
{
private:
	static Game* instance;

	EventManager* pEM;
	GraphicManager* pGM;
	InputManager* pIM;

	Entities::Characters::Player player;
	Entities::Characters::Enemies::Scorpion scorpion;
	Entities::Obstacles::Ground ground;
	

	Game();
	
public:
	static Game* getInstance();
	~Game();
	void executar();
};
