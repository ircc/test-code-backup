// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


#include<stdio.h>
#include<string.h>
#include<assert.h>

// 判断是否为数字 是返回1，不是返回0
int is_digit(char ch)
{
	if(ch>='0'&&ch<='9')
		return 1;
	else
		return 0;
}

// 判断是否为空格，是返回1，不是返回0
int is_space(char ch)
{
	if(ch==' ')
		return 1;
	else
		return 0;
}

// 这个处理逻辑在输入正确的情况下是ok的，但是如果输入字符串中含有其他字符的话会导出输出错误结果
// 应该加上处理逻辑，1非数字字符返回错误  或者 2 设置全局错误值，当出现错误时把错误值设置为指定值
double atof(char *s)
{
	double power,value;
	int i,sign;
	assert(s!=NULL);//判断字符串是否为空

	//除去字符串前的空格
	for(i=0; is_space(s[i]); i++);
	{
		sign = (s[i]=='-')?-1:1;
	}
	

	//要是有符号位就前进一位
	if(s[i]=='-'||s[i]=='+')
		i++;

	//计算小数点前的数字
	for(value=0.0; is_digit(s[i]); i++)
	{
		value = value*10.0 + (s[i]-'0');
	}

	if(s[i]=='.')
		i++;

	//计算小数点后的数字
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