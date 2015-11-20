/************************************************************************/
/* 
文件名： Loki库学习
创建人： Clark/陈泽丹
描述：	 
创建日期： 20111006
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
{//符合取头类型
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail>, i>
{//不符合取尾巴的类型
    typedef typename TypeAt<Tail, i - 1>::Result Result;
};


template <class TList, unsigned int index,typename DefaultType = NullType>
struct TypeAtNonStrict
{//加入DefaultType，当所有类型都偏特化不成功时，则以普通类型的值出现
    //DefaultType用于设定找不到时的返回值
    typedef DefaultType Result;
};

template <class Head, class Tail, typename DefaultType>
struct TypeAtNonStrict<Typelist<Head, Tail>, 0, DefaultType>
{
    //DefaultType是偏特化的语法要求,不是递归算法的因素
    typedef Head Result;
};

template <class Head, class Tail, unsigned int i, typename DefaultType>
struct TypeAtNonStrict<Typelist<Head, Tail>, i, DefaultType>
{
    //typename的作用是告诉编译器其后的实体是类型,DefaultType是偏特化的语法要求,不是递归算法的因素
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