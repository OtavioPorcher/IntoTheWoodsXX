#include "..\Include\Menus\Menu.h"
using namespace Menus;

Menu::Menu():
	pState(new StateMenu(this)),
	pIM(Managers::InputManager::getInstance())
{

}

Menu::~Menu()
{

}
