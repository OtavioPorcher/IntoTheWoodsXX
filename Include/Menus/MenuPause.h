#pragma once

#include "Menu.h"

namespace Menus
{
	class MenuPause : public Menu
	{
	private:
		sf::Text Pause;
	public:
		MenuPause(StateMenu* pSM);
		~MenuPause();

		void Select();
	};
}