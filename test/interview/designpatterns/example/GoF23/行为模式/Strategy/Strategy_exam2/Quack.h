// Quack.h: interface for the Quack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUACK_H__B20C8843_54F3_4049_9A50_F2ABA0DDF831__INCLUDED_)
#define AFX_QUACK_H__B20C8843_54F3_4049_9A50_F2ABA0DDF831__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "iostream"
using namespace std;

//�еĽӿ�
class QuackBehavior
{
public:
	virtual void quack()=0;
};

//ʵ��Ѽ�����ɽ�
class Quack:public QuackBehavior
{
public:
	void quack()
	{
		cout<<"�һ����ɽ�,";
    }
};

//ʵ��Ѽ��֨֨��
class Squeak:public QuackBehavior
{
public:
	void quack()
	{
        cout<<"�һ�֨֨��,";
    }
};

//ʲôҲ�����������
class MuteQuack:public QuackBehavior
{
public:
	void quack()
	{
		cout<<"�Ҳ���У�";
	}
};



#endif // !defined(AFX_QUACK_H__B20C8843_54F3_4049_9A50_F2ABA0DDF831__INCLUDED_)
