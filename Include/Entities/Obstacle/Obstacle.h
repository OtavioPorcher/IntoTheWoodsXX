#pragma once

#include "..\Obstacle\Obstacle.h"
#include "..\Entity.h"

namespace Entities
{
    namespace Obstacle
    {
        class Obstacle : public Entity
        {
        protected:
            bool damage;
        public:
            Obstacle(const sf::Vector2f pos);
            ~Obstacle();
            virtual void Move() = 0;
            virtual void Update() = 0;
        };
    }
}
