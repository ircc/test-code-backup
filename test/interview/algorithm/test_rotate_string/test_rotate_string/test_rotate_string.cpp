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

//�ַ�����ת���� ʵ�ֽ� str ��begin��end֮����ַ�����ת
void swap(char *str, int begin, int end)
{
    char ch;
    while (begin < end)
    {
        ch = *(str + begin);
        *(str + begin) = *(str + end);
        *(str + end) = ch;
        begin++;
        end--;
    }
}

void Rotate(char *str, int length ,int m)
{
    if (NULL == str || length == 1)
    {
        return;
    }
    swap(str, 0, m - 1);      // (abcdef, 0, 1) -> bacdef
    swap(str, m, length - 1); // (bacdef, 2, 5) -> bafedc
    swap(str, 0, length - 1); // (bafedc, 0, 5) -> cdefab
}

//���ַ���abcdef����ת2λ�õ��ַ���cdefab
int _tmain(int argc, _TCHAR* argv[])
{
    char chArr[] = "abcdef";
    char *p = chArr;
    cout<<p<<endl;
    Rotate(p, strlen(chArr), 2);
    cout<<p<<endl;
    return 0;
}