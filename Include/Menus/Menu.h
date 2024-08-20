#pragma once

#include"..\Managers\InputManager.h"
#include "..\Being.h"

namespace Menus
{
	class StateMenu;

	class Menu : public Being
	{
	private:
		Managers::InputManager* pIM;
		StateMenu* pState;
	public:
		Menu(StateMenu* pS);
		~Menu();

		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Reset() = 0;

	};

}