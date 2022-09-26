#include "pch.h"
#include "Func.h"

#include "CObj.h"

bool IsValid(CObj*& _Target)
{
	if (_Target->IsDead() || nullptr == _Target)
	{
		_Target = nullptr;
		return false;
	}

    return true;
}
