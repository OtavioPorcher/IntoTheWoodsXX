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
	public:
		~EventManager();
		static EventManager* getInstance(); // TODO: Reestruturar os Singletons de forma a deixar a variável instance acessível somente dentro da getInstance e mantendo a Threadsafe.

		void Run();		
	};
}
