#include "..\Include\Being.h"

Being::Being(bID id_):
	pGM(Managers::GraphicManager::getInstance()),
	id(id_)
{

}

Being::~Being()
{

}

const bID Being::getId()const
{
	return id;
}