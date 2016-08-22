// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>


int candp(int a, int b, int c)
{
    int r=1;
    b=b+1;
    while(b!=1)
    {
        r=r*a;
        r=r%c;
        b--;
    }
    
    printf("%d\n",r);
    return r;
}

void main()
{
    int e,d,m,n,t,c,r;
    // ��Կ��˽Կ������ http://www.cnblogs.com/7hat/p/3407897.html
     int p = 233;
    int q = 9001;

    n = p*q;
    t = (p-1)*(q-1);

    // �����Ϊ7
    e = 7; // e��t����
    d = 1;

    while(((e*d)%t)!=1)   d++;

    // ��ʱ����ԿΪ��e, n����˽ԿΪ��d, n������Կ������˽Կ�Լ����ܡ�
    // N:2097233, M:9001 (2097233, 7) (1193143, 2097233)

    unsigned int c1 = candp(197372, d, n);
    unsigned int m1 = candp(333079, d, n);

    int c2 = candp(197372, d, n);
    int m2 = candp(333079, d, n);

    switch(r)
    {
    case 1: // ����
        c = candp(197372, e, n);
        printf("the cipher is %d\n", c);break;
    case 2: // ����
        m = candp(333079, d, n);
        printf("the cipher is %d\n", m);break;
    }

    getchar();
}
int _tmain1(int argc, _TCHAR* argv[])
{
    // N = M*233
    // M��ʹ��Nβ��Ϊ223�������λ��
    int M = 0;
    int N = 0;
    for (int i=999;i<10000; i++)
    {
        int n = i*233;    
        if (233 == n%1000)
        {
            M = i;
            N = n;
            printf("N:%d, M:%d\r\n", n, i);
        }
    }

    return 0;
}

