#pragma once
#include "product.h"

//��ƷA
class ConcreteProductA:public Product
{
public:
	ConcreteProductA(void);
public:
	virtual ~ConcreteProductA(void);
public:
	virtual void Function();
};
//----��ϵ�е�����
class ConcreteProductANew:public Product
{
public:	
	ConcreteProductANew(void);
public:
	virtual ~ConcreteProductANew(void);
public:
	virtual void Function();
};



class ConcreteProductA1:public ConcreteProductA
{
public:
	ConcreteProductA1(void);
public:
	virtual ~ConcreteProductA1(void);
public:
	virtual void Function();
};



class ConcreteProductA2:public ConcreteProductA
{
public:
	ConcreteProductA2(void);
public:
	virtual ~ConcreteProductA2(void);
public:
	virtual void Function();
};