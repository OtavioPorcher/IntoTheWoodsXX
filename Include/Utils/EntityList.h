#pragma once

#include "List.h"
#include "..\Entities\Entity.h"
using namespace Entities;

namespace List
{
	class EntityList
	{
	private:
		List<Entity> list;

	public:
		EntityList();
		~EntityList();

		void UpdateEntities();
		void DrawEntities();
		
		void insertFront(Entity* pE);
		void insertBack(Entity* pE);

		void Clear();
		void deleteEntities();

		//void SaveEntities();
		//void LoadEntities();

		int getSize();
	};
}
