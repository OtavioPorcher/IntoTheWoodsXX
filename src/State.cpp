#include "..\Include\States\State.h"
#include "..\Include\States\StateMachine.h"
using namespace States;

State::State(StateMachine* psm, sID id_):
	pSM(psm),
	id(id_),
	isRuning(false)
{

}

State::~State()
{

}

void State::setSM(StateMachine* psm)
{
	pSM = psm;
}

const sID State::getStateID()const
{
	return id;
}

const bool State::getIsRuning()const
{
	return isRuning;
}

State* State::getPreviousState()
{
	return previousState;
}

void State::changeState(sID id_)
{
	isRuning = false;
	pSM->changeCurrentState(id_);
	previousState = this;
}

void State::Reset()	{	}

State* State::previousState(NULL);