#pragma once

#include "Menu.h"
#include <list>

namespace Menus
{
	class NewGameMenu : public Menu
	{
	private:
		static bool saveLoaded;
	public:
		NewGameMenu(StateMenu* pState);
		~NewGameMenu();

		void Select();
	};
}
