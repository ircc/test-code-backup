#pragma once
#include "stdafx.h"
#include "Product.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

//简单工厂，此类不需要继承，直接硬编码实现生成的产品
class SimpleFactory
{
public:
	SimpleFactory(){}
public:
	~SimpleFactory(){}
public:
	Product *CreateProduct(int ProuctType);
	Product *CreateProductA();
	Product *CreateProductB();
};

//工厂模式，此模式的工厂只定义加工产品的接口，具体生成交予其继承类实现
//只有具体的继承类才确定要加工何种产品
class Factory
{
public:
	Factory(void);
public:
	virtual ~Factory(void);
public:
	virtual Product* CreateProduct(int ProductType = 0) =0;
};
//工厂实现
class ConcreteFactory1:public Factory
{
public:
	ConcreteFactory1();
public:
	virtual ~ConcreteFactory1();
public :
	Product* CreateProduct(int ProductType);
};
//新工厂，当要创建新类是实现此新工厂
class ConcreteFactory2:public Factory
{
public:
	ConcreteFactory2();
public:
	virtual ~ConcreteFactory2();
public :
	Product* CreateProduct(int ProductType);
};

//////////////////////////////////
//抽象工厂模式
class AbstractFactory
{
public:
	AbstractFactory();
public:
	virtual ~AbstractFactory();
public:
	virtual ConcreteProductA* CreateA() = 0;
	virtual ConcreteProductB* CreateB() = 0;
};
////-----
class ConcreteAbsFactory1:public AbstractFactory
{
public:
	ConcreteAbsFactory1();
public:
	virtual ~ConcreteAbsFactory1();
public:
	virtual ConcreteProductA* CreateA();
	virtual ConcreteProductB* CreateB();
};
////－－－－－
class ConcreteAbsFactory2:public AbstractFactory
{
public:
	ConcreteAbsFactory2();
public:
	virtual ~ConcreteAbsFactory2();
public:
	virtual ConcreteProductA* CreateA();
	virtual ConcreteProductB* CreateB();
};