// Duck.h: interface for the Duck class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUCK_H__EC355C43_B3B0_4EC5_9023_55C196C2C438__INCLUDED_)
#define AFX_DUCK_H__EC355C43_B3B0_4EC5_9023_55C196C2C438__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Fly.h"
#include "Quack.h"
#include "iostream"
using namespace std;
//����Ѽ�ӳ�����
class Duck
{
protected:
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;
public:
	//����Ѽ�Ӷ�����Ӿ
	void swim()
	{
		cout<<"�һ���Ӿ�����εúܰ���";
	}
	//������۲�һ��������Ϊ����
	virtual void display()=0;
	
	void performQuack()
	{
		quackBehavior->quack();
	}
	void performFly()
	{
		flyBehavior->fly();
	}

	void setFlyBehavior(FlyBehavior* flyBehavior)
	{
		this->flyBehavior = flyBehavior;
	}

	void setQuackBehavior(QuackBehavior* quackBehavior)
	{
		this->quackBehavior = quackBehavior;
	}
   
};

/*��������������Ѽ�ӣ�Ѽ�Ӷ�����Ӿ�ģ����ڷɺͽ��Ƕ��������õġ�Ҳ����˵Ѽ�ӵ���Ϊ�Ѿ�������Ѽ��
  ���ǿ�����������ӻ��޸ķ��С��е������ģʽ����ɵ�Ӱ�������*/
//һ��Ѽ��ʵ��
class ModelDuck:public Duck
{
public:
	ModelDuck()
	{
		flyBehavior = new FlyNoWay();//��ʼ״̬�� ���ǵ�ģ��Ѽ�ǲ���ɵġ�
        quackBehavior = new Quack();//��ʼ״̬�����ǵ�ģ��Ѽ�ǿ��Խе�.
	}
	void display()
	{
		cout<<"����һ��ģ��Ѽ�ӣ�";
	}
};

//������Ҫ���Խ���һ���µ�FlyBehavior����

class FlyRocketPowered:public FlyBehavior
{
	// ���ǽ���һ�����û�������ķ�����Ϊ��
public:
	void fly()
	{
      cout<<"���ѻ��Ϊ�������У��ó��죬��ˬ������"<<endl;
    }
};




#endif // !defined(AFX_DUCK_H__EC355C43_B3B0_4EC5_9023_55C196C2C438__INCLUDED_)
