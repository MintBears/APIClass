#include "pch.h"
#include "CCollisionMgr.h"

#include "CLevelMgr.h"

#include "CLevel.h"
#include "CObj.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr():
	m_matrix{}
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::tick()
{
	for (UINT iRow = 0; iRow < (UINT)LAYER::END; iRow++)
	{
		for (UINT iCol = iRow; iCol < (UINT)LAYER::END; iCol++)
		{
			if (!(m_matrix[iRow] & (1 << iCol)))
			{
				continue;
			}
			CollisionBtwLayer((LAYER)iRow, (LAYER)iCol);
		}
	}
}

void CCollisionMgr::LayerCheck(LAYER _left, LAYER _right)
{
	UINT iRow = (UINT)_left;
	UINT iCol = (UINT)_right;
	if (iRow > iCol)
	{
		UINT iTemp = iCol;
		iCol = iRow;
		iRow = iTemp;
	}
	
	//비트 합치기		(1 ; 가장 왼쪽을 의미, << iCol : 왼쪽에서부터 몇칸 움직일건지)
	m_matrix[iRow] |= (1 << iCol);
	
	m_matrix;


}

void CCollisionMgr::CollisionBtwLayer(LAYER _left, LAYER _right)
{
	CLevel* CorLevel = CLevelMgr::GetInst()->GetCurLevel();

	const vector<CObj*>& vecLeft = CorLevel->GetLayer(_left);
	const vector<CObj*>& vecRight = CorLevel->GetLayer(_right);

	for (size_t i = 0; i < vecLeft.size(); i++)
	{
		if (nullptr == vecLeft[i]->GetCollider())
			continue;
		
		for (size_t j = 0; j < vecRight.size(); j++)
		{
			if (nullptr == vecRight[j]->GetCollider())
				continue;

			if (vecLeft[i] == vecRight[j])
				continue;

			if (CollisionBtwCollider(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{
				//오버랩 중이다. 겹친 상태이다.
				vecLeft[i]->GetCollider()->BeginOverlap(vecRight[j]->GetCollider());
				vecRight[j]->GetCollider()->BeginOverlap(vecLeft[i]->GetCollider());
			}
			else
			{
				//떨어져있다.
				vecLeft[i]->GetCollider()->EndOverlap(vecRight[j]->GetCollider());
				vecRight[j]->GetCollider()->EndOverlap(vecLeft[i]->GetCollider());
			}
			

			//vecLeft[i]     vs    vecRight[j];
		}
	}

}

bool CCollisionMgr::CollisionBtwCollider(CCollider* _left, CCollider* _right)
{
	Vec2 LeftPos = _left->GetFinalPos();
	Vec2 LeftScale = _left->GetScale();

	Vec2 RightPos = _right->GetFinalPos();
	Vec2 RightScale = _right->GetScale();

	if (fabsf(LeftPos.x - RightPos.x) > (LeftScale.x / 2.0f + RightScale.x / 2.0f))
	{
		return false;
	}
	if (fabsf(LeftPos.y - RightPos.y) > (LeftScale.y / 2.0f + RightScale.y / 2.0f))
	{
		return false;
	}

	return true;
}
