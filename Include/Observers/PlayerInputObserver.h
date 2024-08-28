#pragma once

#include "Observer.h"

#include "..\Entities\Characters\Player.h"
using namespace Entities;
using namespace Characters;

namespace Observers
{
	class PlayerInputObserver : public Observer
	{
	private:
		States::State* linkedState;

		Player* pPlayer1;
		bool jumpKeyReleased1;
		// bool attackKeyReleased1;

		Player* pPlayer2; 
		std::map<std::string, std::string> inputSet2; //Player 2 input map
		bool jumpKeyReleased2;
		// bool attackKeyReleased2;

		void playerInputPressed(int playerIdx, std::string key);
		void playerInputReleased(int playerIdx, std::string key);
	
	public:
		
		PlayerInputObserver(Player* pP1 = NULL, Player* pP2 = NULL, States::State* cState = NULL);
		~PlayerInputObserver();

		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);
		
		void setPlayer1(Player* pP1);
		void setPlayer2(Player* pP2);

	};
}
