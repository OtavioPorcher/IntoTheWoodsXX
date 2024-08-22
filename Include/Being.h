#pragma once
#include "Managers/GraphicManager.h"

enum class bID
{
	empty	   = -1,
	player	   =  0,
	scorpion   =  1, //Simple Enemy
	snake	   =  2, //Medium Enemy
	bear	   =  3, //Boss
	projectile =  4,
	ground	   =  5,
	grass	   =  6,
	trap	   =  7,
	menu	   =  8, 
	button	   =  9, 
	dawn	   = 10, //Lvl 1
	evening	   = 11  //Lvl 2
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
