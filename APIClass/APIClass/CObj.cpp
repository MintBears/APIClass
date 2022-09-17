#include "pch.h"
#include "CObj.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"


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

void CObj::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();
	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f), (int)(vPos.y - vSize.y / 2.f)
				 , (int)(vPos.x + vSize.x / 2.f), (int)(vPos.y + vSize.y / 2.f));
}