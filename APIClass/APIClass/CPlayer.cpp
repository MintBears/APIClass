#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

#include "CLevel.h"

#include "CCollider.h"
#include "CAnimator.h"

#include "CMissile.h"



CPlayer::CPlayer():
	m_fSpeed(200.f)

{
	CreateCollider();

	GetCollider()->SetOffsetPos(Vec2(0.f, -50.f));
	GetCollider()->SetScale(Vec2(150.f, 150.f));
}

CPlayer::~CPlayer()
{
}

void CPlayer::tick()
{
	Vec2 vPos = GetPos();

	//문제점 : 현재 각각의 키상태를 매 tick 마다 확인을 해야되는 상황이다.
	//해결 : 이걸 종합적으로 관리해줄 메니저를 따로 만들어야된다.
	if (IsPressed(KEY::LEFT))
	{
		vPos.x -= m_fSpeed * DT;
	}

	if (IsPressed(KEY::RIGHR))
	{
		vPos.x += m_fSpeed * DT;
	}

	if (IsPressed(KEY::UP))
	{
		vPos.y -= m_fSpeed * DT;
	}

	if (IsPressed(KEY::DOWN))
	{
		vPos.y += m_fSpeed * DT;
	}

	if (IsTap(KEY::SPACE))
	{
		CLevel* CurLevel = CLevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; i++)
		{
			CMissile* Missile = new CMissile;
			Missile->SetPos(GetPos());
			Missile->SetScale(Vec2(20.F, 20.f));
			Missile->SetSpeed(400.f);
			Missile->SetDir(45.f + 45.f * (float)i);
			CurLevel->AddObject(Missile, LAYER::PLAYER_PROJECTILE);
		}
	}

	SetPos(vPos);

	CObj::tick();
}

void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();

	HBRUSH hOriginBrush = (HBRUSH)SelectObject(_dc, (HBRUSH)GetStockObject(NULL_BRUSH));

	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f)
				 , (int)(vPos.y - vSize.y / 2.f)
				 , (int)(vPos.x + vSize.x / 2.f)
				 , (int)(vPos.y + vSize.y / 2.f));

	SelectObject(_dc, hOriginBrush);

	CObj::render(_dc);
}

void CPlayer::BeginOverlap(CCollider* _Other)
{
	
}
