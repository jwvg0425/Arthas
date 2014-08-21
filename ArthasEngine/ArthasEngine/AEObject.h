#pragma once
#include "AEInclude.h"
class AEObject
{
public:
	AEObject();
	virtual ~AEObject();


public:
	virtual bool		Render();
	virtual bool		Update();
	virtual bool		Delete();
	virtual AEObject*	GetParent();

private:
	std::list<AEObject*> m_ChildList;
	AEObject* m_Parent;
};

