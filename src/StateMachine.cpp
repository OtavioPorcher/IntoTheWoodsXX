#include "..\Include\States\StateMachine.h"
using namespace States;

StateMachine::StateMachine():
	currentState(sID::empty)
{

}

StateMachine::~StateMachine()
{

}

void StateMachine::changeCurrentState(sID id_)
{
	currentState = id_;
}

void StateMachine::runCurrentState()
{
	statesMap[currentState]->Draw();
	statesMap[currentState]->Update();
}

const sID StateMachine::getCurrentStateID()const
{
	return currentState;
}

void StateMachine::addState(States::State* pS)
{
	statesMap[pS->getStateID()] = pS;
}