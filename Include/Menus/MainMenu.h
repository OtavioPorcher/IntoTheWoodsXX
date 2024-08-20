#pragma once

#include "Menu.h"
#include "..\States\State.h"

namespace Menus
{
	class MainMenu : public Menu
	{
	private:

	public:
		MainMenu(StateMenu* pS);
		~MainMenu();

		void Update();
		void Draw();
		void Reset();
	};
}
