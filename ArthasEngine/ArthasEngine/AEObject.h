/*
Object >> AEObject

@Class AEObjec
->�ֻ��� ������Ʈ

@�ۼ���: �迬��
@�ۼ���: 14-8-21
@���� ������: 
@���� ������:
@���� ��������:

*/

#pragma once
#include "AEInclude.h"
#include "AERect.h"

class AEObject
{
public:
	AEObject();
	virtual ~AEObject();


public:
	virtual void		RemoveChild( AEObject* child , bool isDelete);
	virtual void		AddChild(AEObject* child);

	virtual void		SetParent( AEObject* parent );
	virtual AEObject*	GetParent() {return m_Parent;}

	virtual void		Init() = 0;
	virtual void		Render() = 0;
	virtual void		Update() = 0;
	virtual void		Clear() = 0;

	AEPoint				GetPosition() {return m_Rect.GetPoint();}
	AEPoint				GetCenter() {return m_Rect.GetCenter();}
	AESize				GetSize() {return m_Rect.GetSize();}

private:
	void				RenderAll();
	void				UpdateAll();
	void				ClearAll();

protected:
	std::list<AEObject*>	m_ChildList;
	AEObject*				m_Parent;
	AERect					m_Rect;
};

