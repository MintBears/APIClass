#include "pch.h"
#include "CMonster.h"

#include "CCollider.h"

CMonster::CMonster():
	m_Speed(100.f)
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
	CObj::tick();
}

void CMonster::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();
	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f)
					, (int)(vPos.y - vSize.y / 2.f)
					, (int)(vPos.x + vSize.x / 2.f)
					, (int)(vPos.y + vSize.y / 2.f));
	CObj::render(_dc);
}
