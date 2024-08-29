#include <iostream>
#include "..\Include\Managers\InputManager.h"
using namespace Managers;

InputManager::InputManager()
{
	obsList.clear();
	keyMap.clear();
	keyMap[sf::Keyboard::A] = 'A';
	keyMap[sf::Keyboard::B] = 'B';
	keyMap[sf::Keyboard::C] = 'C';
	keyMap[sf::Keyboard::D] = 'D';
	keyMap[sf::Keyboard::E] = 'E';
	keyMap[sf::Keyboard::F] = 'F';
	keyMap[sf::Keyboard::G] = 'G';
	keyMap[sf::Keyboard::H] = 'H';
	keyMap[sf::Keyboard::I] = 'I';
	keyMap[sf::Keyboard::J] = 'J';
	keyMap[sf::Keyboard::K] = 'K';
	keyMap[sf::Keyboard::L] = 'L';
	keyMap[sf::Keyboard::M] = 'M';
	keyMap[sf::Keyboard::N] = 'N';
	keyMap[sf::Keyboard::O] = 'O';
	keyMap[sf::Keyboard::P] = 'P';
	keyMap[sf::Keyboard::Q] = 'Q';
	keyMap[sf::Keyboard::R] = 'R';
	keyMap[sf::Keyboard::S] = 'S';
	keyMap[sf::Keyboard::T] = 'T';
	keyMap[sf::Keyboard::U] = 'U';
	keyMap[sf::Keyboard::V] = 'V';
	keyMap[sf::Keyboard::W] = 'W';
	keyMap[sf::Keyboard::X] = 'X';
	keyMap[sf::Keyboard::Y] = 'Y';
	keyMap[sf::Keyboard::Z] = 'Z';
	keyMap[sf::Keyboard::Escape] = "Esc";
	keyMap[sf::Keyboard::Enter] = "Enter";
	keyMap[sf::Keyboard::Up] = "Up";
	keyMap[sf::Keyboard::Left] = "Left";
	keyMap[sf::Keyboard::Down] = "Down";
	keyMap[sf::Keyboard::Right] = "Right";
	keyMap[sf::Keyboard::Space] = "Space";
	keyMap[sf::Keyboard::LShift] = "LShift";
	keyMap[sf::Keyboard::RShift] = "RShift";
	keyMap[sf::Keyboard::LControl] = "LControl";
	keyMap[sf::Keyboard::RControl] = "RControl";
	keyMap[sf::Keyboard::BackSpace] = "BackSpace";
	keyMap[sf::Keyboard::Tab] = "Tab";
}
InputManager::~InputManager()
{
	obsList.clear();
	keyMap.clear();
	instance = NULL;
}

InputManager* InputManager::getInstance()
{
	if (!instance)
	{
		try { instance = new InputManager(); }
		catch (int error)
		{
			if (!error)
			{
				std::cout << "ERROR: Failed to Allocate Memory (InputManager)" << std::endl;
				exit(1);
			}
		}
	}
	return instance;
}

void InputManager::setObserver(Observers::Observer* pO)
{
	obsList.push_front(pO);
}

void InputManager::remObserver(Observers::Observer* pO)
{
	listIt = obsList.begin();
	for (listIt; listIt != obsList.end(); listIt++)
	{
		if ((*listIt) == pO)
		{
			obsList.erase(listIt);
			return;
		}
	}
}

void InputManager::pressedInput(sf::Event::KeyEvent key)
{
	listIt = obsList.begin();
	for (listIt; listIt != obsList.end(); listIt++)
	{
		(*listIt)->notifyKeyPressed(keyMap[key.code]);
	}
}

void InputManager::releasedInput(sf::Event::KeyEvent key)
{
	listIt = obsList.begin();
	for (listIt; listIt != obsList.end(); listIt++)
	{
		(*listIt)->notifyKeyReleased(keyMap[key.code]);
	}
}

InputManager* InputManager::instance(NULL);