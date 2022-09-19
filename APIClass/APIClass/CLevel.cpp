#include "pch.h"
#include "CLevel.h"
#include "CObj.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	//오브젝트 삭제
	for (size_t i = 0; i < m_vecobj.size(); i++)
	{
		DEL(m_vecobj[i]);
	}
}

void CLevel::tick()
{
	for (size_t i = 0; i < m_vecobj.size(); i++)
	{
		m_vecobj[i]->tick();
	}
}

void CLevel::render(HDC _dc)
{
	for (size_t i = 0; i < m_vecobj.size(); i++)
	{
		m_vecobj[i]->render(_dc);
	}
}
