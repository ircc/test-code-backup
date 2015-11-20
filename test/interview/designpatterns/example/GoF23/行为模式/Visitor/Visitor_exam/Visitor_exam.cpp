// Visitor_exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Element.h"
#include "Visitor.h"


int main(int argc, char* argv[])
{
	Visitor* visA = new ConcreteVisitorA();//����һ����Ϊ����
	Visitor* visB = new ConcreteVisitorB();//����һ����Ϊ����
	Element* elmA = new ConcreteElementA();//����һ��Ԫ��
	Element* elmB = new ConcreteElementB();//����һ��Ԫ��
	cout<<endl;
	elmA->Accept(visA);//Ԫ�ص��÷���
	elmA->Accept(visB);//Ԫ�ص��÷���
	elmB->Accept(visA);//Ԫ�ص��÷���
	elmB->Accept(visB);//Ԫ�ص��÷���
	return 0;
}

