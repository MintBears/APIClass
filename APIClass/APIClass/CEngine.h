#pragma once

class CEngine
{
private:
	CEngine();
	~CEngine();

public :
	//�����̱���
	//ó������ ������ ������ �ڸ��� ���õǿ�������, �׻� �غ�Ǿ��ִ�.
	//������ �ð��� �������� �����Ͱ� �����Ǿ ���ʿ��� �����Ͱ� ����� �ִ�.
	static CEngine* GetInst()
	{
		static CEngine engine;
		return &engine;
	}

	//�����̵� �������� Ȱ��Ǵ� �̱���
	//���� ������ ������ ����� ������ ������ �ּҰ��� ������, �������� ��ü�� ��Ƶδ¹��.
	//�������� ����°� �ִٸ� ����°� �ʿ������� �ʿ��ϱ⶧���� Deleta�� ����� ����Ѵ�.
	//������ ���� �Ҽ��ֱ⿡ ������ְ�, ������ �����ִ� ������ �ؾߵȴ�.
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