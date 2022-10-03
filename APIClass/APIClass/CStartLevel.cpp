#include "pch.h"
#include "CStartLevel.h"

#include "CCollisionMgr.h"
#include "CResMgr.h"
#include "CKeyMgr.h"

#include "CEngine.h"
#include "CCamera.h"
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
	//택스트 로딩
	CResMgr::GetInst()->LoadTexture(L"Monster", L"texture\\magicmushroom.bmp");

	CPlayer* Player = new CPlayer;
	Player->SetPos(Vec2((FLOAT)(CEngine::GetInst()->GetResolution().x / 2), (FLOAT)(CEngine::GetInst()->GetResolution().y / 2)));
	Player->SetScale(Vec2(100.f, 100.f));
	AddObject(Player, LAYER::PLAYER);

	CMonster* Monster = new CMonster;
	Monster->SetPos(Vec2((FLOAT)(CEngine::GetInst()->GetResolution().x / 4), (FLOAT)(CEngine::GetInst()->GetResolution().y / 4)));
	Monster->SetScale(Vec2(100.f, 100.f));
	Monster->SetTarget(Player);

	AddObject(Monster, LAYER::MONSTER);


	//level의 충돌 체크
	CCollisionMgr::GetInst()->LayerCheck(LAYER::PLAYER, LAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(LAYER::PLAYER, LAYER::MONSTER_PROJECTILE);
	CCollisionMgr::GetInst()->LayerCheck(LAYER::PLAYER_PROJECTILE, LAYER::MONSTER);
	CCollisionMgr::GetInst()->LayerCheck(LAYER::MONSTER, LAYER::MONSTER);

	Vec2 Resolution = CEngine::GetInst()->GetResolution();
	CCamera::GetInst()->SetLook(Resolution/2.f);
}

void CStartLevel::tick()
{
	CLevel::tick();

	if (IsTap(KEY::ENTER))
	{
		CCamera::GetInst()->FadeOut(1.0f);
		CCamera::GetInst()->FadeIn(1.0f);
	}

}
