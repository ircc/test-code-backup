// strategy.h: interface for the strategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRATEGY_H__C2CEAD03_C158_4E53_9EA2_6D29D163D9F8__INCLUDED_)
#define AFX_STRATEGY_H__C2CEAD03_C158_4E53_9EA2_6D29D163D9F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std;
//��Ϊһ����ӿ�
class BehaviorOne
{
public:
	virtual void BehaviorOneMethod() = 0;
protected:
private:
};
//��Ϊ������ӿ�
class BehaviorTwo
{
public:
	virtual void BehaviorTwoMethod() = 0;
protected:
private:
};
//��Ϊһ��A����
class BehaviorOneA:public BehaviorOne
{
public:
	void BehaviorOneMethod()
	{
		cout<<"��Ϊһ��A����"<<endl;
	}
protected:
private:
};

//��Ϊһ��B����
class BehaviorOneB:public BehaviorOne
{
public:
	void BehaviorOneMethod()
	{
		cout<<"��Ϊһ��B����"<<endl;
	}
protected:
private:
};
//��Ϊ����A����
class BehaviorTwoA:public BehaviorTwo
{
public:
	void BehaviorTwoMethod()
	{
		cout<<"��Ϊ����A����"<<endl;
	}
protected:
private:
};

//��Ϊ����B����
class BehaviorTwoB:public BehaviorTwo
{
public:
	void BehaviorTwoMethod()
	{
		cout<<"��Ϊ����B����"<<endl;
	}
protected:
private:
};

#endif // !defined(AFX_STRATEGY_H__C2CEAD03_C158_4E53_9EA2_6D29D163D9F8__INCLUDED_)
