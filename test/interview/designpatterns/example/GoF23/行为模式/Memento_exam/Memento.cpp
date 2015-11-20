// Memento.cpp: implementation of the Memento class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Memento.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;
typedef string State;

Originator::Originator()
{
	_sdt = "";_mt = 0;
}

Originator::Originator(const State& sdt)
{
	_sdt = sdt;_mt = 0;
}

Originator::~Originator() {}

Memento* Originator::CreateMemento()
{
	cout<<"����������ɹ�������"<< _sdt<<"ֵ����"<<endl;
	return new Memento(_sdt);
}
State Originator::GetState() { return _sdt; }

void Originator::SetState(const State& sdt)
{
	cout<<"״ֵ̬����"<< _sdt<<"����Ϊ"<<sdt<<endl;
	_sdt = sdt;    
}

void Originator::PrintState()
{ cout<<"��ǰ״ֵ̬Ϊ��"<<this->_sdt<<endl;}

void Originator::SetMemento(Memento* men) {}

void Originator::RestoreToMemento(Memento* mt)
{
	this->_sdt = mt->GetState();
    cout<<"״ֵ̬�ָ�Ϊ"<< _sdt<<endl;
}


Memento::Memento(){ }
Memento::Memento(const State& sdt){ _sdt = sdt; }
State Memento::GetState() { return _sdt; }
void Memento::SetState(const State& sdt){ _sdt = sdt; }