#include "../Include/Menus/StateMenu.h"
#include "../Include/Menus/Ranking.h"
using namespace Menus;

#include "../Include/Utils/TextUtils.h"

Ranking::Ranking(StateMenu* pState) : Menu(pState),
	First("", pGM->getFont(), 30),
	Second("", pGM->getFont(), 30),
	Third("", pGM->getFont(), 30),
	Fourth("", pGM->getFont(), 30),
	Fifth("", pGM->getFont(), 30),
	RankingNameTags(),
	RankingScores()
{
	newButton({ 60.f, 40.f }, 30, "Back");
	FetchRankingData();

	First.setPosition({ RES_X / 2 , 100 });
	Second.setPosition({ RES_X / 2 , 175 });
	Third.setPosition({ RES_X / 2 , 250 });
	Fourth.setPosition({ RES_X / 2 , 325 });
	Fifth.setPosition({ RES_X / 2 , 400 });

	switch (RankingNameTags.size())
	{
	case 5:
		setText(&Fifth, "5: " + std::string(RankingNameTags[4]) + " " + std::string(std::to_string(RankingScores[4])));
	case 4:
		setText(&Fourth, "4: " + std::string(RankingNameTags[3]) + " " + std::string(std::to_string(RankingScores[3])));
	case 3:
		setText(&Third, "3: " + std::string(RankingNameTags[2]) + " " + std::string(std::to_string(RankingScores[2])));
	case 2:
		setText(&Second, "2: " + std::string(RankingNameTags[1]) + " " + std::string(std::to_string(RankingScores[1])));
	case 1:
		setText(&First, "1: " + std::string(RankingNameTags[0]) + " " + std::string(std::to_string(RankingScores[0])));
	
	}
}

Ranking::~Ranking()
{

}

void Ranking::Draw()
{
	pGM->render(&First);
	pGM->render(&Second);
	pGM->render(&Third);
	pGM->render(&Fourth);
	pGM->render(&Fifth);

	for (unsigned int i = 0; i < buttonPool.size(); i++)
		buttonPool[i]->Draw();
		
}

void Ranking::Select()
{
	pState->changeState(sID::MainMenu);
}

#include <fstream>
#include <iostream>

void Ranking::FetchRankingData()
{
	std::ifstream RankingInput;
	std::string line;
	RankingInput.open("Assets/Leaderboard.txt");
	if (!RankingInput.is_open())
	{
		std::cout << "ERROR: Failed to open Leaderboard File!" << std::endl;
		exit(1);
	}
	while (std::getline(RankingInput, line))
	{
		if (!line.empty())
		{
			RankingNameTags.push_back(line.substr(0, line.find_first_of(' ')));
			RankingScores.push_back(stoi(line.substr(line.find_first_of(' ') + 1)));
		}
	}
}