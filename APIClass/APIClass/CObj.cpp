#include "pch.h"
#include "CObj.h"


CObj::CObj():
	m_vPos{},
	m_vScale{}
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
		vPos.x -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 1;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= 1;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += 1;
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