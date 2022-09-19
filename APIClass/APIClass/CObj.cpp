#include "pch.h"
#include "CObj.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"


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
	
}

void CObj::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();
	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f), (int)(vPos.y - vSize.y / 2.f)
				 , (int)(vPos.x + vSize.x / 2.f), (int)(vPos.y + vSize.y / 2.f));
}