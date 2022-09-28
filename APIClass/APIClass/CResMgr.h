#pragma once

class CTexture;
class CResMgr
{
	SINGLE(CResMgr);

private:
	map<wstring, CTexture*> m_mapTex;  

public:
	CTexture* FindTexture(const wstring& _Key);
	CTexture* LoadTexture(const wstring& _key, const wstring& _RelativePath);
};

