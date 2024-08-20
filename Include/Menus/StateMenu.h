#pragma once

#include "..\States\StateMachine.h"
using namespace States;

#include "..\Include\Menus\MainMenu.h"

namespace Menus
{

	class StateMenu : public State
	{
	private:
		Menu* pMenu;
	public:
		StateMenu(StateMachine* psm = NULL, sID id_ = sID::empty);
		~StateMenu();

		void Update();
		void Draw();
		void Reset();
	};

}