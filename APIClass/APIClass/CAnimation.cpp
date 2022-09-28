#include "pch.h"
#include "CAnimation.h"

#include "CCamera.h"
#include "CTimeMgr.h"

#include "CObj.h"
#include "CAnimator.h"
#include "CTexture.h"

CAnimation::CAnimation(CAnimator* _pAnimator)
	: m_pAnimator(_pAnimator)
	, m_vecFrm(0)
	, m_pAtlas(nullptr)
	, m_iCurFrm(0)
	, m_fAccTime(0.f)
	, m_bFinish(false)
{
}

CAnimation::~CAnimation()
{
}

void CAnimation::init(const wstring& _strName, CTexture* _pAtlas, Vec2 _vLeftTop, Vec2 _vSize, int _iMaxFrmCount, float _fDuration)
{
	SetName(_strName);
	m_pAtlas = _pAtlas;
	for (int i = 0; i < _iMaxFrmCount; i++)
	{
		tAnimFrm frm = {};
		frm.LeftTopPos = Vec2(_vLeftTop.x + (float)i * _vSize.x, _vLeftTop.y);
		frm.Duration = _fDuration;
		frm.Size = _vSize;

		m_vecFrm.push_back(frm);
	}
}

void CAnimation::tick()
{

	if (m_bFinish)
	{
		return;
	}

	m_fAccTime += DT;

	if (m_vecFrm[m_iCurFrm].Duration < m_fAccTime)
	{
		++m_iCurFrm;
		m_fAccTime = 0.f;
		if (m_vecFrm.size() <= m_iCurFrm)
		{
			m_iCurFrm = m_vecFrm.size() - 1;
			m_bFinish = true;
		}
	}



	//if (m_vecFrm.size() <= m_iCurFrm)
	//{
	//	m_iCurFrm = 0;
	//}

	m_iCurFrm;
}

void CAnimation::render(HDC _dc)
{

	CObj* pOwnerObj = m_pAnimator->GetOwner();

	Vec2 Pos = CCamera::GetInst()->GetRenderPos(pOwnerObj->GetPos());
	Vec2 Size = pOwnerObj->GetScale();

	tAnimFrm frm = m_vecFrm[m_iCurFrm];
	
	TransparentBlt(_dc
		, (int)(Pos.x - frm.Size.x / 2.0f), (int)(Pos.y - frm.Size.y / 2.0f)
		, (int)frm.Size.x, (int)frm.Size.y
		, m_pAtlas->GetDC()
		, (int)frm.LeftTopPos.x, (int)frm.LeftTopPos.y
		, (int)frm.Size.x, (int)frm.Size.y
		, RGB(255,0,255));

}
