#include "..\Include\Observers\MenuObserver.h"
using namespace Observers;
#include <iostream>
MenuObserver::MenuObserver(Menus::StateMenu* cSate) : Observer(),
	linkedState(cSate)
{
	inputSet["Up"] = "W";
	inputSet["Down"] = "S";
	inputSet["Select"] = "Enter";
	inputSet["Escape"] = "Esc";
}

MenuObserver::~MenuObserver()
{

}


void MenuObserver::notifyKeyPressed(std::string key)
{
	if (!linkedState->getIsRuning())
		return;

	for (mapIt = inputSet.begin(); mapIt != inputSet.end(); mapIt++)
	{
		if (mapIt->second == key)
		{
			if (mapIt->first == "Up")
			{
				linkedState->MoveUp();
				return;
			}
			if (mapIt->first == "Down")
			{
				linkedState->MoveDown();
				return;
			}
			if (mapIt->first == "Select")
			{
				linkedState->Select();
				return;
			}
			if (mapIt->first == "Escape")
			{
				linkedState->Escape();
				return;
			}
		}
	}
	
}

void MenuObserver::notifyKeyReleased(std::string key)
{
	  
}