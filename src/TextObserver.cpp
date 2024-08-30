#include "..\Include\Observers\TextObserver.h"
using namespace Observers;

TextObserver::TextObserver(States::GameOverState* pGO) : Observer(),
	linkedState(pGO)
{
	inputSet["A"] = "A";
	inputSet["B"] = "B";
	inputSet["C"] = "C";
	inputSet["D"] = "D";
	inputSet["E"] = "E";
	inputSet["F"] = "F";
	inputSet["G"] = "G";
	inputSet["H"] = "H";
	inputSet["I"] = "I";
	inputSet["J"] = "J";
	inputSet["K"] = "K";
	inputSet["L"] = "L";
	inputSet["M"] = "M";
	inputSet["N"] = "N";
	inputSet["O"] = "O";
	inputSet["P"] = "P";
	inputSet["Q"] = "Q";
	inputSet["R"] = "R";
	inputSet["S"] = "S";
	inputSet["T"] = "T";
	inputSet["U"] = "U";
	inputSet["V"] = "V";
	inputSet["W"] = "W";
	inputSet["X"] = "X";
	inputSet["Y"] = "Y";
	inputSet["Z"] = "Z";
	inputSet["Enter"] = "Enter";
	inputSet["BackSpace"] = "BackSpace";
	inputSet["Space"] = " ";
}

TextObserver::~TextObserver()
{

}

void TextObserver::notifyKeyPressed(std::string key)
{
	if (!linkedState->getIsRuning())
		return;

	for (mapIt = inputSet.begin(); mapIt != inputSet.end(); mapIt++)
	{
		if (mapIt->first == key)
		{
			linkedState->keyInput(mapIt->second);
		}
	}
}

void TextObserver::notifyKeyReleased(std::string key)
{

}
