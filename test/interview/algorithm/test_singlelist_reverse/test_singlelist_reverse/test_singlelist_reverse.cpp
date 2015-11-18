// test.cpp : �������̨Ӧ�ó������ڵ㡣
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

//����һ��ֵΪ��1��iInNum�ĵ�����
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

//���õ�����
void SingleListReverse(PSINGLELIST& pInSLHead)
{
    if (NULL == pInSLHead)
    {
        return;
    }

    PSINGLELIST pLNode = pInSLHead;
    PSINGLELIST pLPrev = NULL;
    PSINGLELIST pLNext = NULL;

    // ������Ԫ��һ��һ��ȡ������ȡ����Ԫ��ָ��pLPrev ʵ���ϲ�ȡ��ֻ���޸���ָ��ָ����ѣ����ҽ�������ָ��ָ�����һ��Ԫ��
    // �൱�ڽ��б�Ԫ��ָ�� ��һ��ȡ��ָ��NULL����һ��ȡ��ָ����һ��ȡ��Ԫ�أ�ֱ�����һ����ȡ�����޸�ָ��ȡ��
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

    cout<<"����һ����ԱΪ1-15�ĵ�����"<<endl;
    
    CreateSingleList(pHead, 15);

    cout<<"��ӡ������"<<endl;
    PrintSingleList(pHead);

    SingleListReverse(pHead);
    cout<<"���ú�ĵ�����"<<endl;
    PrintSingleList(pHead);

    return 0;
}