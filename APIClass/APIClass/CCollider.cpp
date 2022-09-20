#include "pch.h"
#include "CCollider.h"

#include "CEngine.h"
#include"CObj.h"

CCollider::CCollider(CObj* _Owner) :
	CComponent(_Owner),
	m_OffsetPos(),
	m_FinalPos()
{
}

CCollider::~CCollider()
{
}

void CCollider::tick()
{
	m_FinalPos = GetOwner()->GetPos() + m_OffsetPos;
}

void CCollider::render(HDC _dc)
{
	m_FinalPos;
	m_Scale;

	//��� �귯���� �����
	//HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	//HBRUSH hNullBrush = (HBRUSH)GetStockObject(NULL_BRUSH);

	HPEN hPen = nullptr;

	if (m_bOverlap)
	{
		hPen = CEngine::GetInst()->GetPen(PEN_TYPE::GREEN);
	}
	else
	{
		hPen = CEngine::GetInst()->GetPen(PEN_TYPE::RED);
	}


	//���� ��� �귯�ø� ���� ������ �͵�� ���۴�.
	HPEN hOriginPen = (HPEN)SelectObject(_dc, hPen);
    HBRUSH hOriginBrush = (HBRUSH)SelectObject(_dc, (HBRUSH)GetStockObject(NULL_BRUSH));

	Rectangle(_dc, (int)(m_FinalPos.x - m_Scale.x / 2.f)
			   	 , (int)(m_FinalPos.y - m_Scale.y / 2.f)
				 , (int)(m_FinalPos.x + m_Scale.x / 2.f)
				 , (int)(m_FinalPos.y + m_Scale.y / 2.f));
	//�ٽ� ����ġ
	SelectObject(_dc, hOriginPen);
	SelectObject(_dc, hOriginBrush);

	//���� ���� �� ����
	//DeleteObject(hGreenPen);
}

void CCollider::BeginOverlap(CCollider* _Other)
{
	m_bOverlap = true;

	GetOwner()->BeginOverlap(_Other);
}

void CCollider::EndOverlap(CCollider* _Other)
{
	m_bOverlap = false;
}
