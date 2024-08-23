#include <iostream>
#include "..\Include\Managers\EventManager.h"
using namespace Managers;

EventManager::EventManager():
	pGM(GraphicManager::getInstance()),
	pIM(InputManager::getInstance())
{

}

EventManager* EventManager::getInstance()
{
	if (!instance)
	{
		try { instance = new EventManager(); }
		catch (int error)
		{
			if (!error)
			{
				std::cout << "ERROR: Failed to Allocate Memory (EventManager)" << std::endl;
				exit(1);
			}
		}
	}
	return instance;
}

EventManager::~EventManager()
{
	pGM = NULL;
	pIM = NULL;
}

void EventManager::Run()
{
	sf::Event event;
	if(pGM->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			pGM->closeWindow();
		if (event.type == sf::Event::KeyPressed)
			pIM->pressedInput(event.key);
		if (event.type == sf::Event::KeyReleased)
			pIM->releasedInput(event.key);
	}
}


EventManager* EventManager::instance(NULL);