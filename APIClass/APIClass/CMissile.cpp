#include "pch.h"
#include "CMissile.h"

#include "CTimeMgr.h"
#include "CCollider.h"

CMissile::CMissile():
	m_fSpeed(400.f),
	m_fDegree(80.f)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(10.f, 10.f));
}

CMissile::~CMissile()
{
}

void CMissile::tick()
{
	Vec2 vPos = GetPos();
	//vPos.y -= m_fSpeed * DT;
	float fRadian = (m_fDegree * PI) / 180.f;

	vPos.x += m_fSpeed * cosf(fRadian) * DT;
	vPos.y -= m_fSpeed * sinf(fRadian) * DT;
	SetPos(vPos);

	CObj::tick();
}

void CMissile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();
	Ellipse(_dc, (int)(vPos.x - vSize.x / 2.f)
				  , (int)(vPos.y - vSize.y / 2.f)
				  , (int)(vPos.x + vSize.x / 2.f)
				  , (int)(vPos.y + vSize.y / 2.f));

	CObj::render(_dc);
}
