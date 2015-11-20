#include "StdAfx.h"
#include "ConcreteProductA.h"

ConcreteProductA::ConcreteProductA()
{
	cout<<"创建 A 产品"<<endl;
}
ConcreteProductA::~ConcreteProductA()
{
	cout<<"释放 A 产品"<<endl;
}
void ConcreteProductA::Function()
{
	cout<<"这时产品 A 具有的基本功能"<<endl;
}


ConcreteProductANew::ConcreteProductANew()
{
	cout<<"创建一个 新 产品"<<endl;
}
ConcreteProductANew::~ConcreteProductANew()
{
	cout<<"释放这个 新 产品"<<endl;
}
void ConcreteProductANew::Function()
{
	cout<<"这是 新产品  具有的基本功能"<<endl;
}


ConcreteProductA1::ConcreteProductA1()
{
	cout<<"创建 A1 产品"<<endl;
}
ConcreteProductA1::~ConcreteProductA1()
{
	cout<<"释放 A1 产品"<<endl;
}
void ConcreteProductA1::Function()
{
	cout<<"这时产品 A1 具有的基本功能"<<endl;
}


ConcreteProductA2::ConcreteProductA2()
{
	cout<<"创建 A2 产品"<<endl;
}
ConcreteProductA2::~ConcreteProductA2()
{
	cout<<"释放 A2 产品"<<endl;
}
void ConcreteProductA2::Function()
{
	cout<<"这时产品 A2 具有的基本功能"<<endl;
}
