#include "stdafx.h"
#include "Product.h"

AbstractProductA::AbstractProductA(){}
AbstractProductA::~AbstractProductA(){}
AbstractProductB::AbstractProductB(){}
AbstractProductB::~AbstractProductB(){}

ProductA1::ProductA1()
{
	cout<<"һ����ƷA..."<<endl;
}

ProductA1::~ProductA1(){}

ProductA2::ProductA2()
{
	cout<<"������ƷA..."<<endl;
}

void ProductA1::fun()
{
	cout<<"һ����ƷA����Ϊ"<<endl;
}

void ProductA2::fun()
{
	cout<<"������ƷA����Ϊ"<<endl;
}

ProductA2::~ProductA2(){}

ProductB1::ProductB1()
{
	cout<<"һ����ƷB..."<<endl;
}

ProductB1::~ProductB1(){}

ProductB2::ProductB2()
{
	cout<<"������ƷB..."<<endl;
}

void ProductB1::fun()
{
	cout<<"һ����ƷB����Ϊ"<<endl;
}

void ProductB2::fun()
{
	cout<<"������ƷB����Ϊ"<<endl;
}

ProductB2::~ProductB2(){}

