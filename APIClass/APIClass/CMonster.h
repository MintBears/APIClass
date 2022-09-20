#pragma once
#include "CObj.h"


class CMonster :
    public CObj
{
public:
    CMonster();
    virtual ~CMonster();

private:
    FLOAT       m_Speed;

public:
    virtual void tick() override;
    virtual void render(HDC _dc) override;

    virtual void BeginOverlap(CCollider* _Other) override;
};

