// Adapter.h: interface for the Adapter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADAPTER_H__00B0F5B6_3560_496D_9FEE_F58D1DAD9E1A__INCLUDED_)
#define AFX_ADAPTER_H__00B0F5B6_3560_496D_9FEE_F58D1DAD9E1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
using namespace std;

//ģ��ԭʼĿ���࣬ͨ��Request ʵ�ֹ��ܡ�����������Ҫһ�����ӹ��ܵ��������Ѿ�ʵ�֣���������ΪSpecificRequest
class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{
		cout<<"���ǵ�Ŀ���෽������������ΪRequest"<<endl;
	};
protected:
private:
};
/*ģ��������࣬����SpecificRequest ��������Ҫ�ġ������������û��ṩͳһ�ӿڣ���ͨ��Request����*/
class ThirdParty
{
public:
	ThirdParty(){}
	~ThirdParty(){}
	void SpecificRequest()
	{
		cout<<"������Ҫ�ĵ������෽������������ΪSpecificRequest" <<endl;
	};
protected:
private:
};

//�̳�Ŀ���࣬����ָ�����ָ�����������󣬼̳е������������������Ե��õ������෽��
class Adapter:public Target,private ThirdParty
{
public:
	Adapter(){}
	~Adapter(){}
	void Request()
	{
		this->SpecificRequest();
	};
protected:
private:
};

#endif // !defined(AFX_ADAPTER_H__00B0F5B6_3560_496D_9FEE_F58D1DAD9E1A__INCLUDED_)
