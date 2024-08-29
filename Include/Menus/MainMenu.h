#pragma once

#include "Menu.h"
#include "..\States\State.h"

namespace Menus
{
	class MainMenu : public Menu
	{
	private:
		bool twoPlayers;
	public:
		MainMenu(StateMenu* pS);
		~MainMenu();

		void Select();
		void Escape();
	};
}
