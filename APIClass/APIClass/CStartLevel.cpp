#include "pch.h"
#include "CStartLevel.h"

#include "CCollisionMgr.h"

#include "CEngine.h"
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
	CPlayer* Player = new CPlayer;
	Player->SetPos(Vec2((FLOAT)(CEngine::GetInst()->GetResolution().x / 2), (FLOAT)(CEngine::GetInst()->GetResolution().y / 2)));
	Player->SetScale(Vec2(100.f, 100.f));
	AddObject(Player, LAYER::PLAYER);

	CMonster* Monster = new CMonster;
	Monster->SetPos(Vec2((FLOAT)(CEngine::GetInst()->GetResolution().x / 4), (FLOAT)(CEngine::GetInst()->GetResolution().y / 4)));
	Monster->SetScale(Vec2(100.f, 100.f));
	Monster->SetTarget(Player);

	AddObject(Monster, LAYER::MONSTER);


	//level�� �浹 üũ
	CCollisionMgr::GetInst()->LayerCheck(LAYER::PLAYER, LAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(LAYER::PLAYER, LAYER::MONSTER_PROJECTILE);
	CCollisionMgr::GetInst()->LayerCheck(LAYER::PLAYER_PROJECTILE, LAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(LAYER::MONSTER, LAYER::MONSTER);
}
