// Colleage.cpp: implementation of the Colleage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Colleage.h"
#include "Mediator.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Colleage::Colleage()
{ //_sdt = " "; 
}
Colleage::Colleage(Mediator* mdt)
{
	this->_mdt = mdt;//_sdt = " ";
}
Colleage::~Colleage(){}

ConcreteColleageA::ConcreteColleageA(){}
ConcreteColleageA::~ConcreteColleageA() {}
ConcreteColleageA::ConcreteColleageA(Mediator* mdt):Colleage(mdt){}
string ConcreteColleageA::GetState(){return _sdt;}
void ConcreteColleageA::SetState(const string& sdt){ _sdt = sdt; }
void ConcreteColleageA::Aciton()
{
	_mdt->DoActionFromAtoB();
	cout<<"ͬ��һ��ǰֵΪ"<<" "<<this->GetState()<<"�Ѿ�ͨ���н鷽������Ϣ���ݸ�Ŀ�����"<<endl;
}

ConcreteColleageB::ConcreteColleageB() {}
ConcreteColleageB::~ConcreteColleageB() {}
ConcreteColleageB::ConcreteColleageB(Mediator* mdt):Colleage(mdt){}

void ConcreteColleageB::Aciton()
{
	_mdt->DoActionFromBtoA();
	cout<<"ͬ�¶���ǰֵΪ"<<" "<<this->GetState()<<"�Ѿ�ͨ���н鷽������Ϣ���ݸ�Ŀ�����"<<endl;
}

string ConcreteColleageB::GetState(){ return _sdt; }
void ConcreteColleageB::SetState(const string& sdt){ _sdt = sdt;}
