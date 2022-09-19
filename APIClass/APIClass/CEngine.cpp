#include "pch.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CLevelMgr.h"

//�̱��� �ʱ�ȭ
//CEngine* CEngine::m_pInst = nullptr;
CEngine::CEngine() :
	m_hMainWnd(nullptr),
	m_hDC(nullptr),
	m_hMemDC(nullptr),
	m_hMemBit(nullptr),
	m_Resolution{}
{
}

CEngine::~CEngine()
{
	//���� dc�� �̰ɷ� �����
	ReleaseDC(m_hMainWnd, m_hDC);

	//CreateCompatible�� ���� dc�� �̰ɷ� ������ vs���� �׷���.
	DeleteDC(m_hMemDC);
	DeleteObject(m_hMemBit);
}



void CEngine::Inst(HWND _hwnd, UINT _iWidth, UINT _iHeight)
{
	m_hMainWnd = _hwnd;

	m_Resolution.x = _iWidth;
	m_Resolution.y = _iHeight;

	//������ ũ�� ����
	RECT rt = { 0, 0, (LONG)_iWidth, (LONG)_iHeight};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hMainWnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0); 

	//HDC �ʱ�ȭ
	m_hDC = GetDC(m_hMainWnd);

	//���ֻ���ϴ� �� �귯��
	CreatPenBrush();

	//������ ��Ʈ���� ������� ������ �ػ󵵷� ����.
	m_hMemBit = CreateCompatibleBitmap(m_hDC, m_Resolution.x, m_Resolution.y);
	//���ο� dc ���� , m_hDC�� �޴����� => ������ ����ϴ� �⺻ �������� ������ ���ο� dc�� ���������
	m_hMemDC = CreateCompatibleDC(m_hDC);
	//���ο� dc�� bit�� ���� �����ش�.
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hMemDC, m_hMemBit);
	//dc�� ����鼭 �ʱ⿡ ����Ű�� bit�� ������ߵȴ�.
	DeleteObject(hPrevBit);

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
	Rectangle(m_hMemDC, -1, -1, m_Resolution.x + 1, m_Resolution.y + 1);

	//���� ����
	CLevelMgr::GetInst()->render(m_hMemDC);

	BitBlt(m_hDC, 0, 0, m_Resolution.x, m_Resolution.y, m_hMemDC, 0, 0, SRCCOPY);
}

void CEngine::CreatPenBrush()
{
	////dc �� ����
	//HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	//HPEN hBlackPen = (HPEN)SelectObject(m_hDC, hGreenPen);
	//DeleteObject(hBlackPen);
	//
	////dc �귯�� ����
	//HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	//HBRUSH hWhiteBrush = (HBRUSH)SelectObject(m_hDC, hBlueBrush);
	//DeleteObject(hWhiteBrush);
	//
	//GetStockObject(HOLLOW_BRUSH);
}
