#include "pch.h"
#include "CEngine.h"

#include "CStartLevel.h"

#include "CObj.h"
#include "CPlayer.h"
#include "CMonster.h"

CStartLevel::CStartLevel()
{
}

CStartLevel::~CStartLevel()
{
}

void CStartLevel::init()
{
	CObj* Player = new CPlayer;
	Player->SetPos(Vec2((FLOAT)(CEngine::GetInst()->GetResolution().x / 2), (FLOAT)(CEngine::GetInst()->GetResolution().y / 2)));
	Player->SetScale(Vec2(100.f, 100.f));
	AddObject(Player, LAYER::PLAYER);

	CObj* Monster = new CMonster;
	Monster->SetPos(Vec2((FLOAT)(CEngine::GetInst()->GetResolution().x / 4), (FLOAT)(CEngine::GetInst()->GetResolution().y / 4)));
	Monster->SetScale(Vec2(100.f, 100.f));
	AddObject(Monster, LAYER::MONSTER);

}
