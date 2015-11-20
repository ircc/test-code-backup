#pragma once
#include "product.h"

class ConcreteProductB:public Product
{
public:
	ConcreteProductB(void);
public:
	virtual ~ConcreteProductB(void);
public:
	virtual void Function();
};


class ConcreteProductB1: public ConcreteProductB
{
public:
	ConcreteProductB1(void);
public:
	virtual ~ConcreteProductB1(void);
public:
	virtual void Function();

};

class ConcreteProductB2: public ConcreteProductB
{
public:
	ConcreteProductB2(void);
public:
	virtual ~ConcreteProductB2(void);
public:
	virtual void Function();

};