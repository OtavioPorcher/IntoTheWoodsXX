#include "../Include/Menus/MenuPause.h"
using namespace Menus;

#include "../Include/Menus/StateMenu.h"

#include "../Include/Levels/Level.h"

MenuPause::MenuPause(StateMenu* pSM) : Menu(pSM),
	Pause("Pause", pGM->getFont(), 50)
{
	Pause.setPosition({ RES_X / 2.F , 100 });

	newButton({ RES_X / 2.f, 200.f }, 40, "Resume");
	newButton({ RES_X / 2.f, 300.f }, 40, "Save");
	newButton({ RES_X / 2.f, 400.f }, 40, "Exit");
}

MenuPause::~MenuPause()
{

}

void MenuPause::Select()
{
	switch (hovering)
	{
	case 0:
		pState->changeState(pState->getPreviousState()->getStateID());
		break;
	case 1:
		//static_cast<Levels::Level*>(pState->getPreviousState())->saveLevel();
		break;
	case 2:
		pGM->closeWindow();
		break;
	}
}
