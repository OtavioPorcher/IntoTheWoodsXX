#pragma once

#include "../Managers/EventManager.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Obstacles/Ground.h"
#include "../States/State.h"
using namespace States;
#include "../Observers/PlayerInputObserver.h"

namespace Levels
{
    class Level :public State {
    protected:
        sf::Clock clock;
        Managers::InputManager* pIM;
        Observers::PlayerInputObserver* pPIO;

        Player* pPlayer1;
        Player* pPlayer2;
    public:
        Level(StateMachine* psm, sID id_);
        virtual ~Level();
        
        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual void Reset() = 0;
        //Observers::PlayerInputManager* getPlayerInputManager() const;
        virtual void createMap() = 0;
        void CreatePlayer();
        void CreateGround();
    };
}