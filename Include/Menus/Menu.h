#pragma once

#include"..\Managers\InputManager.h"
#include "..\Being.h"
#include "StateMenu.h"
namespace Menus
{

	class Menu : public Being
	{
	private:
		Managers::InputManager* pIM;
		StateMenu* pState;
	public:
		Menu();
		~Menu();

		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Reset() = 0;

	};

}