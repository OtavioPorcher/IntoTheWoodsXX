#pragma once

#include "GraphicManager.h"
#include "InputManager.h"

using namespace Managers;

namespace Managers
{
	class EventManager
	{
	private:
		EventManager();
		static EventManager* instance;

		InputManager* pIM;
		GraphicManager* pGM;


		
	};
}
