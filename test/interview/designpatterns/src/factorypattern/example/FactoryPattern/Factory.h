#pragma once
#include "stdafx.h"
#include "Product.h"
#include "ConcreteProductA.h"
#include "ConcreteProductB.h"

//�򵥹��������಻��Ҫ�̳У�ֱ��Ӳ����ʵ�����ɵĲ�Ʒ
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

//����ģʽ����ģʽ�Ĺ���ֻ����ӹ���Ʒ�Ľӿڣ��������ɽ�����̳���ʵ��
//ֻ�о���ļ̳����ȷ��Ҫ�ӹ����ֲ�Ʒ
class Factory
{
public:
	Factory(void);
public:
	virtual ~Factory(void);
public:
	virtual Product* CreateProduct(int ProductType = 0) =0;
};
//����ʵ��
class ConcreteFactory1:public Factory
{
public:
	ConcreteFactory1();
public:
	virtual ~ConcreteFactory1();
public :
	Product* CreateProduct(int ProductType);
};
//�¹�������Ҫ����������ʵ�ִ��¹���
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
//���󹤳�ģʽ
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
////����������
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