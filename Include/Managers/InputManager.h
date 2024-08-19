#pragma once

#include <map>
#include <list>
#include <SFML\Graphics.hpp>
#include"..\Observers\Observer.h"

namespace Managers
{
	class InputManager
	{
	private:
		static InputManager* instance;
		InputManager();

		std::map<sf::Keyboard::Key, std::string> keyMap;
		std::map<sf::Keyboard::Key, std::string>::const_iterator mapIt;

		std::list<Observers::Observer*> obsList;
		std::list<Observers::Observer*>::const_iterator listIt;
		
	public:
		static InputManager* getInstance();
		~InputManager();

		void setObserver(Observers::Observer* pO);
		void remObserver(Observers::Observer* pO);

		void pressedInput(sf::Event::KeyEvent key);
		void releasedInput(sf::Event::KeyEvent key);
	};
}
