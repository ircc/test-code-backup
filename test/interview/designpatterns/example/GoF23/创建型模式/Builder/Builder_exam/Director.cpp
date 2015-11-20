// Director.cpp: implementation of the Director class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Director.h"
#include "Builder.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Director::Director(Builder* bld)
{
	cout<<"�õ���ض��Ʋ������������ɴ�������,";
	_bld = bld;
}

Director::~Director()
{

}

Product* Director::Construct()
{
    cout<<"���������Ѿ����ɣ���ʼ�𲽹�����Ʒ"<<endl;
	return _bld->GetProduct();
}
