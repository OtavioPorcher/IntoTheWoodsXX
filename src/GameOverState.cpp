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

void GameOverState::saveLeaderboard()
{

}