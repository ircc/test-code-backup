// Flyweight.h: interface for the Flyweight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLYWEIGHT_H__C538340B_3718_46A1_8C18_4773CFC166C0__INCLUDED_)
#define AFX_FLYWEIGHT_H__C538340B_3718_46A1_8C18_4773CFC166C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std;
#include "string"
using namespace std;

class Flyweight
{
public:
	virtual ~Flyweight(){}
	virtual void Operation(){}
	//���ر�����������
	string GetIntrinsicState()
	{
		return this->_intrinsicState;
	}
protected:
	//�������Ĺ�����������һ��������������
	Flyweight(string intrinsicState)
	{
		this->_intrinsicState = intrinsicState;
	}
private:
	string _intrinsicState;//�������
};

class ConcreteFlyweight:public Flyweight
{
public:
	ConcreteFlyweight(string intrinsicState):Flyweight(intrinsicState)
	{
		cout<<"������"<<intrinsicState<<"Ԫ��"<<endl;
	}
	~ConcreteFlyweight(){}
	void Operation()
	{
		cout<<this->GetIntrinsicState()<<"Ԫ�ص���ز��������Զ���"<<endl;
	}
protected:
private:
};
#endif // !defined(AFX_FLYWEIGHT_H__C538340B_3718_46A1_8C18_4773CFC166C0__INCLUDED_)
