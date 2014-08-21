#include "AEObject.h"


AEObject::AEObject()
	:m_Parent(nullptr)
{
}


AEObject::~AEObject()
{
}

void AEObject::Delete()
{
	m_ChildList.clear();
}

void AEObject::RenderChildren()
{
	for( auto child : m_ChildList )
	{
		child->RenderChildren();
	}
	Render();
}

void AEObject::UpdateChildren()
{
	for( auto child : m_ChildList )
	{
		child->UpdateChildren();
	}
	Update();
}

void AEObject::DeleteChildren()
{
	for( auto child : m_ChildList )
	{
		child->DeleteChildren();
	}
	Delete();
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
}

