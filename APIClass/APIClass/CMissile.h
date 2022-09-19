#pragma once
#include "CObj.h"
class CMissile :
    public CObj
{
public:
    CMissile();
    virtual ~CMissile();

    FLOAT   m_fSpeed;
    FLOAT   m_fDegree;

public:
    void SetSpeed(FLOAT _speed) { m_fSpeed = _speed; }
    void SetDir(FLOAT _fDegree) { m_fDegree = _fDegree; }

public:
    virtual void tick() override;
    virtual void render(HDC _dc)override;
};

