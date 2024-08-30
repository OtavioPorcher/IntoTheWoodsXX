#include "..\Include\States\GameOverState.h"
using namespace States;

#include "..\Include\Levels\Level.h"
#include "..\Include\Managers\InputManager.h"
#include "..\Include\Observers\TextObserver.h"

void setText(sf::Text* text, std::string txt);

GameOverState::GameOverState(StateMachine* pSM) : State(pSM, sID::gameOver),
pGM(Managers::GraphicManager::getInstance()),
pTO(NULL),
GameOver("", pGM->getFont(), 50),
name("",pGM->getFont(), 30),
Score("", pGM->getFont(), 30)
{
	Managers::InputManager* pIM = Managers::InputManager::getInstance();
	try { pTO = new Observers::TextObserver(this); }
	catch (int error)
	{
		if (!error)
		{
			std::cout << "ERROR: Failed to Allocate Memory (TextObserver)" << std::endl;
			exit(1);
		}
	}
	if (pTO)
		pIM->setObserver(static_cast<Observers::Observer*> (pTO));

	GameOver.setPosition({ RES_X / 2 , 100 });
	Score.setPosition({ RES_X / 2 , 200 });
	name.setPosition({ RES_X / 2 , 300 });

	setText(&GameOver, "Game Over");
	
	GameOver.setFillColor(sf::Color::White);
	Score.setFillColor(sf::Color::White);
	name.setFillColor(sf::Color::White);
}

GameOverState::~GameOverState()
{

}

void setText(sf::Text* text, std::string txt)
{
	text->setString(txt);

	sf::FloatRect aux = text->getLocalBounds();
	text->setOrigin(aux.width / 2, aux.height / 2);
}

void GameOverState::Update()
{
	if (!isRuning)
		isRuning = true;
	pGM->centerView({ RES_X / 2,RES_Y / 2 });
	setText(&name, NameTag);
	setText(&Score, std::to_string(Levels::Level::getPoints()));

}

void GameOverState::Draw()
{
	pGM->render(&GameOver);
	pGM->render(&Score);
	pGM->render(&name);
}

void GameOverState::keyInput(std::string key)
{
	if (key == "Enter")
	{
		saveLeaderboard();
		return;
	}
	if (key == "BackSpace")
	{
		NameTag.pop_back();
		return;
	}
	
	NameTag.append(key);
}

#include <fstream>
#include <vector>

void InsertionSort(std::vector<int>& Scores, std::vector<std::string>& Names);

void GameOverState::saveLeaderboard()
{
	std::vector<std::string> rankingNameTags;
	std::vector<int> rankingScores;

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
			rankingNameTags.push_back(line.substr(0, line.find_first_of(' ')));
			rankingScores.push_back(stoi(line.substr(line.find_first_of(' ') + 1)));
		}
	}
	
	rankingNameTags.push_back(NameTag);
	rankingScores.push_back(Levels::Level::getPoints());

	InsertionSort(rankingScores, rankingNameTags);

	std::ofstream RankingOutput;
	RankingOutput.open("Assets/Leaderboard.txt");
	for (int i = 0; i < rankingScores.size(); i++)
	{
		RankingOutput << rankingNameTags[i] << " " << rankingScores[i] << std::endl;
	}
	RankingOutput.close();

	pGM->closeWindow();
}


void swap(std::vector<int>& A, int i, int j, std::vector<std::string>& B)
{
	int auxInt = A[i]; // Troca a posição das pontuações
	A[i] = A[j];
	A[j] = auxInt;

	std::string auxString = B[i]; // Troca a posição dos nomes 
	B[i] = B[j];
	B[j] = auxString;
}

void InsertionSort(std::vector<int>& Scores, std::vector<std::string>& Names)
{
	unsigned int i, j, key;
	for (i = 1; i < Scores.size(); i++)
	{
		j = i;
		while ((j > 0) && (Scores[j] > Scores[j - 1]))
		{
			swap(Scores, j, j - 1, Names);
			j = j - 1;
		}
	}
}