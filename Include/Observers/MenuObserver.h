#pragma once

#include "Observer.h"
#include "..\Menus\StateMenu.h"

namespace Observers
{
	class MenuObserver : public Observer
	{
	private:
		Menus::StateMenu* linkedState;
	public:

		MenuObserver(Menus::StateMenu* cState = NULL);
		~MenuObserver();

		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);

	};
}
