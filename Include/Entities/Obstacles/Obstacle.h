#pragma once

#include "..\Obstacles\Obstacle.h"
#include "..\Entity.h"

namespace Entities
{
    namespace Characters { class Player; }

    namespace Obstacles
    {
        class Obstacle : public Entity
        {
        protected:
            const bool solid;
        public:
            Obstacle(const bool sld, bID id_, sf::Vector2f size = { 50.0f,50.0f });
            virtual ~Obstacle();

            virtual void Update() = 0;
            void Move();
            void Draw(); //Se mudar a armadilha de urso, deixa de ser virtual e coloca a sprite nessa classe

            virtual const bool Collide(Characters::Player* pPlayer);
            virtual void updateVelMultiplier(Characters::Player* pPlayer);
        };
    }
}
