#include "pch.h"
#include "CObj.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CEventMge.h"

#include "CComponent.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CRigidbody.h"

CObj::CObj()
	: m_vPos{}
	, m_vScale{}
	, m_Collider(nullptr)
	, m_Animator(nullptr)
	, m_Rigidbody(nullptr)
	, m_Dead(false)
{
}

CObj::~CObj()
{
	DEL(m_Collider);
	DEL(m_Animator);
	DEL(m_Rigidbody);
}



void CObj::tick()
{
	if (nullptr != m_Collider)
	{
		m_Collider->tick();
	}
	if (nullptr != m_Animator)
	{
		m_Animator->tick();
	}
	
}

void CObj::render(HDC _dc)
{
	if (nullptr != m_Collider)
	{
		m_Collider->render(_dc);
	}
	if (nullptr != m_Animator)
	{
		m_Animator->render(_dc);
	}
}

void CObj::SetDead()
{
	tEvent _evn = {};
	_evn.eType = EVENT_TYPE::DELETE_OBJECT;
	_evn.wParam = (DWORD_PTR)this;
	CEventMge::GetInst()->AddEvent(_evn);
}

void CObj::Instantiate(CObj* _NewObj, Vec2 _Pos, LAYER _Layer)
{
	_NewObj->SetPos(_Pos);

	tEvent _evn = {};
	_evn.eType = EVENT_TYPE::CREATE_OBJECT;
	_evn.wParam = (DWORD_PTR)_NewObj;
	_evn.lParam = (DWORD_PTR)_Layer;
	CEventMge::GetInst()->AddEvent(_evn);
}

void CObj::CreateCollider()
{
	m_Collider = new CCollider(this);

}

void CObj::CreateAnimator()
{
	m_Animator = new CAnimator(this);
}

void CObj::CreatRigidbody()
{
	m_Rigidbody = new CRigidbody(this);
}
