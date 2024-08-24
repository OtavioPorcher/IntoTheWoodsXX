#pragma once

#include "../Managers/EventManager.h"
#include "../Entities/Characters/Player.h"
#include "../Entities/Obstacles/Ground.h"

#include "../States/State.h"
using namespace States;

#include "../Observers/PlayerInputObserver.h"
using namespace Observers;

#include "../Utils/EntityList.h"
using namespace List;

namespace Levels
{
    class Level : public Being, public State 
    {
    protected:
        sf::Clock clock;
        float dt;

        Managers::InputManager* pIM;
        Observers::PlayerInputObserver* pPIO;

        Player* pPlayer1;
        Player* pPlayer2;

        EntityList dinamicEntities;
        EntityList staticEntities;

        //Background
        //Texture
    public:
        Level(StateMachine* psm, sID id_);
        virtual ~Level();
        
        void Draw();
        virtual void Update() = 0;
        void updateDeltaTime();
        virtual void Reset() = 0;
        //Observers::PlayerInputManager* getPlayerInputManager() const;

        void setupLevel();
        void createMap();
        virtual std::string getFileName() = 0;
        virtual void CreateEntity(char id, sf::Vector2f pos) = 0;

        void CreatePlayer(sf::Vector2f pos);
        void CreateGround(sf::Vector2f pos);
    };
}