#pragma once
#include "CLevel.h"
class CStartLevel :
    public CLevel
{
public:
    CStartLevel();
    ~CStartLevel();

public:
    virtual void init() override;
};

