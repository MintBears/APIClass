#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

//�̱��� �ʱ�ȭ
//CEngine* CEngine::m_pInst = nullptr;
CEngine::CEngine() :
	m_hMainWnd(nullptr),
	m_hDC(nullptr)
{
}

CEngine::~CEngine()
{
	ReleaseDC(m_hMainWnd, m_hDC);
}



void CEngine::Inst(HWND _hwnd, UINT _iWidth, UINT _iHeight)
{
	m_hMainWnd = _hwnd;

	//������ ũ�� ����
	RECT rt = { 0, 0, (LONG)_iWidth, (LONG)_iHeight};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hMainWnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0); 

	//HDC �ʱ�ȭ
	m_hDC = GetDC(m_hMainWnd);

	//dc �� ����
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	//HPEN hBlackPen = (HPEN)SelectObject(m_hDC, hGreenPen);
	//DeleteObject(hBlackPen);

	//dc �귯�� ����
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	//HBRUSH hWhiteBrush = (HBRUSH)SelectObject(m_hDC, hBlueBrush);
	//DeleteObject(hWhiteBrush);

	//timeMgr �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CLevelMgr::GetInst()->init();

}

void CEngine::progress()
{
	//������ ����
	tick();

	//ȭ�� ������ ����
	render();
}

void CEngine::tick()
{
	CTimeMgr::GetInst()->tick();
	CKeyMgr::GetInst()->tick();
	CLevelMgr::GetInst()->tick();

}

void CEngine::render()
{
	//ȭ�� Ŭ����


	//���� ����
	CLevelMgr::GetInst()->render(m_hDC);
}