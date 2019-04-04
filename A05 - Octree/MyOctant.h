#pragma once
#include "MyEntityManager.h"

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

public:
	float GetSize(void);
};
}