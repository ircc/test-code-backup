/************************************************************************/  
/*  
�ļ����� ģ����ػ���ƫ�ػ���ʵ���� 
�����ˣ� Clark/���� 
������   
ģ���ػ���ʵ����ģ������⴦������ʱ��ָ�����ͣ�Ȼ���������������⴦���� 
ģ��ƫ�ػ���ʵ����ģ��Ĳ������⴦������ʱ��ָ�����ͣ�Ȼ���������������⴦���� 
ģ���ʵ����������ʱ����ָ�������ˣ� 
�������ڣ� 20111006 
*/  
/************************************************************************/  
#include "stdafx.h"
#include <iostream>   

using namespace std;  

#define TEMP_TRUE true   

#ifdef TEMP_TRUE   
//�����ж����is_template,�������is_template���ػ���ƫ�ػ���ʵ�����ſ�ʵ��   
//��ͨģ��   
template <class T1, class T2>  
struct is_template{ enum { value = 0}; };   
//Ҳ��ֻ������struct is_template;   
#endif   


//ģ���ػ�(����ʱ��ָ����������������⴦��)   
template<>  
struct is_template<int, char>{ enum { value = 1}; };   

//ģ��ƫ�ػ�(����ʱ��ָ�������������⴦��)   
template <class T1, class T2>  
struct is_template<T1*, T2>{ enum { value = 2}; };  

//ģ��ƫ�ػ�(����ʱ�貿��ָ��)   
template <class T2>  
struct is_template<char, T2>{ enum { value = 3}; };  

//ģ��ʵ����(����ʱ����ָ����)   
struct is_template_ex : public  is_template<int, char>      
{  
    enum { value = 4};  
};  

//ƫ�ػ����������ھ�����ֵ
template <class T, int index>  
struct is_template_value{ enum { value = 11}; };
//����Ϊ0ʱ��ƫ�ػ�
template <class T>  
struct is_template_value<T, 0>{ enum { value = 22}; };  


//ƫ�ػ������������������
template <class T1, class T2>
struct find_type
{
    enum { value = -1 };
};
template <class T> //�������ʱ��ƫ�ػ�
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
