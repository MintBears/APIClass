#pragma once

#define SINGLE(type) public : static type* GetInst(){static type inst; return &inst;}\
					 private : type(); ~type();

#define DT CTimeMgr::GetInst()->GetDeltaTime()

#define IsTap(key) CKeyMgr::GetInst()->GetKeyState(key) == KEY_STATE::TAP
#define IsPressed(key) CKeyMgr::GetInst()->GetKeyState(key) == KEY_STATE::PRESSED
#define IsRelease(key) CKeyMgr::GetInst()->GetKeyState(key) == KEY_STATE::RELEASED

#define DEL(p) if (nullptr != p) delete p;
#define PI	3.1215926535f

enum class LEVEL_TYPE
{
	START,
	STAGE_01,
	STAGE_02,
	STAGE_03,
	STAGE_04,

	END,

};



















/*
public:
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
	
private:
	static CEngine* m_pInst;
public:
	static CEngine* GetInit()
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