#include "pch.h"
#include "CLevel.h"
#include "CObj.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	for (UINT i = 0; i < (UINT)LAYER::END; i++)
	{
		for (size_t j = 0; j < m_arrLayer[i].size(); j++)
		{
			DEL(m_arrLayer[i][j]);
		}
	}
	//오브젝트 삭제 

}

void CLevel::tick()
{

	for (UINT i = 0; i < (UINT)LAYER::END; i++)
	{
		for (size_t j = 0; j < m_arrLayer[i].size(); j++)
		{
			m_arrLayer[i][j]->tick();
		}
	}
}

void CLevel::render(HDC _dc)
{

	for (UINT i = 0; i < (UINT)LAYER::END; i++)
	{
		for (size_t j = 0; j < m_arrLayer[i].size(); j++)
		{
			m_arrLayer[i][j]->render(_dc);
		}
	}
}
