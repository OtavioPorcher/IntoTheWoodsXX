#pragma once

#include "..\States\StateMachine.h"
using namespace States;



namespace Menus
{
	class Menu;

	class StateMenu : public State
	{
	private:
		Menu* pMenu;
	public:
		StateMenu(Menu* pM, StateMachine* psm = NULL, sID id_ = sID::empty);
		~StateMenu();

		void Update();
		void Draw();
		void Reset();
	};

}