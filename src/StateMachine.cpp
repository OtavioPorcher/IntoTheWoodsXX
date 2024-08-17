#include "..\Include\States\StateMachine.h"

States::StateMachine::StateMachine():
	currentState()
{

}

States::StateMachine::~StateMachine()
{

}

void States::StateMachine::changeCurrentState(States::sID id_)
{
	currentState = id_;
}

void States::StateMachine::runCurrentState()
{
	statesMap[currentState]->Update();
	statesMap[currentState]->Draw();
}

const States::sID States::StateMachine::getCurrentStateID()
{
	return currentState;
}

void States::StateMachine::push_State(States::State* pS)
{

}