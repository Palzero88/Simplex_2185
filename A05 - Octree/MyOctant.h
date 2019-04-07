#pragma once
#include "MyEntityManager.h"
#include "AppClass.h"

namespace Simplex
{
class MyOctant
{
	static uint m_uOctantCount; //current count of total octant divisions
	static uint m_uMaxLevel; //max level of divisions allowed
	static uint m_uIdealEntityCount; //level of entities "within" or colliding with applicable octree

	uint m_uID = 0; //defines octant by ID number stored as an argument when created
	uint m_uLevel = 0; //stores the level of octree it is beginning at zero
	uint m_uChildren = 0;// if the octant has children. 0 or 8

	float m_fSize = 0.0f; //Size of the octant. Sice its a cube it is one half of the parents dimension on one side.

	vector3 m_v3Center = vector3(0.0f); //Will store the center point of the octant eqiovalent to some quarter of the parents axis
	vector3 m_v3Min = vector3(0.0f); //Will store the minimum vector of the octant
	vector3 m_v3Max = vector3(0.0f); //Will store the maximum vector of the octant

	MyOctant* m_pParent = nullptr;// Will store the parent of current octant stored upon creation
	MyOctant* m_pChild[8];//Will store the children of the current octant if it is divided.

	std::vector<uint> m_EntityList; //List of Entities under this octant (Index in Entity Manager)

	MyOctant* m_pRoot = nullptr;//Root octant, this is the firs one that was created
	std::vector<MyOctant*> m_lChild; //list of nodes that contain objects only the root will have this in a useful way because it contains all children

	vector3 m_v3HalfWidth = ZERO_V3; //half the size of octant

	matrix4 m_m4ToWorld = IDENTITY_M4; //Matrix that will take us from local to world coordinate

	MyEntityManager* m_EntityManager;
	MeshManager* m_MeshManager;

public:
	//constructor for root node
	MyOctant(uint a_nIdealEntityCount, vector3 a_v3Center, float a_fSize);

	//sets model matrix like an arbb
	void MyOctant::SetModelMatrix(matrix4 a_m4ModelMatrix);

	//returns size of one length of an octant
	float GetSize(void);
	
	//sets size
	void MyOctant::SetSize(float size);

	//creates 8 octants internally within the parent octant.
	void Subdivide(void);

	//clears the list of colliding entities
	void ClearEntityList(void);

	//returns the child for the octant with a specific index
	MyOctant* GetChild(uint a_nChild);

	//returns the parent of the octant in question
	MyOctant* GetParent(void);

	//returns true if there are more entities within the octant thatn the ideal count
	bool ContainsMoreThan(uint a_nEntities);

	//deletes children of an octant
	void KillBranches(void);

	//get the mind and max corners of the octant. Initial values determined by the min and max of the entities that were created
	vector3 GetMinGlobal(void);
	vector3 GetMaxGlobal(void);

	//get the center point of the octant determined by the min and max corners
	vector3 GetCenterGlobal(void);

	//assigns an ID value to an octant.
	void AssignIDtoEntity(void);

	//return total octant count
	uint GetOctantCount(void);

	//displays octant on screen based on index or not
	void Display(vector3 a_v3Color = C_YELLOW);
	
private:
	//initializing variables
	void Init(void);
};
}