// Fly.h: interface for the Fly class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLY_H__D97C9C72_8B03_4B42_A135_9156BA93361E__INCLUDED_)
#define AFX_FLY_H__D97C9C72_8B03_4B42_A135_9156BA93361E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "iostream"
using namespace std;

//�ɵĳ���ӿ�
class FlyBehavior
{
public:
	FlyBehavior(){}
	~FlyBehavior(){}
	virtual void fly()=0;
};

//���
class FlyWithWings:public FlyBehavior
{
public:
    void fly()
	{
		cout<<"�һ��"<<endl;
		//ʵ��Ѽ�ӷ���
	}
};
//�����

class FlyNoWay:public FlyBehavior
{
public:
	void fly()
	{
		cout<<"�Ҳ����"<<endl;
		//ʲôҲ�����������
     }
};

#endif // !defined(AFX_FLY_H__D97C9C72_8B03_4B42_A135_9156BA93361E__INCLUDED_)
