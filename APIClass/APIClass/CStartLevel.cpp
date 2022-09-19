#include "pch.h"
#include "CStartLevel.h"

#include "CObj.h"
#include "CPlayer.h"

CStartLevel::CStartLevel()
{
}

CStartLevel::~CStartLevel()
{
}

void CStartLevel::init()
{
	CObj* obj = new CPlayer;
	obj->SetPos(Vec2(100.f,100.f));
	obj->SetScale(Vec2(100.f, 100.f));
	AddObject(obj);

}
