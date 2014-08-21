#pragma once
#include "AEInclude.h"
class AEObject
{
public:
	AEObject();
	virtual ~AEObject();


public:
	virtual void		Render() = 0;
	virtual void		Update() = 0;
	virtual void		Clear();

	virtual void		DeleteChild( AEObject* child );
	virtual void		AddChild(AEObject* child);

	virtual void		SetParent( AEObject* parent );
	virtual AEObject*	GetParent() {return m_Parent;}

private:
	std::list<AEObject*>	m_ChildList;
	AEObject*				m_Parent;
};

