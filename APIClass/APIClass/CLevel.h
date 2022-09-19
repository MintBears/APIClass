#pragma once
#include "CEntity.h"

class CObj;
class CLevel :
    public CEntity
{
public:
    CLevel();
    virtual ~CLevel();

private:
    vector<CObj*>   m_vecobj;

public:
    virtual void init() = 0;
    virtual void tick();
    virtual void render(HDC _dc); 

public:
    void AddObject(CObj* _obj) { m_vecobj.push_back(_obj); }

};

