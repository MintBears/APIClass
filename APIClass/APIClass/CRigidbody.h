#pragma once
#include "CComponent.h"
class CRigidbody :
    public CComponent
{
public:
    CRigidbody(CObj* _pOwner);
    ~CRigidbody();

private:
    float           m_fMass;        //����
    Vec2            m_vVelocity;    //�ӵ�
    Vec2            m_vForce;       //��

public:
    void AddForce(Vec2 _vForce)
    {
        m_vForce += _vForce;
    }

public:
    virtual void tick() override;
    virtual void render(HDC _dc) override;
    

};

