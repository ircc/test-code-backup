// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


#include<iostream>  
#define MAXSIZE 100  
using namespace std;  

// ����������
// ������n������(����Ϊ������)��ɵ�����A1,A2,A3,...,An,������е������Ӷεĺ͵����ֵ��������������Ϊ������ʱ����������Ӷκ�Ϊ0
// ����   {-4, 11��-2, 13��-7��-3��12} ������Ӷκ�Ϊ22
// �����ȼ��д��룬���о������


// <limits.h>����INT_MAX��INT_MIN�ĺ궨���ֱ��ʹ�á�
// �������ж����
// #define INT_MAX 0x7fffffff
// #define INT_MIN 0x80000000
// INT_MAX = 2147483647
// INT_MIN = -2147483648

int MaxSum(int szArray[],int n)  
{  
    int iTemp = 0;  
    int iSum = INT_MIN;  

    for(int i=0; i<n; i++)  
    {  
        if(iTemp > 0)  
        {  
            iTemp += szArray[i];  
        }  
        else  
        {  
            iTemp = szArray[i];  
        } 

        if(iTemp > iSum)  
        {  
            iSum = iTemp;  
        }  
    }  
    return iSum;  
}

int main(void)  
{  
    int iCount = 7;  
    int szArray[] =  {-4, -15, -50, -13, -7, -3, -16};  

    cout<<MaxSum(szArray, iCount )<<endl;


    //int n;  
    //int array[MAXSIZE];  
    //while(cin>>n)  
    //{  
    //    for(int i=1;i<=n;i++)  
    //    {  
    //        cin>>array[i];  
    //    }  
    //    cout<<MaxSum(array,n)<<endl;  
    //}  
    return 0;  
}  
