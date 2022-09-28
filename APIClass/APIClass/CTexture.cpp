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
	//bitmap �ε�
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(m_hBit, sizeof(BITMAP), &m_BitmapInfo);
	//bitmap �� ���� ��ų dc ����


	m_hDC = CreateCompatibleDC(CEngine::GetInst(	)->GetMainDC());
	//���ο� dc�� bit�� ���� �����ش�.
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	//dc�� ����鼭 �ʱ⿡ ����Ű�� bit�� ������ߵȴ�.
	DeleteObject(hPrevBit);

	return S_OK;
}
