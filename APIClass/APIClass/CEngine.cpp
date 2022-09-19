#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

//싱글톤 초기화
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

	//원도우 크기 설정
	RECT rt = { 0, 0, (LONG)_iWidth, (LONG)_iHeight};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hMainWnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0); 

	//HDC 초기화
	m_hDC = GetDC(m_hMainWnd);

	//dc 펜 설정
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	//HPEN hBlackPen = (HPEN)SelectObject(m_hDC, hGreenPen);
	//DeleteObject(hBlackPen);

	//dc 브러쉬 설정
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	//HBRUSH hWhiteBrush = (HBRUSH)SelectObject(m_hDC, hBlueBrush);
	//DeleteObject(hWhiteBrush);

	//timeMgr 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CLevelMgr::GetInst()->init();

}

void CEngine::progress()
{
	//논리적인 연산
	tick();

	//화면 랜더링 갱신
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
	//화면 클리어


	//레벨 렌더
	CLevelMgr::GetInst()->render(m_hDC);
}