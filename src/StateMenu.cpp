#include "..\Include\Menus\StateMenu.h"
using namespace Menus;

StateMenu::StateMenu(StateMachine* pSM, sID id_) : 
	pMenu()
{
	switch(id_)
	{
	case sID::MainMenu:
		pMenu = static_cast<Menu*>(new MainMenu(this));
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