// Adapter.h: interface for the Adapter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADAPTER_H__6B139991_4B8C_4465_A290_7FC49C9E9DAB__INCLUDED_)
#define AFX_ADAPTER_H__6B139991_4B8C_4465_A290_7FC49C9E9DAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
using namespace std;
/*ģ��ԭʼĿ���࣬ͨ��Request ʵ�ֹ��ܡ�����������Ҫһ�����ӹ�
�ܵ��������Ѿ�ʵ�֣���������ΪSpecificRequest*/
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
/*ģ���������ӿڣ�������󷽷�SpecificRequest ��������Ҫ�ġ����Ĳ�ͬʵ�ֿ��ܾ��в�ͬ����*/
class ThirdPartyInterface
{
public:
	ThirdPartyInterface(){}
	~ThirdPartyInterface(){}
	virtual void SpecificRequest()=0;
protected:
private:
};
/*ģ��������࣬����SpecificRequest ��������Ҫ�ġ������������û��ṩͳһ�ӿڣ���ͨ��Request����*/
class ThirdPartyOne:public ThirdPartyInterface
{
public:
	ThirdPartyOne(){}
	~ThirdPartyOne(){}
	void SpecificRequest()
	{
		cout<<"������Ҫ�ĵ������෽������������ΪSpecificRequest" <<endl;
	}
};

//�̳�Ŀ���࣬����ָ�����ָ������������
class Adapter:public Target
{
public:
	Adapter(ThirdPartyInterface* thirdParty)//:Target(),_thirdParty(thirdParty){}
	{
		this->_thirdParty = thirdParty;
	}
	~Adapter(){}
	void Request()
	{
		_thirdParty->SpecificRequest();
	}
protected:
private:
	ThirdPartyInterface* _thirdParty;
};



#endif // !defined(AFX_ADAPTER_H__6B139991_4B8C_4465_A290_7FC49C9E9DAB__INCLUDED_)
