#pragma once

#include "../Managers/EventManager.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Obstacles/Ground.h"
#include "../States/State.h"
#include "../Observers/PlayerInputManager.h"

namespace Levels
{
    class level :public States::State {
    protected:
        Managers::InputManager* pIM;
        Observers::PlayerInputManager* pPIM;
        Entities::Characters::Player* pPlayer;
        //Managers::CollisionManager* pCManager;
    public:
        Level(sf::Vector2f size = { 300.0f,50.0f });
        virtual ~Level();
        virtual void Draw() = 0;
        virtual void Update() = 0;
        Observers::PlayerInputManager* getPlayerInputManager() const;
        void CreatePlayer(const sf::Vector2f pos = sf::Vector2f(0, 0));
        void CreateGround(const sf::Vector2f pos = sf::Vector2f(0, 0));
    };
}