// Decorator.h: interface for the Decorator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DECORATOR_H__BD8CC29F_B533_4F11_802C_E205DB0A1CC9__INCLUDED_)
#define AFX_DECORATOR_H__BD8CC29F_B533_4F11_802C_E205DB0A1CC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
using namespace std;

//�����ӿ�
class Component
{
public:
	virtual ~Component();
	virtual void Operation();
protected:
	Component();
private:
};

//ԭʼ����
class ConcreteComponent:public Component
{
public:
	ConcreteComponent();
	~ConcreteComponent();
	void Operation()
	{
		cout<<"ԭ��������..."<<endl;
	}

protected:
private:
};

//����A����
class DecoratorA:public Component
{
public:
	DecoratorA(Component* com)
	{
		this->_com = com;
	}
	virtual ~DecoratorA()
	{
		delete _com;
	}
	void Operation()
	{
		this->AddedBehavior();
		_com->Operation();		
	}
	void AddedBehavior()
	{
		cout<<"���Ӳ���A...."<<endl;
	}
protected:
	Component* _com;
private:
};

//����B����
class DecoratorB:public Component
{
public:
	DecoratorB(Component* com)
	{
		this->_com = com;
	}
	virtual ~DecoratorB()
	{
		delete _com;
	}
	void Operation()
	{		
		_com->Operation();
		this->AddedBehavior();
	}
	void AddedBehavior()
	{
		cout<<"���Ӳ���B...."<<endl;
	}
protected:
	Component* _com;
private:
};

#endif // !defined(AFX_DECORATOR_H__BD8CC29F_B533_4F11_802C_E205DB0A1CC9__INCLUDED_)
