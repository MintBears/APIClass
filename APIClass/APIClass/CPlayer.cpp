#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"
#include "CEventMge.h"

#include "CLevel.h"

#include "CCollider.h"
#include "CAnimator.h"

#include "CMissile.h"



CPlayer::CPlayer():
	m_fSpeed(200.f)

{
	CreateCollider();

	GetCollider()->SetOffsetPos(Vec2(0.f, -50.f));
	GetCollider()->SetScale(Vec2(150.f, 150.f));
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
		//CLevel* CurLevel = CLevelMgr::GetInst()->GetCurLevel();

		for (int i = 0; i < 3; i++)
		{
			CMissile* Missile = new CMissile;
			Missile->SetPos(GetPos());
			Missile->SetScale(Vec2(20.F, 20.f));
			Missile->SetSpeed(400.f);
			Missile->SetDir(45.f + (45.f * (float)i));
			//�ٷ� ������ �߰��Ѵ�.
			//CurLevel->AddObject(Missile, LAYER::PLAYER_PROJECTILE);
			//����ٰ� ������ tick���� ȣ���� ������Ʈ�� �ٷ� ó�����ϰ� Event�� ���� ó���Ѵ�.
			//_evn.eType : �̺�Ʈ Ÿ�� �����ϰ�, _evn.wParam : �̺�Ʈ ���� �����ϰ�, AddEvent(_evn) : �̺�Ʈ�޴����� �ִ´�.
 			tEvent _evn = {};
			_evn.eType = EVENT_TYPE::CREATE_OBJECT;
			_evn.wParam = (DWORD_PTR)Missile;
			_evn.lParam = (DWORD_PTR)LAYER::PLAYER_PROJECTILE;
			CEventMge::GetInst()->AddEvent(_evn);
		}
	}

	SetPos(vPos);

	CObj::tick();
}

void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetScale();

	HBRUSH hOriginBrush = (HBRUSH)SelectObject(_dc, (HBRUSH)GetStockObject(NULL_BRUSH));

	Rectangle(_dc, (int)(vPos.x - vSize.x / 2.f)
				 , (int)(vPos.y - vSize.y / 2.f)
				 , (int)(vPos.x + vSize.x / 2.f)
				 , (int)(vPos.y + vSize.y / 2.f));

	SelectObject(_dc, hOriginBrush);

	CObj::render(_dc);
}

void CPlayer::BeginOverlap(CCollider* _Other)
{
	
}

void CPlayer::OnOverlap(CCollider* _Other)
{
}

void CPlayer::EndOverlap(CCollider* _Other)
{
}
