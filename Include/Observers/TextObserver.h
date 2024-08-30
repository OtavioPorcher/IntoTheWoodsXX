#pragma once

#include "Observer.h"
#include "..\States\GameOverState.h"

namespace Observers
{
	class TextObserver : public Observer
	{
	private:
		States::GameOverState* linkedState;

	public:
		TextObserver(States::GameOverState* pGO);
		~TextObserver();

		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);
	};
}
