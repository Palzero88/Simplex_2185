#include "AppClass.h"
#include "MyOctant.h"
#include "MyEntityManager.h"
#include "MyRigidBody.h"

using namespace Simplex;

void MyOctant::Init(void)
{
	m_uOctantCount; //current count of total octant divisions

	m_uID = 0; //defines octant by ID number stored as an argument when created
	m_uLevel = 0; //stores the level of octree it is beginning at zero
	m_uChildren = 0;// if the octant has children. 0 or 8

	m_fSize = 0.0f; //Size of the octant. Sice its a cube it is one half of the parents dimension on one side.

	m_v3Center = vector3(0.0f); //Will store the center point of the octant eqiovalent to some quarter of the parents axis
	m_v3Min = vector3(0.0f); //Will store the minimum vector of the octant
	m_v3Max = vector3(0.0f); //Will store the maximum vector of the octant

	m_pParent = nullptr;// Will store the parent of current octant stored upon creation
	m_pChild[8];//Will store the children of the current octant if it is divided.

	m_EntityList; //List of Entities under this octant (Index in Entity Manager)

	m_EntityManager = MyEntityManager::GetInstance();
	m_MeshManager = MeshManager::GetInstance();

	m_pRoot = nullptr;//Root octant, this is the firs one that was created
	m_lChild; //list of nodes that contain objects only the root will have this in a useful way because it contains all children
}

MyOctant::MyOctant(uint a_nIdealEntityCount, vector3 a_v3Center, float a_fSize)
{

}

void MyOctant::SetModelMatrix(matrix4 a_m4ModelMatrix)
{
	if (a_m4ModelMatrix == m_m4ToWorld)
		return;

	m_m4ToWorld = a_m4ModelMatrix;

	//your code goes here---------------------
	vector3 v3Corner[8];

	//make front and back squares
	v3Corner[0] = m_v3Min;
	v3Corner[1] = vector3(m_v3Max.x, m_v3Min.y, m_v3Min.z);
	v3Corner[2] = vector3(m_v3Min.x, m_v3Max.y, m_v3Min.z);
	v3Corner[3] = vector3(m_v3Max.x, m_v3Max.y, m_v3Min.z);
	v3Corner[4] = vector3(m_v3Min.x, m_v3Min.y, m_v3Max.z);
	v3Corner[5] = vector3(m_v3Max.x, m_v3Min.y, m_v3Max.z);
	v3Corner[6] = vector3(m_v3Min.x, m_v3Max.y, m_v3Max.z);
	v3Corner[7] = m_v3Max;

	//make them global
	for (uint uIndex = 0; uIndex < 8; ++uIndex)
	{
		v3Corner[uIndex] = vector3(m_m4ToWorld * vector4(v3Corner[uIndex], 1.0f));
	}

	//set them to zero
	m_v3Max = m_v3Min = v3Corner[0];

	//set global mins and maxs to be correct
	for (uint i = 0; i < m_EntityManager->GetEntityCount; ++i)
	{
		if (m_v3Max.x < m_EntityManager->GetEntityIndex(i+""))
		{
			m_v3Max.x = v3Corner[i].x;
		}

		if (m_v3Min.x > v3Corner[i].x)
		{
			m_v3Min.x = v3Corner[i].x;
		}

		if (m_v3Max.y < v3Corner[i].y)
		{
			m_v3Max.y = v3Corner[i].y;
		}

		if (m_v3Min.y > v3Corner[i].y)
		{
			m_v3Min.y = v3Corner[i].y;
		}

		if (m_v3Max.z < v3Corner[i].z)
		{
			m_v3Max.z = v3Corner[i].z;
		}

		if (m_v3Min.z > v3Corner[i].z)
		{
			m_v3Min.z = v3Corner[i].z;
		}
	}
	//----------------------------------------

	//we calculate the distance between min and max vectors
	m_fSize = m_v3Max.x - m_v3Min.x;
	this->SetSize(m_fSize);
}

float MyOctant::GetSize()
{
	return m_fSize;
}

void MyOctant::SetSize(float size)
{
	//this->m_fSize = size;
}

void MyOctant::Subdivide()
{

}

void MyOctant::ClearEntityList()
{
}

MyOctant* MyOctant::GetChild(uint a_nChild)
{
	return nullptr;
}

MyOctant* MyOctant::GetParent()
{
	return nullptr;
}

bool MyOctant::ContainsMoreThan(uint a_nEntities)
{
	return false;
}

void MyOctant::KillBranches()
{
}

vector3 MyOctant::GetMinGlobal()
{
	return vector3();
}

vector3 MyOctant::GetMaxGlobal()
{
	return vector3();
}

vector3 MyOctant::GetCenterGlobal()
{
	return vector3();
}

void MyOctant::AssignIDtoEntity()
{
}

uint MyOctant::GetOctantCount()
{
	return uint();
}

void MyOctant::Display(uint a_nIndex, vector3 a_v3Color)
{
	//m_MeshManager->AddWireCubeToRenderList(glm::translate(m_v3Center) * m_fSize), a_v3Color);
}
