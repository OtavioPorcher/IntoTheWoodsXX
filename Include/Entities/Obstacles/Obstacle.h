#pragma once

#include "..\Obstacle\Obstacle.h"
#include "..\Entity.h"

namespace Entities
{
    namespace Obstacles
    {
        class Obstacle : public Entity
        {
        protected:
            
        public:
            Obstacle();
            virtual ~Obstacle();

            virtual void Move() = 0;
            virtual void Update() = 0;
            virtual void Draw() = 0; //Se mudar a armadilha de urso, deixa de ser virtual e coloca a sprite nessa classe
        };
    }
}
