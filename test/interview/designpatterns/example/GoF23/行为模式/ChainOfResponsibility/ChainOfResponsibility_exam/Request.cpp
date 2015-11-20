// Request.cpp: implementation of the Request class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Request.h"
#include "Handle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Request::Request()
{

}

Request::~Request()
{

}
void Request::setRequestLeverl(int requestLeverl)
{
	this->requestLeverl = requestLeverl;
}
int Request::getRequestLeverl()
{
	return requestLeverl;
}

void Request::setRequestName(string requestName)
{
	this->requestName = requestName;
}

string Request::getRequestName()
{
	return requestName;
}

HandleChain::HandleChain()
{
	Handle* h1 = new ConcreteHandleB("B4",1);//����һ��������
	h1->SetSuccessor(0);
    Handle* h2 = new ConcreteHandleB("B3",2,h1);//����һ��������
	Handle* h3 = new ConcreteHandleB("B2",3,h2);//����һ��������
	Handle* h4 = new ConcreteHandleB("B1",4,h3);//����һ��������
	Handle* h5 = new ConcreteHandleA("A5",5,h4);//����һ��������
	Handle* h6 = new ConcreteHandleA("A4",6,h5);//����һ��������
	Handle* h7 = new ConcreteHandleA("A3",7,h6);//����һ��������
	Handle* h8 = new ConcreteHandleA("A2",8,h7);//����һ��������
	Handle* h9 = new ConcreteHandleA("A1",9,h8);//����һ��������
	this->FirstHandle=h9;
	cout<<"�Ѿ�����һ�����������������Ը������⼶������ֻ��һ������"<<endl;
}

void HandleChain::setRequest(Request* Request)
{
	this->FirstHandle->HandleRequest(Request);
}

