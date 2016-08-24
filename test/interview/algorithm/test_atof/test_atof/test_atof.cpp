// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


#include<stdio.h>
#include<string.h>
#include<assert.h>

// �ж��Ƿ�Ϊ���� �Ƿ���1�����Ƿ���0
int is_digit(char ch)
{
	if(ch>='0'&&ch<='9')
		return 1;
	else
		return 0;
}

// �ж��Ƿ�Ϊ�ո��Ƿ���1�����Ƿ���0
int is_space(char ch)
{
	if(ch==' ')
		return 1;
	else
		return 0;
}

// ��������߼���������ȷ���������ok�ģ�������������ַ����к��������ַ��Ļ��ᵼ�����������
// Ӧ�ü��ϴ����߼���1�������ַ����ش���  ���� 2 ����ȫ�ִ���ֵ�������ִ���ʱ�Ѵ���ֵ����Ϊָ��ֵ
double atof(char *s)
{
	double power,value;
	int i,sign;
	assert(s!=NULL);//�ж��ַ����Ƿ�Ϊ��

	//��ȥ�ַ���ǰ�Ŀո�
	for(i=0; is_space(s[i]); i++);
	{
		sign = (s[i]=='-')?-1:1;
	}
	

	//Ҫ���з���λ��ǰ��һλ
	if(s[i]=='-'||s[i]=='+')
		i++;

	//����С����ǰ������
	for(value=0.0; is_digit(s[i]); i++)
	{
		value = value*10.0 + (s[i]-'0');
	}

	if(s[i]=='.')
		i++;

	//����С����������
	for(power=1.0; is_digit(s[i]); i++)
	{
		value = value*10.0+(s[i]-'0');
		power *= 10.0;
	}
	return sign*value/power;
}

int main()
{
	double sum;
	char line[100]="8510.23568";
	sum = atof(line);
	printf("%lf\n",sum);
	return 0;
}