// Handle.cpp: implementation of the Handle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Handle.h"
#include "Request.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void Handle::SetSuccessor(Handle* succ){_succ = succ; }//���ú��	
Handle* Handle::GetSuccessor(){return _succ;}//�õ����
string Handle::getHandleName(){return _handleName;}//�õ�����������
int Handle::getHandleLevel(){return _handleLevel;}//�õ�������
Handle::Handle(string handleName,int handleLevel,Handle* succ)
:_handleName(handleName),_handleLevel(handleLevel),_succ(succ){}
Handle::Handle(string handleName,int handleLevel)
:_handleName(handleName),_handleLevel(handleLevel){}


ConcreteHandleA::ConcreteHandleA(string handleName,int handleLevel,Handle* succ)
    :Handle(handleName,handleLevel,succ){}
ConcreteHandleA::ConcreteHandleA(string handleName,int handleLevel)
    :Handle(handleName,handleLevel){}
ConcreteHandleA::~ConcreteHandleA(){}

void ConcreteHandleA::HandleRequest(Request* request)
{
	if((this->getHandleLevel())==(request->getRequestLeverl()))
	{
		cout<<this->getHandleName()<<"�������⣺"<<request->getRequestName()<<endl;
	}else if(this->GetSuccessor() != 0)
	{
		cout<<"����"<<this->getHandleName()<<",����("<<request->getRequestName()<<")�����Ҵ���,�Ѿ���"<<endl;
		this->GetSuccessor()->HandleRequest(request);
	}
	else
	{
		cout<<"����("<<request->getRequestName()<<")û���ҵ����ʵĴ����ߣ���ʱ�޷������������Ա��ϵ"<<endl;
	}
}



ConcreteHandleB::ConcreteHandleB(string handleName,int handleLevel,Handle* succ)
    :Handle(handleName,handleLevel,succ){}
ConcreteHandleB::ConcreteHandleB(string handleName,int handleLevel)
    :Handle(handleName,handleLevel){}
ConcreteHandleB::~ConcreteHandleB(){}

void ConcreteHandleB::HandleRequest(Request* request)
{
	if((this->getHandleLevel())==(request->getRequestLeverl()))
	{
		cout<<this->getHandleName()<<"�������⣺"<<request->getRequestName()<<endl;
	}else if(this->GetSuccessor() != 0)
	{
		cout<<"����"<<this->getHandleName()<<",����("<<request->getRequestName()<<")�����Ҵ���,�Ѿ���"<<endl;
		this->GetSuccessor()->HandleRequest(request);
	}
	else
	{
		cout<<"�������������һ��:"<<this->getHandleName()<<",����("<<request->getRequestName()<<")û���ҵ����ʵĴ����ߣ���ʱ�޷������������Ա��ϵ"<<endl;
	}
}