// Handle.h: interface for the Handle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HANDLE_H__E2BC965A_4449_4A35_BDE5_C4BAF190EA02__INCLUDED_)
#define AFX_HANDLE_H__E2BC965A_4449_4A35_BDE5_C4BAF190EA02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
using namespace std;
#include <string>

class Request;
class Handle  
{public:
virtual ~Handle(){}	
	virtual void HandleRequest(Request* request) = 0;//��������ķ���	
	void SetSuccessor(Handle* succ);//���ú��	
	Handle* GetSuccessor();//�õ����
	std::string getHandleName();//�õ�����������
	int getHandleLevel();//�õ�������
protected:
	Handle(string handleName,int handleLevel,Handle* succ);
	Handle(string handleName,int handleLevel);
private:
	Handle* _succ;
	int _handleLevel;
	string _handleName;
};

//���������ദ���������Ա��ÿ���кܶ����Ա
class ConcreteHandleA:public Handle
{
public:
	ConcreteHandleA(string handleName,int handleLevel,Handle* succ);
	ConcreteHandleA(string handleName,int handleLevel);
	~ConcreteHandleA();
	void HandleRequest(Request* request);
protected:
private:
};

class ConcreteHandleB:public Handle
{
public:
	ConcreteHandleB(string handleName,int handleLevel,Handle* succ);
	ConcreteHandleB(string handleName,int handleLevel);
	~ConcreteHandleB();
	void HandleRequest(Request* request);
protected:
private:
};
#endif // !defined(AFX_HANDLE_H__E2BC965A_4449_4A35_BDE5_C4BAF190EA02__INCLUDED_)
