#include "../include/Levels/Level.h"
using namespace Levels;

Level::Level(StateMachine* psm, sID id_) : State(psm, id_),
	pIM(pIM),
	clock()
{

}

Level::~Level()
{
}

void Level::CreatePlayer()
{
	Entities::Characters::Player* aux = new Entities::Characters::Player();
}

void Level::CreateGround()
{
	Entities::Obstacles::Ground* aux = new Entities::Obstacles::Ground();
}
