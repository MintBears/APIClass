#pragma once

class CEngine
{
private:
	CEngine();
	~CEngine();

public :
	//정적싱글톤
	//처음부터 데이터 영역에 자리가 마련되여있으며, 항상 준비되어있다.
	//하지만 시간이 지날수록 데이터가 누적되어서 불필요한 데이터가 생길수 있다.
	static CEngine* GetInst()
	{
		static CEngine engine;
		return &engine;
	}

	//정적이되 동적으로 활용되는 싱글톤
	//정적 포인터 변수를 만들어 데이터 영역에 주소값을 저장후, 힙영역에 객체를 담아두는방식.
	//힙영역에 만드는게 있다면 지우는게 필연적으로 필요하기때문에 Deleta를 만들어 줘야한다.
	//하지만 관리 할수있기에 만들수있고, 일일이 지워주는 관리를 해야된다.
	/*
private:
	static CEngine* m_pInst;
public:
	static CEngine* GetInst()
	{
		if (nullptr == m_pInst)
		{
			m_pInst = new CEngine;
		}
		return m_pInst;
	}
	static void Delete()
	{
		if (nullptr != m_pInst)
		{
			delete m_pInst;
			m_pInst = nullptr;

		}
	}
	*/
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