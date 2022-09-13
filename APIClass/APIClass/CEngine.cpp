#include "pch.h"
#include "CEngine.h"

#include "CObj.h"

CObj obj;

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

	//obj�ʱ�ȭ
	obj.SetPos(Vec2(_iWidth / 2, _iHeight / 2));
	obj.SetScale(Vec2(100.f, 100.f));
}

void CEngine::progress()
{
	static ULONGLONG PrevCount = GetTickCount64();
	static ULONGLONG CurCount = GetTickCount64();
	static int iCallCount = 0;

	//1�� ����.
	if (CurCount - PrevCount > 1000)
	{
		wchar_t szBuff[256] = {};
		wsprintf(szBuff, L"�ʴ� CEngine :: progress �Լ� ȣ�� ȸ�� : %d", iCallCount);
		SetWindowText(m_hMainWnd, szBuff);

		//1�ʸ��� �� ����(������)
		iCallCount;

		//����
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