#include "StdAfx.h"
#include "ConcreteProductB.h"

ConcreteProductB::ConcreteProductB()
{
	cout<<"创建 B 产品"<<endl;
}
ConcreteProductB::~ConcreteProductB()
{
	cout<<"释放 B 产品"<<endl;
}
void ConcreteProductB::Function()
{
	cout<<"这时产品 B 具有的基本功能"<<endl;
}

ConcreteProductB1::ConcreteProductB1()
{
	cout<<"创建 B1 产品"<<endl;
}
ConcreteProductB1::~ConcreteProductB1()
{
	cout<<"释放 B1 产品"<<endl;
}
void ConcreteProductB1::Function()
{
	cout<<"这时产品 B1 具有的基本功能"<<endl;
}

ConcreteProductB2::ConcreteProductB2()
{
	cout<<"创建 B2 产品"<<endl;
}
ConcreteProductB2::~ConcreteProductB2()
{
	cout<<"释放 B2 产品"<<endl;
}
void ConcreteProductB2::Function()
{
	cout<<"这时产品 B2 具有的基本功能"<<endl;
}

