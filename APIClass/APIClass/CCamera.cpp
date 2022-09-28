#include "pch.h"
#include "CCamera.h"

#include "CTimeMgr.h"
#include "CEngine.h"
#include "CKeyMgr.h"

CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void CCamera::tick()
{
	if (IsPressed(KEY::W))
	{
		m_Look.y -= 200.f * DT;
	}
	if (IsPressed(KEY::S))
	{
		m_Look.y += 200.f * DT;
	}
	if (IsPressed(KEY::A))
	{
		m_Look.x -= 200.f * DT;
	}
	if (IsPressed(KEY::D))
	{
		m_Look.x += 200.f * DT;
	}
	
	Vec2 Resolution = CEngine::GetInst()->GetResolution();
	Resolution /= 2.0f;

	m_Diff = m_Look - Resolution;


}
