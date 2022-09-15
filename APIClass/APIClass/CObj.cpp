#include "pch.h"
#include "CTimeMgr.h"
#include "CObj.h"


CObj::CObj():
	m_vPos{},
	m_vScale{},
	m_fSpeed(200.f)
{
}

CObj::~CObj()
{
}

void CObj::tick()
{
	Vec2 vPos = GetPos();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= m_fSpeed * DT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += m_fSpeed * DT;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= m_fSpeed * DT;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += m_fSpeed * DT;
	}

	SetPos(vPos);
}

void CObj::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();
	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f), (int)(vPos.y - vSize.y / 2.f)
				 , (int)(vPos.x + vSize.x / 2.f), (int)(vPos.y + vSize.y / 2.f));
}