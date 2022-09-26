#include "pch.h"
#include "Func.h"

#include "CObj.h"

bool IsValid(CObj*& _Target)
{
	if (nullptr == _Target)
	{
		return false;
	}
	else if (_Target->IsDead())
	{
		_Target = nullptr;
		return false; 
	}

    return true;
}
