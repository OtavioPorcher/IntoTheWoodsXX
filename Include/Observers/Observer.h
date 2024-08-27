#pragma once

#include "..\States\State.h"

#include <string>
#include <map>

namespace Observers
{
    class Observer
    {
    protected:
        States::State* linkedState;

        std::map<std::string, std::string> inputSet;
        std::map<std::string, std::string>::iterator mapIt;
    public:
        Observer(States::State* cState);
        virtual ~Observer();

        virtual void notifyKeyPressed(std::string key) = 0;
        virtual void notifyKeyReleased(std::string key) = 0;
    
    };
}
