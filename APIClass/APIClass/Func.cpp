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

void SaveWString(const wstring& _str, FILE* _pFile)
{
	size_t iLen = _str.length();
	fwrite(&iLen, sizeof(size_t), 1, _pFile);
	fwrite(_str.c_str(), sizeof(wchar_t), iLen, _pFile);
}

void LoadWString(wstring& _str, FILE* _pFile)
{
	size_t iLen = 0;
	fread(&iLen, sizeof(size_t), 1, _pFile);

	wchar_t szBuff[256] = {};
	fread(szBuff, sizeof(wchar_t), iLen, _pFile);
	_str = szBuff;
}
