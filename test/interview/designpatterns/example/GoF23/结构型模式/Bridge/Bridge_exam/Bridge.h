// Bridge.h: interface for the Bridge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRIDGE_H__2A2BEE0A_2BDD_4C59_9BFE_60D41C66A735__INCLUDED_)
#define AFX_BRIDGE_H__2A2BEE0A_2BDD_4C59_9BFE_60D41C66A735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AbstractionImp.h"

class Bridge  
{
public:	
	virtual ~Bridge(){};
	static void setActionImp(AbstractionImp* actionImp1)
	{
		actionImp=actionImp1;
	}
    static AbstractionImp* getActionImp()
	{
		if(actionImp==0)
			actionImp = new ConcreteAbstractionImp();
		return actionImp;
	}
    static Bridge* getBridge()
	{
		if(bridge==0)
		{
			bridge= new Bridge();
		}
		return bridge;
	}
private:
	Bridge()
	{
		actionImp = new ConcreteAbstractionImp();
	}
	static AbstractionImp* actionImp;
	static Bridge* bridge;
};
//���ڵ�̬ģʽ�˾�ز����١�����ж�Ӧcpp�ļ����˾����д��cpp�ļ���
Bridge* Bridge::bridge=0;
AbstractionImp* Bridge::actionImp=0;
#endif // !defined(AFX_BRIDGE_H__2A2BEE0A_2BDD_4C59_9BFE_60D41C66A735__INCLUDED_)
