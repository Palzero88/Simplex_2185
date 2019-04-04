#include "AppClass.h"
#include "MyOctant.h"
#include "MyEntityManager.h"
#include "MyRigidBody.h"

using namespace Simplex;

MyOctant::MyOctant(uint a_nMaxLevel = 2, uint a_nIdealEntityCount = 5)
{
	this->m_uMaxLevel = a_nMaxLevel;
	this->m_uIdealEntityCount = a_nIdealEntityCount;
}

MyOctant::MyOctant(vector3 a_v3Center, float a_fSize)
{
	
}

float MyOctant::GetSize(void)
{
	return m_fSize;
}