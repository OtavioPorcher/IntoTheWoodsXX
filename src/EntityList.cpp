#include "..\Include\Utils\EntityList.h"
using namespace Lists;

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
		if((*it)->getActive())
			(*it)->Update();
	}
}

void EntityList::DrawEntities()
{
	List<Entity>::Iterator<Entity> it = list.begin();
	for (it; it != list.end(); it++)
	{
		if ((*it)->getActive())
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

List<Entities::Entity>& EntityList::getList()
{
	return list;
}

void Lists::EntityList::SaveEntities()
{
	List<Entity>::Iterator<Entity> it = list.begin();
	for (it; it != list.end(); it++)
	{
		//if ((*it)->getActive())
			//(*it)->Save();
	}
}

int EntityList::getSize()
{
	return list.getSize();
}