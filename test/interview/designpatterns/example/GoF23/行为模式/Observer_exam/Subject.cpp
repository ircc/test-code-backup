// Subject.cpp: implementation of the Subject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <list>
using namespace std;
typedef string state;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Subject::Subject()
{ //****��ģ���ʹ��֮ǰһ��Ҫnew������ 
	_obvs = new list<Observer*>;
	cout<<"�Ѿ�Ϊ��Ŀ���󴴽�һ���۲����б�,";
}
Subject::~Subject(){}

void Subject::Attach(Observer* obv)
{
	_obvs->push_front(obv);
}

void Subject::Detach(Observer* obv)
{
	if (obv != NULL) _obvs->remove(obv);
}

void Subject::Notify()
{
	list<Observer*>::iterator it;
	cout<<(_obvs->empty());
	it = _obvs->begin();
	for (;it != _obvs->end();it++)
	{//����ģ���iterator���÷�
		(*it)->Update(this);
	}
}

ConcreteSubject::ConcreteSubject()
{
	cout<<"�Ѿ�����һ����Ŀ����."<<endl;;
	_st = '\0';
}

ConcreteSubject::~ConcreteSubject(){ }
State ConcreteSubject::GetState(){ return _st;}
void ConcreteSubject::SetState(const State& st){ _st = st;}
