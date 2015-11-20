// Observer.cpp: implementation of the Observer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Observer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include "Subject.h"
#include <iostream>
#include <string>
using namespace std;
Observer::Observer(){ _st = '\0';}

Observer::~Observer(){}

ConcreteObserverA::ConcreteObserverA(Subject* sub)
{
	_sub = sub;
	_sub->Attach(this);
	cout<<"�۲���A���������Ѿ��ڿ�Ŀ������ע��"<<endl;
}

ConcreteObserverA::~ConcreteObserverA()
{
	_sub->Detach(this);
	if (_sub != 0){delete _sub;}
}

Subject* ConcreteObserverA::GetSubject(){ return _sub; }

void ConcreteObserverA::PrintInfo()
{
	cout<<"�۲���A�۲쵽��Ŀ״̬��Ϊ"<<_sub->GetState()<<"�Ѿ�������Ӧ�ķ�Ӧ"<<endl;
}

void ConcreteObserverA::Update(Subject* sub)
{
	_st = sub->GetState();
	PrintInfo();
}

ConcreteObserverB::ConcreteObserverB(Subject* sub)
{
	_sub = sub;
	_sub->Attach(this);
	cout<<"�۲���B���������Ѿ��ڿ�Ŀ������ע��"<<endl;
}

ConcreteObserverB::~ConcreteObserverB()
{
	_sub->Detach(this);
	if (_sub != 0){ delete _sub;}
}

Subject* ConcreteObserverB::GetSubject(){return _sub;}

void ConcreteObserverB::PrintInfo()
{
	cout<<"�۲���B�۲쵽��Ŀ״̬��Ϊ"<<_sub->GetState()<<"�Ѿ�������Ӧ�ķ�Ӧ"<<endl;
}

void ConcreteObserverB::Update(Subject* sub)
{
	_st = sub->GetState();
	PrintInfo();
}
