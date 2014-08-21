#include "AEObject.h"


AEObject::AEObject()
	:m_Parent(nullptr)
{
}


AEObject::~AEObject()
{
}


void AEObject::RenderAll()
{
	Render();
	for( auto child : m_ChildList )
	{
		child->RenderAll();
	}
}

void AEObject::UpdateAll()
{
	Update();
	for( auto child : m_ChildList )
	{
		child->UpdateAll();
	}
}

void AEObject::ClearAll()
{
	for( auto child : m_ChildList )
	{
		child->ClearAll();
	}
	Clear();
}

void AEObject::SetParent( AEObject* parent )
{
	if( parent == nullptr )
	{
		return;
	}
	m_Parent = parent;
}

void AEObject::AddChild( AEObject* child )
{
	if( child == nullptr )
	{
		return;
	}
	child->SetParent( this );
	m_ChildList.push_back( child );
}

void AEObject::RemoveChild( AEObject* child , bool isDelete)
{
	if( child == nullptr )
	{
		return;
	}
	m_ChildList.remove( child );

	if( isDelete )
	{
		child->ClearAll();
	}
}

