#include "pch.h"
#include "CObj.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CComponent.h"
#include "CCollider.h"
#include "CAnimator.h"

CObj::CObj():
	m_vPos{},
	m_vScale{},
	m_Collider(nullptr),
	m_Animator(nullptr)
{
}

CObj::~CObj()
{
	DEL(m_Collider);
	DEL(m_Animator);
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

void CObj::CreateCollider()
{
	m_Collider = new CCollider(this);

}

void CObj::Createanimator()
{
	//m_Animator = new CAnimator(this);
}
