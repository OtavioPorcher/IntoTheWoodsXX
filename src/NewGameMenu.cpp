#include "..\Include\Menus\NewGameMenu.h"
#include "..\Include\Menus\StateMenu.h"
using namespace Menus;

NewGameMenu::NewGameMenu(StateMenu* pState) : Menu(pState)
{
	newButton({ RES_X / 2, 150 }, 80, "Evening");
	newButton({ RES_X / 2, 250 }, 80, "Dawn");
	if (saveLoaded)
		newButton({ RES_X / 2, 350 }, 80, "Saved Level");
}

NewGameMenu::~NewGameMenu()
{

}

void NewGameMenu::Select()
{
	switch (hovering)
	{
	case 0:
		pState->changeState(sID::Evening);
		break;
	case 1:
		pState->changeState(sID::Dawn);
		break;
	case 2:
		//pState->changeState(sID::)
		break;
	}
}
bool NewGameMenu::saveLoaded(false);