#include "pch.h"
#include "CTexture.h"
#include "CEngine.h"

CTexture::CTexture()
	: m_hBit(nullptr)
	, m_hDC(nullptr)
	, m_BitmapInfo{}
{
}

CTexture::~CTexture()
{
	DeleteObject(m_hBit);
	DeleteDC(m_hDC);
}

int CTexture::Load(const wstring& _strFilePath)
{
	//bitmap 로딩
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(m_hBit, sizeof(BITMAP), &m_BitmapInfo);
	//bitmap 과 연결 시킬 dc 생성


	m_hDC = CreateCompatibleDC(CEngine::GetInst(	)->GetMainDC());
	//새로운 dc와 bit를 연결 시켜준다.
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	//dc를 만들면서 초기에 가르키던 bit를 지워줘야된다.
	DeleteObject(hPrevBit);

	return S_OK;
}
