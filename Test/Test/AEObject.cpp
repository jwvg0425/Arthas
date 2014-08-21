#include "stdafx.h"
#include "AEObject.h"

AEObject::AEObject()
	:m_Parent( nullptr )
{
}


AEObject::~AEObject()
{
}


void AEObject::Render()
{
	for( auto child : m_ChildList )
	{
		child->Render();
	}

	CustomRender();
}

void AEObject::Update()
{
	for( auto child : m_ChildList )
	{
		child->Update();
	}
	CustomUpdate();
}

void AEObject::Clear()
{
	for( auto child : m_ChildList )
	{
		child->Clear();
	}
	CustomClear();
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

void AEObject::DeleteChild( AEObject* child )
{
	if( child == nullptr )
	{
		return;
	}
	m_ChildList.remove( child );
	child->Clear();
}

