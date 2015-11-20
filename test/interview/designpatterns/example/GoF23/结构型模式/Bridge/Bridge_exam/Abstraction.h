// Abstraction.h: interface for the Abstraction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ABSTRACTION_H__6CB8BB19_B327_40B0_AAE5_75F1533920C2__INCLUDED_)
#define AFX_ABSTRACTION_H__6CB8BB19_B327_40B0_AAE5_75F1533920C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "string"
#include "AbstractionImp.h"
#include "Bridge.h"
#include <iostream>
using namespace std;

class AbstractionImp;

//� �������桢ѧϰ��
class Abstraction
{
public:
	virtual ~Abstraction(){}
	virtual void Operation()=0;	
protected:
	Abstraction(){}	
private:
};

/*һ������Ļ.
 ע��˻��ʵ����Ҫ������һ������ķ�����������m�ֿ�ѡ��������Ϊ������������巽����ʵʩ���������
 �������ĺô���һ������һ���µĻ������ֻ��ҪЩһ���࣬������m����
*/
class RefinedAbstraction:public Abstraction
{
public:
	//���캯��
	/*������Ҫ�������ڴ�ͨ��Bridge ��� AbstractionImp ʵ��ָ��_imp��
		*/
	RefinedAbstraction(){}
	~RefinedAbstraction(){}
	//������ʵʩ����
	void Operation()
	{
        _imp=Bridge::getActionImp();
		cout<<"�һ����";
		_imp->Operation();
	}
protected:
private:
	Bridge* bridge;
	AbstractionImp* _imp;
};

#endif // !defined(AFX_ABSTRACTION_H__6CB8BB19_B327_40B0_AAE5_75F1533920C2__INCLUDED_)
