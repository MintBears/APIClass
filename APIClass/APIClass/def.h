#pragma once

#define SINGLE(type) public : static type* GetInst(){static type inst; return &inst;}\
					 private : type(); ~type();

#define DT CTimeMgr::GetInst()->GetDeltaTime()
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