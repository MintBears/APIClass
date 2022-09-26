#pragma once
#include "CObj.h"

class CPlayer;
class CMonster :
    public CObj
{
public:
    CMonster();
    virtual ~CMonster();

private:

    UINT        m_HP;
    FLOAT       m_Speed;
    CObj*    m_Target;

public:

    void SetTarget(CObj* _Target)
    {
        m_Target = _Target;
    }

public:
    virtual void tick() override;
    virtual void render(HDC _dc) override;

    virtual void BeginOverlap(CCollider* _Other) override;

public:
     
};

