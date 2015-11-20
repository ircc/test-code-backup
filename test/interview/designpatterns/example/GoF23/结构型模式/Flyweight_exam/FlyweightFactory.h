// FlyweightFactory.h: interface for the FlyweightFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLYWEIGHTFACTORY_H__5F40637B_1B63_43B2_A8FC_A4539A175FBF__INCLUDED_)
#define AFX_FLYWEIGHTFACTORY_H__5F40637B_1B63_43B2_A8FC_A4539A175FBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flyweight.h"
#include <iostream>
//#include <cassert>
#include <string>
#include <vector>
using namespace std;

/*cassert Ϊԭc���� cassertͷ�ļ���
��д����ʱ���������ǻ�����һЩ���裬���Ծ��������ڴ����в�׽��Щ���裬
���Խ����Կ������쳣�����һ�ָ߼���ʽ�����Ա�ʾΪһЩ�������ʽ��
����Ա�����ڳ����е�ĳ���ض���ñ��ʽֵΪ�档�������κ�ʱ�����úͽ��ö�����֤��
��˿����ڲ���ʱ���ö��ԣ����ڲ���ʱ���ö��ԡ�ͬ��������Ͷ�����к�
�����û�����������ʱ�����������ö��ԡ�
*/

class FlyweightFactory
{
public:
	FlyweightFactory(){}
	~FlyweightFactory(){}
	Flyweight* GetFlyweight(const string& key)
	{
		vector<Flyweight*>::iterator it = _fly.begin();
		for (; it != _fly.end();it++)
		{ //�ҵ��ˣ���һ���ã�^_^
			if ((*it)->GetIntrinsicState() == key)
			{
				cout<<"�ڿ��м�����"<<key<<"Ԫ��"<<endl;
				return *it;
			}
		}
		//û���ҵ��򴴽�
		Flyweight* fn = new ConcreteFlyweight(key);
		//�������
		_fly.push_back(fn);
		return fn;
	}
protected:
private:
	vector<Flyweight*> _fly;
};

#endif // !defined(AFX_FLYWEIGHTFACTORY_H__5F40637B_1B63_43B2_A8FC_A4539A175FBF__INCLUDED_)
