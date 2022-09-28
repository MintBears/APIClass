#include "pch.h"
#include "CResMgr.h"
#include "CPathMgr.h"

#include "CRes.h"
#include "CTexture.h"

CResMgr::CResMgr()
{
}

CResMgr::~CResMgr()
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.begin();

	for (; iter != m_mapTex.end(); iter++)
	{
		delete iter->second;
	}
}

CTexture* CResMgr::FindTexture(const wstring& _Key)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_Key);

	if (iter == m_mapTex.end())
	{
		return nullptr;
	}


	return iter->second;
}

CTexture* CResMgr::LoadTexture(const wstring& _key, const wstring& _RelativePath)
{
	CRes* Texture = FindTexture(_key);

	if (nullptr != Texture)
	{
		return (CTexture*)Texture;
	}

	wstring FindPath = CPathMgr::GetInst()->GetContentPath();
	FindPath += _RelativePath;

	Texture = new  CTexture;
	Texture->Load(FindPath);
	Texture->SetKey(_key);
	Texture->SetRelativePath(_RelativePath);

	m_mapTex.insert(make_pair(_key, (CTexture*)Texture));


	return (CTexture*)Texture;
}
