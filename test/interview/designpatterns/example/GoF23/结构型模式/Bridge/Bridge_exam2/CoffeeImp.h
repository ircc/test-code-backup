// CoffeeImp.h: interface for the CoffeeImp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COFFEEIMP_H__36BA6975_E825_4AC1_B784_E26E14E50B43__INCLUDED_)
#define AFX_COFFEEIMP_H__36BA6975_E825_4AC1_B784_E26E14E50B43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "iostream"
#include "string"
using namespace std;

class CoffeeImp  
{
public:
	CoffeeImp();
	~CoffeeImp(){}
	virtual void pourCoffeeImp(string cup)=0;
};

//��Ϊ�����Ӽ���
class MilkCoffeeImp:public CoffeeImp
{
public:
	MilkCoffeeImp(){}
	void pourCoffeeImp(string cup)
	{
		cout<<cup<<"������ζ��ţ��"<<endl;
	}
};

//��Ϊ����������
class FragrantCoffeeImp:public CoffeeImp
{
public:
	FragrantCoffeeImp(){}
	void pourCoffeeImp(string cup)
	{
		cout<<cup<<"ʲôҲû��,����"<<endl;
	}
};
#endif // !defined(AFX_COFFEEIMP_H__36BA6975_E825_4AC1_B784_E26E14E50B43__INCLUDED_)
