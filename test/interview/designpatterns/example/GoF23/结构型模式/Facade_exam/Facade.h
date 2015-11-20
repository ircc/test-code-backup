// Facade.h: interface for the Facade class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACADE_H__793E2D0D_7F12_470D_BBA8_29750B6DC9CE__INCLUDED_)
#define AFX_FACADE_H__793E2D0D_7F12_470D_BBA8_29750B6DC9CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std; 

class Subsystem1
{
public:
	Subsystem1(){}
	~Subsystem1(){}
	void Operation()
	{
		cout<<"����һ����Ϊ.."<<endl;
	}
protected:
private:
};

class Subsystem2
{
public:
	Subsystem2(){}
	~Subsystem2(){}
	void Operation()
	{
		cout<<"���������Ϊ.."<<endl;
	}
protected:
private:
};

class Facade
{
public:
	Facade()
	{
		cout<<"�ڹ���Ĺ�������������С���󣬵�Ȼ���Ը�����Ҫ��Ʋ�ͬ��Facade"<<endl;
		this->_subs1 = new Subsystem1();
		this->_subs2 = new Subsystem2();
	} 
	~Facade()
	{
		delete _subs1;
		delete _subs2;
	}
	void OperationWrapper()
	{
		this->_subs1->Operation();
		this->_subs2->Operation();
	}
protected:
private:
	Subsystem1* _subs1;
	Subsystem2* _subs2;
};



#endif // !defined(AFX_FACADE_H__793E2D0D_7F12_470D_BBA8_29750B6DC9CE__INCLUDED_)
