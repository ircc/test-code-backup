// Element.cpp: implementation of the Element class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Element.h"
#include "Visitor.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


void ConcreteElementA::Accept(Visitor* vis)
{
	cout<<"��������Ԫ��A�ķ�����";
	vis->VisitConcreteElementA(this);	
}
void ConcreteElementB::Accept(Visitor* vis)
{
	cout<<"��������Ԫ��B�ķ�����";
	vis->VisitConcreteElementB(this);
}
