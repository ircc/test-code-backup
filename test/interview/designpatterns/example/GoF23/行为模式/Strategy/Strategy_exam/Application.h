// Application.h: interface for the Application class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APPLICATION_H__02FD6DD0_2456_464D_99FD_32B10B0D49F0__INCLUDED_)
#define AFX_APPLICATION_H__02FD6DD0_2456_464D_99FD_32B10B0D49F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "strategy.h"
/*��һ����ʵ��Ӧ�����壬����������һЩ���ԡ���Ϊ�ǹ�ͬ�ġ�����һЩ��Ϊ�ǿɱ�ġ�
���������Ǽ�����������Ϊ�ǿɱ�ģ������ǳ������
*/
//Ӧ�ó�����
class Application  
{
public:
	Application(){}
	virtual ~Application(){}
	//�����������඼�еĹ���
	void CommonMethod()
	{
		cout<<"�������Ƕ��е�һ���Ĺ���"<<endl;
	}
	//�������඼�е���ͬ����������Ϣ
	virtual void disply()=0;

	void setBehaviorOne(BehaviorOne* behaviorOne)
	{
		this->behaviorOne= behaviorOne;
	}

	void setBehaviorTwo(BehaviorTwo* behaviorTwo)
	{
		this->behaviorTwo= behaviorTwo;
	}

	void perForm()
	{
		behaviorOne->BehaviorOneMethod();
        behaviorTwo->BehaviorTwoMethod();
	}
protected:
	BehaviorOne* behaviorOne;
	BehaviorTwo* behaviorTwo;
};

//���ʽ���ƾ���Ӧ����
class ApplicationOne:public Application
{
public:
	//�ڹ���������ֱ����Ϊ����Ĭ�ϲ����
	ApplicationOne()
	{
		this->behaviorOne=new BehaviorOneA();
		this->behaviorTwo=new BehaviorTwoA();
	}
	//�������еĹ���
	void disply()
	{
		cout<<"��ã����Ǿ���Ӧ���࣬�����ҵ�������Ϣ"<<endl;
	}
};
/*
�����Ҫ�����µ�Ӧ���࣬������һ�����̳�Application �࣬����д���������Ϳ��ԡ�
����������Ĭ��ֵҲ������ Application �������á���ȱ������ԡ�
�����������ÿ�����඼ȥд�Լ�����Ϊ������������������ô������ܶ����Ϊ�ò��̶�������ĳ����Ϊ
�������᲻�ϻ�ʱ�����޸ĺ�ά�������ܶ���鷳����ÿ�ֱ仯����������ھ���Ӧ��������Ԥ���ӿڡ�ʵ��
���ʽ��̣������ܴ�ķ���
*/

#endif // !defined(AFX_APPLICATION_H__02FD6DD0_2456_464D_99FD_32B10B0D49F0__INCLUDED_)
