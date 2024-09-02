#pragma once

#include "List.h"
#include "..\Entities\Entity.h"
using namespace Entities;

namespace Lists
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

		List<Entity>& getList();

		void SaveEntities(nlohmann::json& saveJson);
		//void LoadEntities(nlohmann::json& saveJson);

		int getSize();
	};
}
