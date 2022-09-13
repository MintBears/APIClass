#include "pch.h"
#include "CEngine.h"

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

	//obj초기화
	obj.SetPos(Vec2(_iWidth / 2, _iHeight / 2));
	obj.SetScale(Vec2(100.f, 100.f));
}

void CEngine::progress()
{
	static ULONGLONG PrevCount = GetTickCount64();
	static ULONGLONG CurCount = GetTickCount64();
	static int iCallCount = 0;

	//1초 마다.
	if (CurCount - PrevCount > 1000)
	{
		wchar_t szBuff[256] = {};
		wsprintf(szBuff, L"초당 CEngine :: progress 함수 호출 회수 : %d", iCallCount);
		SetWindowText(m_hMainWnd, szBuff);

		//1초마다 센 숫자(프레임)
		iCallCount;

		//리셋
		iCallCount = 0;
		PrevCount = CurCount;
	}

	CurCount = GetTickCount64();

	++iCallCount;


	tick();
	render();
}

void CEngine::tick()
{
	obj.tick();
}

void CEngine::render()
{
	obj.render(m_hDC);
	//Rectangle(m_hDC, 100, 100, 200, 200);
}