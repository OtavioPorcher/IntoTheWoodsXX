#pragma once

#include "State.h"
#include <map>

namespace States
{
	class StateMachine
	{
    protected:
        States::sID currentState;
        std::map<sID, States::State*> statesMap;

    public:
        StateMachine();
        virtual ~StateMachine();

        void changeCurrentState(States::sID id_);
        void runCurrentState();
        const States::sID getCurrentStateID();
        void push_State(States::State* pS);
	};
}
