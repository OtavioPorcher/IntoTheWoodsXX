#pragma once

#include "Level.h"

namespace Levels
{
	class Dawn : public Level
	{
	private:
		bool bossesDead;
		int counterBosses;
	public:
		Dawn(StateMachine* pSM);
		~Dawn();

		void Update();
		void Reset();

		std::string getFileName();

		void CreateEntity(const char id, sf::Vector2f pos);
		void CreateBear(sf::Vector2f pos, const bool random = false);
		void CreateTrap(sf::Vector2f pos, const bool random = false);

		void bearKilled();
	};
}
