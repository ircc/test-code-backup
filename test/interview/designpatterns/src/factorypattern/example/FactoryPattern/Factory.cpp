#include "StdAfx.h"
#include "Factory.h"
#include "Product.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"


Product * SimpleFactory::CreateProduct(int ProductType=0)
{
	Product *p = 0;
	switch(ProductType)
	{
	case 0:
		p= new ConcreteProductA();
		break;
	case 1:
		p= new ConcreteProductB();
		break;
	default:
		p= new ConcreteProductA();
		break;
	}
	return p;
}
Product *SimpleFactory::CreateProductA()
{
	return new ConcreteProductA();
}
Product *SimpleFactory::CreateProductB()
{
	return new ConcreteProductB();
}
//
Factory::Factory(void)
{
}

Factory::~Factory(void)
{
}

ConcreteFactory1::ConcreteFactory1()
{
}

ConcreteFactory1::~ConcreteFactory1()
{
}

Product * ConcreteFactory1::CreateProduct(int ProductType = 0)
{
	Product *p = 0;
	switch(ProductType)
	{
	case 0:
		p= new ConcreteProductA();
		break;
	case 1:
		p= new ConcreteProductB();
		break;
	default:
		p= new ConcreteProductA();
		break;
	}
	return p;
}


ConcreteFactory2::ConcreteFactory2()
{
}

ConcreteFactory2::~ConcreteFactory2()
{
}

Product * ConcreteFactory2::CreateProduct(int ProductType = 0)
{
	
	return new ConcreteProductANew();

}


AbstractFactory::AbstractFactory()
{
}
AbstractFactory::~AbstractFactory()
{
}


ConcreteAbsFactory1::ConcreteAbsFactory1()
{
}
ConcreteAbsFactory1::~ConcreteAbsFactory1()
{
}
ConcreteProductA* ConcreteAbsFactory1::CreateA()
{
	return new ConcreteProductA1();
}
ConcreteProductB * ConcreteAbsFactory1::CreateB()
{
	return new ConcreteProductB1();
}


ConcreteAbsFactory2::ConcreteAbsFactory2()
{
}
ConcreteAbsFactory2::~ConcreteAbsFactory2()
{
}
ConcreteProductA* ConcreteAbsFactory2::CreateA()
{
	return new ConcreteProductA2();
}
ConcreteProductB * ConcreteAbsFactory2::CreateB()
{
	return new ConcreteProductB2();
}