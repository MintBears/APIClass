#pragma once
#include "CEntity.h"

class CCollider;
class CAnimator;

class CObj :
    public CEntity
{
public:
    CObj();
    virtual ~CObj();

private: 
    Vec2            m_vPos;
    Vec2            m_vScale;

    CCollider*     m_Collider;
    CAnimator*     m_Animator;


public : 
    void SetPos(Vec2 _v) { m_vPos = _v; }
    Vec2 GetPos() { return m_vPos; }

    void SetScale(Vec2 _v) { m_vScale = _v; }
    Vec2 GetScale() { return m_vScale; }


    CCollider* GetCollider() { return m_Collider; }
    CAnimator* GetCAnimator() { return m_Animator; }

public : 
    virtual void tick();
    virtual void render(HDC _dc);

    void CreateCollider();
    void Createanimator();


};

