#include "..\Include\Menus\MainMenu.h"
#include "..\Include\Menus\StateMenu.h"
using namespace Menus;
#include <iostream>
MainMenu::MainMenu(StateMenu* pS):Menu(pS),
	twoPlayers(false)
{
	newButton({ RES_X / 2.f, 200.f }, 40, "New Game");
	newButton({ RES_X / 2.f, 300.f }, 40, "Two Players: OFF");
	newButton({ RES_X / 2.f, 400.f }, 40, "Leaderboard");
}

MainMenu::~MainMenu()
{

}

#include "../Include/Levels/Level.h"
void MainMenu::Select()
{
	switch (hovering)
	{
	case 0:
		pState->changeState(sID::newGameMenu);
		Levels::Level::setTwoPlayers(twoPlayers);
		break;
	case 1:
		twoPlayers = !twoPlayers;
		(twoPlayers ? buttonPool[1]->setText("Two Players: ON") : buttonPool[1]->setText("Two Players: OFF"));
		break;
	case 2:
		pState->changeState(sID::leaderBoard);
		break;
	}
}

void MainMenu::Escape()
{
	pGM->closeWindow();
}