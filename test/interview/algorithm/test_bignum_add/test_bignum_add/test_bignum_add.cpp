// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#define Max 101
void print(char sum[]);
void bigNumAdd(char a[],char b[],char sum[]);

int main()
{
    char a[Max];
    char b[Max];
    char sum[Max];
    gets(a);
    gets(b);

    bigNumAdd(a, b, sum);
    print(sum);

    return 0;
}

void bigNumAdd(char a[], char b[], char sum[])
{
    // ��ʼ��,���Ժ�λ�����кܴ������
    char m[Max] = {0};
    char n[Max] = {0};
    memset(sum, 0, Max*sizeof(char)); // ���ﲻ��д��memset(sum,0,sizeof(sum));ԭ���ע������1


    int lenA = strlen(a);
    int lenB = strlen(b);
    
    // �ַ�����ת���ַ���������
    for (int i = 0; i < lenA; i++)
    {
        m[i] = a[lenA-i-1]-'0';
    }

    for (int i=0;i<lenB;i++)
    {
        n[i] = b[lenB-i-1]-'0';
    }


    int c = 0; // ��ʾ��λ

    //λ����
    for (int i = 0;i<lenA||i<lenB;i++)
    {
        sum[i] = (m[i] + n[i] + c) % 10 + '0'; // �õ�ĩλ
        c = (m[i] + n[i] + c) / 10;           // �õ���λ
    }
}

void print(char sum[])
{
    int len = strlen(sum);

    int i = 0;
    for (i = len-1; sum[i] == 0; i--); //�ҵ���һ����Ϊ���λ�ã��������

    //��ת���
    for (int j = i; j >= 0; j--)
    {
        printf("%c", sum[j]);
    }

}
