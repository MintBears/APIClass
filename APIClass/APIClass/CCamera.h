#pragma once
class CCamera
{
	SINGLE(CCamera);

private:
	Vec2			m_Look;
	Vec2			m_Diff;

public:
	void SetLook(Vec2 _Look) { m_Look = _Look; }

public:
	void tick();

	Vec2 GetRenderPos(Vec2 _RealPos)
	{
		return _RealPos - m_Diff;
	}

	Vec2 GetRealPos(Vec2 _RealPos)
	{
		return _RealPos + m_Diff;
	}

};
 
