#include "..\Include\Menus\MainMenu.h"
#include "..\Include\Menus\StateMenu.h"
using namespace Menus;
#include <iostream>
MainMenu::MainMenu(StateMenu* pS):Menu(pS, bID::menu),
	twoPlayers(false)
{
	newButton({ RES_X / 2.f - 90.f, 100.f }, 30, "New Game");
	newButton({ RES_X / 2.f - 120.f, 300.f }, 30, "Two Players: OFF");
}

MainMenu::~MainMenu()
{

}

#include "..\Levels\Level.h"
void MainMenu::Select()
{
	switch (hovering)
	{
	case 0:
		pState->changeState(sID::Evening);
		break;
	case 1:
		twoPlayers = !twoPlayers;
		(twoPlayers ? buttonPool[1]->setText("Two Players: ON") : buttonPool[1]->setText("Two Players: OFF"));
		Levels::Level::setTwoPlayers(twoPlayers);
		break;
	}
}