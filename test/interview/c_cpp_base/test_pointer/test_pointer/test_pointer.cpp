// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//    const int itemp = 10;
//    const int& iReference  = itemp;
//
//    int* piTemp = &iReference;
//
//    int iTemp2 = *piTemp;
//	return 0;
//}
//


//指针的引用和指向指针的指针 
//Filename:point1.cpp 
#include <iostream> 
using namespace std; 

//定义一个函数，函数的参数是一个指向”指向整型变量的指针”的指针
void all1(int **p) 
{ 
    int *pp = new int;             //给指向整型变量的指针  pp分配一个整型数据的内存地址 
    *p = pp;                       //指针 p指向的值是pp（这里 pp是一个指针，指向整型数据的指针） 
    //重点说明：pp是一个地址（指针就是地址） ，新分配的内存的地址 
    cout<<"int**p:p:"<<p<<endl;    //输出指针p的值（就是p所指向的地址） 
    cout<<"int**p:*p:"<<*p<<endl;  //输出指针 p所指向的地址里储存的数据 
    cout<<"int**p:&p:"<<&p<<endl;  //输出指针p的地址 
} 

//定义一个函数， 函数的参数是一个指针的引用（或者说：一个指针的别名） 
void all2(int*& p)
{ 
    int *pp = new int;             //给指向整型变量的指针  pp分配一个整型数据的内存地址 
    p = pp;                        //把新分配的内存地址赋值给 p（p是指针变量的引用（或者说，别名）） 
    cout<<"int*&p:p:"<<p<<endl;    //  输出指针p的值（就是 p所指向的地址） 
    cout<<"int*&p:*p:"<<*p<<endl;  //输出 p所指向的地址里储存的数据 
    cout<<"int*&p:&p:"<<&p<<endl;  //输出p的地址 
} 

int   main() 
{ 
    int iTemp = 1;
    int* &p1 =iTemp;

    int *a1;      //定义一个指针 a1（最好用int *a1=NULL;防止出现野指针） 
    all1(&a1);    //调用函数 all1()，参数是&a1（就是指针 a1 的地址） 
    //补充说明：函数 all1()的参数就是指向指针的指针（或者说：存放指针的地址）  
    *a1 = 1;      //a1指向的地址储存的数据是1 
    //分别输出*a1,a1,&a1 的值（稍后看运行结果） 
    cout<<"\n *a1="<<*a1<<"\n a1="<<a1<<"\n &a1="<<&a1<<endl; 
    delete a1;   //释放分配给a1的内存 
    a1=NULL;     //不再使用的指针赋值为NULL，使其成为空指针，防止出现悬挂指针 
    //分别输出a1和&a1，因为a1是空指针，使用*a会异常退出程序 
    cout<<"\n a1="<<a1<<"\n &a1="<<&a1<<endl; 

    int *a2;    //定义一个指针 a2 
    all2(a2);   //调用函数 all2，函数的参数是 a2（就是指针a2） 
    //补充说明：此时在函数 all2()里，a2的别名就是 p，或者说 p就是 a2。 
    //这个就和孙逸仙就是孙中山，周树人就是鲁迅一样。 
    *a2 = 2;   //指针 a2 所指向的地址存储的值赋值为2 
    //输出*a2、a2、&a2的值，稍后看运行结果 
    cout<<"\n *a2="<<*a2<<"\n a2="<<a2<<"\n &a2="<<&a2<<endl; 
    delete a2; //释放分配给 a2的内存 
    a2=NULL;   //a2 指向空地址 
    //输出a2 和&a2 
    cout<<"\n a2="<<a2<<"\n &a2="<<&a2<<endl; 
    getchar(); //为了防止程序运行一闪而过，停留再来等待输入 
    return 0;   
} 