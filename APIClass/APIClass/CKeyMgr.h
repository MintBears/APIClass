#pragma once


enum class KEY
	//Ű�� ����
{
	UP,
	DOWN,
	LEFT,
	RIGHR,

	Q,
	W,
	E,
	R,

	END,		//Ű ������ ���� ���� ǥ��
};

enum class KEY_STATE
	//Ű�� ���� ����
{
	TAP,		//��������
	PRESSED,	//������ִµ���
	RELEASED,	//��������
	NONE,		//�ƹ��͵� �ƴѼ���

	END,
};

struct tKeyInfo
	//Ű������ ���� ����ü
{
	KEY			key;
	KEY_STATE	state;
	bool		bPrev;
};



class CKeyMgr
{
	SINGLE(CKeyMgr);

private:

	vector<tKeyInfo>	m_vecKey;


public:
	void init();
	void tick();

public:
	KEY_STATE GetKeyState(KEY _key)
	{
		return m_vecKey[(UINT)_key].state;
	}
};

