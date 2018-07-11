// test.cpp : 定义控制台应用程序的入口点。
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

// 问题描述：
// 给定由n个整数(可能为负整数)组成的序列A1,A2,A3,...,An,求该序列的连续子段的和的最大值。当所有整数均为负整数时定义其最大子段和为0
// 例如   {-4, 11，-2, 13，-7，-3，12} 的最大子段和为22
// 虽寥寥几行代码，但感觉很巧妙。


// <limits.h>中有INT_MAX和INT_MIN的宏定义可直接使用。
// 或者自行定义宏
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
