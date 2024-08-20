#include"../Include/Menus/StateMenu.h"
#include "..\Include\Menus\Menu.h"
using namespace Menus;


Menu::Menu(StateMenu* pS):
	pState(pS),
	pIM(Managers::InputManager::getInstance())
{

}

Menu::~Menu()
{

}
