#include "..\Include\Utils\EntityList.h"
using namespace List;

EntityList::EntityList() : 
	list()
{

}

EntityList::~EntityList()
{
	Clear();
}

void EntityList::UpdateEntities()
{
	List<Entity>::Iterator<Entity> it = list.begin();
	for (it; it != list.end(); it++)
	{
		(*it)->Update();
	}
}

void EntityList::DrawEntities()
{
	List<Entity>::Iterator<Entity> it = list.begin();
	for (it; it != list.end(); it++)
	{
		(*it)->Draw();
	}
}

void EntityList::insertFront(Entity* pE)
{
	list.insertFront(pE);
}
void EntityList::insertBack(Entity* pE)
{
	list.insertBack(pE);
}

void EntityList::Clear()
{
	list.clear();
}

void EntityList::deleteEntities()
{
	List<Entity>::Iterator<Entity> it = list.begin();
	for (it; it != list.end(); it++)
	{
		if(*it)
			delete(*it);
	}
}

int EntityList::getSize()
{
	return list.getSize();
}