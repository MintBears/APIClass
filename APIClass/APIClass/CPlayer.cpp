#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

#include "CLevel.h"
#include "CMissile.h"

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
			CurLevel->AddObject(Missile);
		}
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	CObj::render(_dc);
}
