#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"

#include "CObj.h"

CObj obj;

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

	//timeMgr 초기화
	CTimeMgr::GetInst()->init();

	//obj초기화
	obj.SetPos(Vec2(_iWidth / 2, _iHeight / 2));
	obj.SetScale(Vec2(100.f, 100.f));
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

	obj.tick();
}

void CEngine::render()
{
	obj.render(m_hDC);
	//Rectangle(m_hDC, 100, 100, 200, 200);
}