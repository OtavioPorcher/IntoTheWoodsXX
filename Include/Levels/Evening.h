#pragma once

#include "Level.h"

namespace Levels
{
	class Evening : public Level
	{
	private:
		float levelTimer;
	public:
		Evening(StateMachine* psm);
		~Evening();

		std::string getFileName();

		void Update();
		void Reset();

		void CreateEntity(char id, sf::Vector2f pos);
		void CreateScorpion(sf::Vector2f pos, const bool random = false);
		void CreateNest(sf::Vector2f pos, const bool random = false);
	};
}
