#include "../Include/Entities/Characters/Enemies/Snake.h"
using namespace Entities;
using namespace Characters;
using namespace Enemies;

Snake::Snake(Player* pP1, Player* pP2) : Enemy({50.f, 50.f}, bID::snake),
	pPlayer1(pP1),
	pPlayer2(pP2),
	atkCDTimer(0.f)
{

}

Snake::~Snake()
{

}

void Snake::Shot()
{

}

void Snake::Move()
{

}

void Snake::Update()
{
}

void Snake::Draw()
{
}
