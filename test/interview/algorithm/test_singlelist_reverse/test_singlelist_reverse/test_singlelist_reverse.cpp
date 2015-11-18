// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct SINGLE_LIST
{
    int iKey;
    SINGLE_LIST* pNext;
}SINGLELIST, * PSINGLELIST;

//构造一个值为从1到iInNum的单链表
void CreateSingleList(PSINGLELIST& pInSLHead, int iInNum)
{
    PSINGLELIST pLNode = NULL;
    PSINGLELIST pLTemp = NULL;
    int iCount = 0;

    while (iCount < iInNum)
    {
        pLNode = new SINGLELIST;
        pLNode->iKey = ++iCount;
        pLNode->pNext = NULL;

        if (NULL == pInSLHead)
        {
            pInSLHead = pLNode;
            pLTemp = pLNode;
        }
        else
        {
            pLTemp->pNext = pLNode;
            pLTemp = pLNode;
        }
    }
}

//逆置单链表
void SingleListReverse(PSINGLELIST& pInSLHead)
{
    if (NULL == pInSLHead)
    {
        return;
    }

    PSINGLELIST pLNode = pInSLHead;
    PSINGLELIST pLPrev = NULL;
    PSINGLELIST pLNext = NULL;

    // 将链表元素一个一个取出，新取出的元素指向pLPrev 实际上不取出只是修改了指向指针而已，并且将链表首指针指向最后一个元素
    // 相当于将列表元素指针 第一个取出指向NULL，下一个取出指个上一个取出元素，直到最后一个不取出，修改指向取可
    while (NULL != pLNode)
    {
        pLNext = pLNode->pNext;

        if (NULL == pLNext)
        {
            pInSLHead = pLNode;
        }

        pLNode->pNext = pLPrev;
        pLPrev = pLNode;
        pLNode = pLNext;
    }
}

void PrintSingleList(PSINGLELIST pInSLHead)
{
    if (NULL == pInSLHead)
    {
        return;
    }

    PSINGLELIST pLNode = pInSLHead;

    while (NULL != pLNode)
    {
        cout<<pLNode->iKey<<"  ";
        pLNode = pLNode->pNext;
    }

    cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    PSINGLELIST pHead = NULL;

    cout<<"构造一个成员为1-15的单链表"<<endl;
    
    CreateSingleList(pHead, 15);

    cout<<"打印单链表"<<endl;
    PrintSingleList(pHead);

    SingleListReverse(pHead);
    cout<<"逆置后的单链表"<<endl;
    PrintSingleList(pHead);

    return 0;
}