#include "AEObject.h"


AEObject::AEObject()
{
}


AEObject::~AEObject()
{
}

bool AEObject::Render()
{
	if( m_ChildList.empty() )
	{
		return false;
	}

	for( auto child : m_ChildList )
	{
		child->Render();
	}

	return true;
}
