#pragma once

#include "../Managers/EventManager.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Obstacles/Ground.h"
#include "../States/State.h"
#include "../Observers/PlayerInputManager.h"

namespace Levels
{
    class Level :public States::State {
    protected:
        Managers::InputManager* pIM;
        Observers::PlayerInputManager* pPim;
        Entities::Characters::Player* pPlayer;
    public:
        Level();
        virtual ~Level();
        
        virtual void Draw() = 0;
        virtual void Update() = 0;
        //Observers::PlayerInputManager* getPlayerInputManager() const;
        void CreatePlayer();
        void CreateGround();
    };
}