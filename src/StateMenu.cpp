#include <iostream>

#include "..\Include\Menus\StateMenu.h"
using namespace Menus;

StateMenu::StateMenu(StateMachine* pSM, sID id_) : 
	pMenu()
{
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
	}
}

StateMenu::~StateMenu()
{
	pMenu = NULL;
}

void StateMenu::Update()
{
	pMenu->Update();
}

void StateMenu::Draw()
{
	pMenu->Draw();
}

void StateMenu::Reset()
{
	pMenu->Reset();
}