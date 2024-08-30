#pragma once

#include "Menu.h"

#include <vector>
#include <string>


namespace Menus
{
	class Ranking : public Menu
	{
	private:
		std::vector<std::string> RankingNameTags;
		std::vector<int> RankingScores;

		sf::Text First;
		sf::Text Second;
		sf::Text Third;
		sf::Text Fourth;
		sf::Text Fifth;
	public:
		Ranking(StateMenu* pState);
		~Ranking();

		void Draw();
		void Select();
		
		void FetchRankingData();
	};
}