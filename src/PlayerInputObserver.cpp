#include "..\Include\Observers\PlayerInputObserver.h"

Observers::PlayerInputObserver::PlayerInputObserver(Player* pP1, Player* pP2, States::State* cState) : Observer(),
	linkedState(cState),
	pPlayer1(pP1),
	pPlayer2(pP2),
	jumpKeyReleased1(true),
	jumpKeyReleased2(true)
{
	inputSet["Jump"] = "W";
	inputSet["Right"] = "D";
	inputSet["Left"] = "A";
	inputSet["Down"] = "S";
	inputSet["Attack"] = "E";

	inputSet2["Jump"] = "Up";
	inputSet2["Right"] = "Right";
	inputSet2["Left"] = "Left";
	inputSet2["Down"] = "Down";
	inputSet2["Attack"] = "rCtrl";
}

Observers::PlayerInputObserver::~PlayerInputObserver()
{
	inputSet.clear();
	inputSet2.clear();
	pPlayer1 = NULL;
	pPlayer2 = NULL;
}

void Observers::PlayerInputObserver::notifyKeyPressed(std::string key)
{
	if (!linkedState->getIsRuning())
		return;

	if (key == "Esc")
	{
		//linkedState->changeState(States::sID::pauseMenu);
	}

	playerInputPressed(1, key);
	if(pPlayer2)
		playerInputPressed(2, key);
}
#include <iostream>
 void Observers::PlayerInputObserver::playerInputPressed(int playerIdx, std::string key)
{
	Player* pPlayerAux = NULL;
	std::map<std::string, std::string>::iterator mapEnd;


	
	if (playerIdx == 1)
	{
		pPlayerAux = pPlayer1;
		mapIt = inputSet.begin();
		mapEnd = inputSet.end();
	}
	else if (playerIdx == 2)
	{
		pPlayerAux = pPlayer2;
		mapIt = inputSet2.begin();
		mapEnd = inputSet2.end();
	}
	else
		return;

	for (mapIt; mapIt != mapEnd; mapIt++)
	{
		if (mapIt->second == key)
		{
			if (mapIt->first == "Jump")
			{
				if ((playerIdx == 1) && (jumpKeyReleased1))
				{
					jumpKeyReleased1 = false;
					pPlayerAux->Jump();
				}
				if ((playerIdx == 2) && (jumpKeyReleased2))
				{
					jumpKeyReleased2 = false;
					pPlayerAux->Jump();
				}
				break;
			}
			if (mapIt->first == "Left")
			{
				pPlayerAux->MoveLeft(true);
				break;
			}
			if (mapIt->first == "Right")
			{
				pPlayerAux->MoveRight(true);
				break;
			}
			if (mapIt->first == "Down")
				pPlayerAux->Block(true);
		}
	}
	pPlayerAux = NULL;
}

void Observers::PlayerInputObserver::notifyKeyReleased(std::string key)
{
	if (!linkedState->getIsRuning())
		return;
	playerInputReleased(1, key);
	if (pPlayer2)
		playerInputReleased(2, key);
		
 }
void Observers::PlayerInputObserver::playerInputReleased(int playerIdx, std::string key)
{
	Player* pPlayerAux = NULL;
	std::map<std::string, std::string>::iterator mapEnd;
	
	if (playerIdx == 1)
	{
		pPlayerAux = pPlayer1;
		mapIt = inputSet.begin();
		mapEnd = inputSet.end();
	}
	else if (playerIdx == 2)
	{
		pPlayerAux = pPlayer2;
		mapIt = inputSet2.begin();
		mapEnd = inputSet2.end();
	}
	else
		return;

	for (mapIt; mapIt != mapEnd; mapIt++)
	{
		if (mapIt->second == key)
		{
			if (mapIt->first == "Jump")
			{
				if (playerIdx == 1)
					jumpKeyReleased1 = true;
				if (playerIdx == 2)
					jumpKeyReleased2 = true;

				break;
			}
			if (mapIt->first == "Left")
			{
				pPlayerAux->MoveLeft(false);
				break;
			}
			if (mapIt->first == "Right")
			{
				pPlayerAux->MoveRight(false);
				break;
			}
			if (mapIt->first == "Down")
					pPlayerAux->Block(false);
			}
		}
	pPlayerAux = NULL;
}
void Observers::PlayerInputObserver::setPlayer1(Player* pP1)
{
	if (pP1)
		pPlayer1 = pP1;
}

void Observers::PlayerInputObserver::setPlayer2(Player* pP2)
{
	if (pP2)
		pPlayer2 = pP2;
}