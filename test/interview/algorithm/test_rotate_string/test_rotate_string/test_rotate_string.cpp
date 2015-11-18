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

//字符左串旋转函数 实现将 str 从begin到end之间的字符左旋转
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

//把字符串abcdef左旋转2位得到字符串cdefab
int _tmain(int argc, _TCHAR* argv[])
{
    char chArr[] = "abcdef";
    char *p = chArr;
    cout<<p<<endl;
    Rotate(p, strlen(chArr), 2);
    cout<<p<<endl;
    return 0;
}