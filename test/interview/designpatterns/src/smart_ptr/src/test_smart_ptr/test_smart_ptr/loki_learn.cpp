/************************************************************************/
/* 
�ļ����� Loki��ѧϰ
�����ˣ� Clark/����
������	 
�������ڣ� 20111006
*/
/************************************************************************/
#include "stdafx.h"
#include <iostream>

using namespace std;


class NullType {};

template <class T, class U>
struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

template <class TList> struct Length; 
template <> struct Length<NullType>
{ 
    enum { value = 0 };
};

template <class T, class U> 
struct Length< Typelist<T, U> >
{
    enum { value = 1 + Length<U>::value };
};

template <class TList, unsigned int index> struct TypeAt;
template <class Head, class Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{//����ȡͷ����
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail>, i>
{//������ȡβ�͵�����
    typedef typename TypeAt<Tail, i - 1>::Result Result;
};


template <class TList, unsigned int index,typename DefaultType = NullType>
struct TypeAtNonStrict
{//����DefaultType�����������Ͷ�ƫ�ػ����ɹ�ʱ��������ͨ���͵�ֵ����
    //DefaultType�����趨�Ҳ���ʱ�ķ���ֵ
    typedef DefaultType Result;
};

template <class Head, class Tail, typename DefaultType>
struct TypeAtNonStrict<Typelist<Head, Tail>, 0, DefaultType>
{
    //DefaultType��ƫ�ػ����﷨Ҫ��,���ǵݹ��㷨������
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i, typename DefaultType>
struct TypeAtNonStrict<Typelist<Head, Tail>, i, DefaultType>
{
    //typename�������Ǹ��߱���������ʵ��������,DefaultType��ƫ�ػ����﷨Ҫ��,���ǵݹ��㷨������
    typedef typename TypeAtNonStrict<Tail, i - 1, DefaultType>::Result Result;
};

void main2()
{
    cout<<Length<Typelist<int,Typelist<bool,Typelist<char,NullType> > > >::value<<endl;
    cout<<sizeof(TypeAt<Typelist<int,Typelist<bool,Typelist<char,NullType> > >, 0>::Result)<<endl;
    cout<<sizeof(TypeAtNonStrict<Typelist<int,Typelist<bool,Typelist<char,NullType> > >, 5>::Result)<<endl;
    cout<<sizeof(TypeAtNonStrict<Typelist<int,char>,0>::Result)<<endl;

    cout<<"------"<<endl;
    cout<<sizeof(TypeAtNonStrict<int,0>::Result)<<endl;
    system("pause");
}