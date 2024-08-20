#include "..\Include\Menus\Menu.h"
using namespace Menus;

#include "..\Include\Menus\StateMenu.h"
using namespace States;

StateMenu::StateMenu(Menu* pM, StateMachine* pSM, sID id_) : 
	pMenu(pM)
{

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