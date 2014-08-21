#pragma once
#include "AEInclude.h"
class AEObject
{
public:
	AEObject();
	virtual ~AEObject();


public:
	virtual void		DeleteChild( AEObject* child );
	virtual void		AddChild(AEObject* child);

	virtual void		SetParent( AEObject* parent );
	virtual AEObject*	GetParent() {return m_Parent;}

	virtual void		Render() = 0;
	virtual void		Update() = 0;
	virtual void		Clear() = 0;

private:
	void				RenderAll();
	void				UpdateAll();
	void				ClearAll();

protected:
	std::list<AEObject*>	m_ChildList;
	AEObject*				m_Parent;
};

