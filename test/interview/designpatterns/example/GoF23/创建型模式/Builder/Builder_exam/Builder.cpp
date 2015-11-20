// Builder.cpp: implementation of the Builder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Builder.h"
#include "Product.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Builder::Builder()
{

}

Builder::~Builder()
{

}

ConcreteBuilder::ConcreteBuilder()
{

}

ConcreteBuilder::~ConcreteBuilder()
{

}

void ConcreteBuilder::BuildPartA(const string& buildPara)
{
	cout<<"��Ʒ������һ��..."<<buildPara<<endl;
	pt.setPart1(buildPara);
}

void ConcreteBuilder::BuildPartB(const string& buildPara)
{
	cout<<"��Ʒ�����ڶ���..."<<buildPara<<endl;
	pt.setPart2(buildPara);
}

void ConcreteBuilder::BuildPartC(const string& buildPara)
{
	cout<<"��Ʒ����������..."<<buildPara<<endl;
	pt.setPart3(buildPara);
}

Product* ConcreteBuilder::GetProduct()
{
	BuildPartA("��һ��������");
	BuildPartB("�ڶ���������");
	BuildPartC("������������");
	cout<<"�ɹ��õ�һ����Ʒ"<<endl;
	return new Product();
}
