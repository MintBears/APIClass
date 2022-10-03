#pragma once
#include "CComponent.h"
class CRigidbody :
    public CComponent
{
public:
    CRigidbody(CObj* _pOwner);
    ~CRigidbody();

private:
    float           m_fMass;        //질량
    Vec2            m_vVelocity;    //속도
    Vec2            m_vForce;       //힘

public:
    void AddForce(Vec2 _vForce)
    {
        m_vForce += _vForce;
    }

public:
    virtual void tick() override;
    virtual void render(HDC _dc) override;
    

};

