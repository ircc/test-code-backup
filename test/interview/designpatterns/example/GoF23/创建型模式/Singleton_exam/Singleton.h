// Singleton.h: interface for the Singleton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLETON_H__EF79C9A7_29AC_413A_A66A_9E9EE3689F70__INCLUDED_)
#define AFX_SINGLETON_H__EF79C9A7_29AC_413A_A66A_9E9EE3689F70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream> 
using namespace std;

class Singleton  
{private:
    static Singleton* _instance;//��̬˽�еı���ָ��
	Singleton();//˽�еĹ��췽����Ҳ�ɶ���Ϊprotected:������֤���಻�ܱ�ʵ����
public:
	static Singleton* Instance();//��̬���������Ա������
	virtual ~Singleton();
};
Singleton* Singleton::_instance=NULL;
#endif // !defined(AFX_SINGLETON_H__EF79C9A7_29AC_413A_A66A_9E9EE3689F70__INCLUDED_)
