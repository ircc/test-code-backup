/************************************************************************/  
/*  
文件名： 模板的特化，偏特化，实例化 
创建人： Clark/陈泽丹 
描述：   
模板特化其实就是模板的特殊处理（调用时需指定类型，然后再特殊问题特殊处理）。 
模板偏特化其实就是模板的部份特殊处理（调用时需指定类型，然后再特殊问题特殊处理）。 
模板的实例化（调用时无需指定类型了） 
创建日期： 20111006 
*/  
/************************************************************************/  
#include "stdafx.h"
#include <iostream>   

using namespace std;  

#define TEMP_TRUE true   

#ifdef TEMP_TRUE   
//必须有定义过is_template,后面关于is_template的特化，偏特化和实例化才可实现   
//普通模板   
template <class T1, class T2>  
struct is_template{ enum { value = 0}; };   
//也可只声明：struct is_template;   
#endif   


//模板特化(调用时需指定，但特殊情况特殊处理)   
template<>  
struct is_template<int, char>{ enum { value = 1}; };   

//模板偏特化(调用时需指定，但部份特殊处理)   
template <class T1, class T2>  
struct is_template<T1*, T2>{ enum { value = 2}; };  

//模板偏特化(调用时需部份指定)   
template <class T2>  
struct is_template<char, T2>{ enum { value = 3}; };  

//模板实例化(调用时无需指定了)   
struct is_template_ex : public  is_template<int, char>      
{  
    enum { value = 4};  
};  

//偏特化还可以用于具体数值
template <class T, int index>  
struct is_template_value{ enum { value = 11}; };
//参数为0时的偏特化
template <class T>  
struct is_template_value<T, 0>{ enum { value = 22}; };  


//偏特化还可以用于类型配对
template <class T1, class T2>
struct find_type
{
    enum { value = -1 };
};
template <class T> //类型相等时的偏特化
struct find_type<T, T>
{
    enum { value = 0 };
};

#include "TraceUtil.h"
#include<time.h>
void main()  
{  
    int iSoftID = 100;
    TCHAR tszUserName[MAX_PATH] = {_T("ssdsssss")};
    TCHAR tszNewVersion[MAX_PATH] = {_T("65300010000016_1441123996_02317_001_0100110007")};
    TCHAR tszCurVersion[MAX_PATH] = {_T("00000000000000-0000000000-00000-000-0000000001")};
 
    time_t timer;
    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);
    printf("Local time is: %s\r\n", asctime(tblock));

    for (int i=0; i<10000; i++)
    {
        COMMON::TRACE(_T("CheckMustUser_20101209, Ack return:false, iSoftID:%d; sUserName:%s; NewVersion:%s; CurVersion:%s\r\n"), 
            iSoftID, tszUserName, tszNewVersion, tszCurVersion);

    }

    time_t t;
    time(&t);
    printf("Today's date and time: %s\r\n", ctime(&t));

    cout<<is_template<int,bool>::value<<endl;  
    cout<<is_template<int,char>::value<<endl;  
    cout<<is_template<int*,char>::value<<endl;  
    cout<<is_template<char,int>::value<<endl;  
    cout<<is_template_ex::value<<endl;  

    cout<<is_template_value<int,5>::value<<endl;  
    cout<<is_template_value<int,0>::value<<endl;  

    cout<<find_type<int,char>::value<<endl;  
    cout<<find_type<int,int>::value<<endl;  
    cout<<find_type<char,char>::value<<endl;  

    int k;
    cin>>k;
    if( 0 == k)
    {
        cout<<find_type<char,int>::value<<endl;  
    }
    else
    {
        cout<<find_type<char,char>::value<<endl;  
    }


    system("pause");  
}  
