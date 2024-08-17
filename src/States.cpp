#include "..\Include\States\State.h"
#include "..\Include\States\StateMachine.h"

States::State::State(StateMachine* psm, sID id_):
	pSM(psm),
	id(id_),
	isRuning(false)
{

}

States::State::~State()
{

}

void States::State::setSM(StateMachine* psm)
{
	pSM = psm;
}

const States::sID States::State::getStateID()const
{
	return id;
}

const bool States::State::getIsRuning()const
{
	return isRuning;
}

void States::State::changeState(sID id_)
{
	isRuning = false;
	pSM->changeCurrentState(id_);
	previousState = this;
}

States::State* States::State::previousState(NULL);