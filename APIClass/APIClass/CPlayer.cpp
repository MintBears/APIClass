#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

CPlayer::CPlayer():
	m_fSpeed(200.f)
{
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

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	CObj::render(_dc);
}
