#pragma once

#include "..\States\StateMachine.h"
using namespace States;

#include "MainMenu.h"
#include "NewGameMenu.h"

#include "..\Managers\InputManager.h"
namespace Observers { class MenuObserver; }

namespace Menus
{

	class StateMenu : public State
	{
	private:
		Menu* pMenu;
		Managers::InputManager* pIM;
		Observers::MenuObserver* pMO;
	public:
		StateMenu(StateMachine* psm = NULL, sID id_ = sID::empty);
		~StateMenu();

		void Update();
		void Draw();

		void MoveUp();
		void MoveDown();
		void Select();
		void Escape();

	};

}