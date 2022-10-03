#include "pch.h"
#include "CRigidbody.h"

CRigidbody::CRigidbody(CObj* _pOwner)
	: CComponent(_pOwner)
	, m_fMass(1.0f)
{
}

CRigidbody::~CRigidbody()
{
}

void CRigidbody::tick()
{
}

void CRigidbody::render(HDC _dc)
{
}
