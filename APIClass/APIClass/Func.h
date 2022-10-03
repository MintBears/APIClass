#pragma once

class CObj;
bool IsValid(CObj*& _pTarget);

void SaveWString(const wstring& _str, FILE* _pFile);
void LoadWString(wstring& _str, FILE* _pFile);