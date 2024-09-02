#pragma once
#include "Managers/GraphicManager.h"

#include "Utils/json.hpp"
#define SAVEFILE "Assets/SavedLevel.json"

enum class bID
{
	empty	   = -1,
	player	   =  0,
	scorpion   =  1, //Simple Enemy
	snake	   =  2, //Medium Enemy
	bear	   =  3, //Boss
	projectile =  4,
	ground	   =  5,
	nest	   =  6,
	grass	   =  7,
	trap	   =  8,
	menu	   =  9, 
	button	   = 10, 
	evening	   = 11, //Lvl 1
	dawn	   = 12  //Lvl 2
};

class Being
{
private:
	const bID id;
protected:
	Managers::GraphicManager* pGM;
public:
	Being(bID id_ = bID::empty);
	virtual ~Being();

	virtual void Draw() = 0;
	virtual void Update() = 0;

	const bID getId()const;

};
