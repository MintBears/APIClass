#pragma once

class CEngine
{
	SINGLE(CEngine);

private:
	HWND m_hMainWnd;
	HDC	m_hDC;

public : 
	HWND GethMainWnd() { return m_hMainWnd; }

public:
	void Inst(HWND _hwnd, UINT _iWidth, UINT _iHeight);
	void progress();

private:
	void tick();
	void render();

};