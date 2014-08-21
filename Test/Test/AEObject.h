#pragma once
#include <list>

class AEObject
{
public:
	AEObject();
	virtual ~AEObject();


public:
	virtual void		Render();
	virtual void		Update();
	virtual void		Clear();

	virtual void		CustomRender() = 0;
	virtual void		CustomUpdate() = 0;
	virtual void		CustomClear() = 0;


	virtual void		DeleteChild( AEObject* child );
	virtual void		AddChild( AEObject* child );

	virtual void		SetParent( AEObject* parent );
	virtual AEObject*	GetParent()
	{
		return m_Parent;
	}

protected:
	std::list<AEObject*>	m_ChildList;
	AEObject*				m_Parent;
};

