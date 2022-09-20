#pragma once

struct COLLION_INFO
{
	LAYER first;
	LAYER second;
};

class CCollider;
class CCollisionMgr
{
	SINGLE(CCollisionMgr);

private:
	WORD		m_matrix[(UINT)LAYER::END];

public:
	void Clear() 
	{
		for (int i = 0; i < (UINT)LAYER::END; i++)
		{
			m_matrix[i] = 0;
		}
	}
public:
	void tick();
	void LayerCheck(LAYER _left, LAYER _right);
	

private:
	void CollisionBtwLayer(LAYER _left, LAYER _right);
	bool CollisionBtwCollider(CCollider* _left, CCollider* _right);

};

