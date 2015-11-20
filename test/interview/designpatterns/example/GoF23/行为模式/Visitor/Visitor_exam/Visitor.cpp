// Visitor.cpp: implementation of the Visitor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Visitor.h"
#include "Element.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void ConcreteVisitorA::VisitConcreteElementA(Element* elm)
{
	cout<<"A��Ϊ��רΪAԪ��д�ķ���"<<endl;
}

void ConcreteVisitorA::VisitConcreteElementB(Element* elm)
{
	cout<<"A��Ϊ��רΪBԪ��д�ķ���"<<endl;
}

void ConcreteVisitorB::VisitConcreteElementA(Element* elm)
{
	cout<<"B��Ϊ��רΪAԪ��д�ķ���"<<endl;
}
void ConcreteVisitorB::VisitConcreteElementB(Element* elm)
{
	cout<<"B��Ϊ��רΪBԪ��д�ķ���"<<endl;
}
