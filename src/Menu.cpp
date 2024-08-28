#include"../Include/Menus/StateMenu.h"
#include "..\Include\Menus\Menu.h"
using namespace Menus;


Menu::Menu(StateMenu* pS, bID id_): Being(id_),
	pState(pS),
	buttonPool(),
	hovering(0)
{

}

Menu::~Menu()
{

}

void Menu::MoveUp()
{
	buttonPool[hovering]->hovering(false);
	hovering++;
	hovering = hovering % buttonPool.size();
}

void Menu::MoveDown()
{
	buttonPool[hovering]->hovering(false);
	hovering--;
	if (hovering < 0)
		hovering += buttonPool.size();
}

void Menu::Close()
{
	pGM->closeWindow();
}

void Menu::Update()
{
	pGM->centerView({ RES_X/2,RES_Y/2});
	buttonPool[hovering]->hovering(true);
	
}

void Menu::Draw()
{
	for (unsigned int i = 0; i < buttonPool.size(); i++)
		buttonPool[i]->Draw();
}

void Menu::newButton(sf::Vector2f pos, unsigned int fontSize, std::string text)
{
	buttonPool.push_back(new Button(pos, fontSize, text));
}