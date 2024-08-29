#include <iostream>

#include "..\Include\Menus\StateMenu.h"
using namespace Menus;

#include "..\Include\Observers\MenuObserver.h"

StateMenu::StateMenu(StateMachine* pSM, sID id_) : State(pSM, id_),
	pMenu(),
	pIM(Managers::InputManager::getInstance()),
	pMO(NULL)
{
	try { pMO = new Observers::MenuObserver(this); }
	catch (int error)
	{
		if(!error)
		{
			std::cout << "ERROR: Failed to Allocate Memory (MenuObserver)" << std::endl;
			exit(1);
		}
	}
	if (pMO)
		pIM->setObserver(static_cast<Observers::Observer*> (pMO));

	switch(id_)
	{
	case sID::MainMenu:
		try { pMenu = static_cast<Menu*>(new MainMenu(this)); }
		catch (int error)
		{
			if (!error)
			{
				std::cout << "ERROR: Failed to Allocate Memory (MainMenu)" << std::endl;
				exit(1);
			}
		}
		break;
	case sID::newGameMenu:
		try { pMenu = static_cast<Menu*>(new NewGameMenu(this)); }
		catch (int error)
		{
			if (!error)
			{
				std::cout << "ERROR: Failed to Allocate Memory (NewGameMenu)" << std::endl;
				exit(1);
			}
		}
	}
}

StateMenu::~StateMenu()
{
	pMenu = NULL;
}

void StateMenu::Update()
{
	isRuning = true;
	pMenu->Update();
}

void StateMenu::Draw()
{
	pMenu->Draw();
}

void StateMenu::MoveUp()
{
	pMenu->MoveUp();
}

void StateMenu::MoveDown()
{
	pMenu->MoveDown();
}

void StateMenu::Select()
{
	pMenu->Select();
}

void StateMenu::Escape()
{
	pMenu->Escape();
}