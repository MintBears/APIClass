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

	//������ : ���� ������ Ű���¸� �� tick ���� Ȯ���� �ؾߵǴ� ��Ȳ�̴�.
	//�ذ� : �̰� ���������� �������� �޴����� ���� �����ߵȴ�.
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
