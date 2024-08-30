#pragma once

#include "..\Being.h"

#include "..\GraphicElements\Button.h"
#include "..\States\State.h"
#include <vector>

namespace Menus
{
	class StateMenu;

	class Menu : public Being
	{
	protected:
		StateMenu* pState;

		std::vector<Button*> buttonPool; // Circular Buffer
		int hovering;
	public:
		Menu(StateMenu* pS);
		~Menu();

		virtual void Update();
		virtual void Draw();

		void MoveUp();
		void MoveDown();
		virtual void Select() = 0;

		virtual void Escape();

		void newButton(sf::Vector2f pos, unsigned int fontSize, std::string text);
	};

}