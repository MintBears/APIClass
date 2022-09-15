#pragma once
#include "CEntity.h"
class CObj :
    public CEntity
{
public:
    CObj();
    ~CObj();

public : 
    Vec2   m_vPos;
    Vec2   m_vScale;
    FLOAT   m_fSpeed;

public : 
    void SetPos(Vec2 _v) { m_vPos = _v; }
    Vec2 GetPos() { return m_vPos; }

    void SetScale(Vec2 _v) { m_vScale = _v; }
    Vec2 GetScale() { return m_vScale; }

public : 
    void tick();
    void render(HDC _dc);


};

