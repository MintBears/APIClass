#pragma once
#include "CObj.h"
class CPlayer :
    public CObj
{
public:
    CPlayer();
    virtual ~CPlayer();

public:
    FLOAT   m_fSpeed;
public:

    virtual void tick() override;
    virtual void render(HDC _dc) override;
};

