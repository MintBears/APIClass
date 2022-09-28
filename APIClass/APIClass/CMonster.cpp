#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"

#include "CPlayer.h"
#include "CCollider.h"

CMonster::CMonster()
	: m_HP(3)
	, m_Speed(100.f)
	, m_Target(nullptr)
{
	CreateCollider();
	//Vec2 scale = Vec2(GetScale().x + 10.f, GetScale().y + 10.f);

	GetCollider()->SetScale(Vec2(150.f, 150.f));
	
}

CMonster::~CMonster()
{
}

void CMonster::tick()
{
	if (IsValid(m_Target))
	{
		Vec2 TargetPos = m_Target->GetPos();
		m_Target->SetName(L"Player");
		Vec2 ThisPos = GetPos();

		Vec2 Dir = 	TargetPos - ThisPos;
		Dir.Normalize();

		ThisPos.x += Dir.x * m_Speed * DT;
		ThisPos.y += Dir.y * m_Speed * DT;

		SetPos(ThisPos);
	}
	CObj::tick();
}

void CMonster::render(HDC _dc)
{
	Vec2 vPos = CCamera::GetInst()->GetRenderPos(GetPos());
	Vec2 vSize = GetScale();

	HBRUSH hOriginBrush = (HBRUSH)SelectObject(_dc, (HBRUSH)GetStockObject(NULL_BRUSH));

	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f)
					, (int)(vPos.y - vSize.y / 2.f)
					, (int)(vPos.x + vSize.x / 2.f)
					, (int)(vPos.y + vSize.y / 2.f));

	SelectObject(_dc, hOriginBrush);
	CObj::render(_dc);
}

void CMonster::BeginOverlap(CCollider* _Other)
{
	SetDead();
	_Other;
}
