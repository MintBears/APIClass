#pragma once

class CObj;
class CComponent
{
public:
	CComponent(CObj* _Owner);
	virtual ~CComponent();

private:
	//���� �����ϰ��ִ� �ڰ� �������� �ʱ⿡ ���������� ���Ŀ� ������ �������̱⶧���� const�� ���δ�.
	CObj* const m_Owner;

public:
	CObj* GetOwner() { return m_Owner; }

public:
	virtual void tick() = 0;
	virtual void render(HDC _dc) = 0;


};