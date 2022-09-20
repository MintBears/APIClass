#pragma once
#include "CComponent.h"
class CAnimator :
    public CComponent
{
public:
    CAnimator(CObj* _Owner);
    virtual ~CAnimator();
};

