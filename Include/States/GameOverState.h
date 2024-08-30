#pragma once

#include "State.h"
#include "..\Managers\GraphicManager.h"
#include <string>

namespace Observers { class TextObserver; }

namespace States
{
	class GameOverState : public State
	{
	private:
		Observers::TextObserver* pTO;
		Managers::GraphicManager* pGM;
		sf::Text GameOver;
		sf::Text Score;
		sf::Text name;
		std::string NameTag;

	public:
		GameOverState(StateMachine* pSM);
		~GameOverState();

		void Update();
		void Draw();

		void keyInput(std::string key);

		void saveLeaderboard();

	};
}
