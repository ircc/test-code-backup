// Aggregate.h: interface for the Aggregate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AGGREGATE_H__DC457711_BE60_4FCE_826E_7488FFCFEEAA__INCLUDED_)
#define AFX_AGGREGATE_H__DC457711_BE60_4FCE_826E_7488FFCFEEAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Iterator;
typedef int Object;

class Interator;
class Aggregate
{
public:
	virtual ~Aggregate();
	virtual Iterator* CreateIterator() = 0;
	virtual Object GetItem(int idx) = 0;
	virtual int GetSize() = 0;
protected:
	Aggregate();
private:
};

class ConcreteAggregate:public Aggregate
{
public:
	enum{SIZE = 3};
	ConcreteAggregate();//���켯��
	~ConcreteAggregate();
	Iterator* CreateIterator();//����������
	Object GetItem(int idx);//�õ�������ָ�����ֵ
	int GetSize();//�õ����ϴ�С
protected:
private:
	Object _objs[SIZE];
};

#endif // !defined(AFX_AGGREGATE_H__DC457711_BE60_4FCE_826E_7488FFCFEEAA__INCLUDED_)
