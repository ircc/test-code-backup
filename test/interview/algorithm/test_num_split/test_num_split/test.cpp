// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

//���⣺
//����һ������ 
//�ж��Ƿ����������Ԫ�أ����ǽ����ִ���Ϊ�ĸ��Ӵ�������ÿ���Ӵ�������֮�;���ͬ(��3��Ԫ�ز��������) 
//
//Ҫ��ʱ�临�ӶȺͿռ临�ӶȾ����ܳ���O(n)


//˼·��
//����������˵����ԣ�ö�ٵ�һ�εĺͣ� ��һ�εĺ�ȷ���ˣ���ô��������2��3��4�εĺ;Ͷ�ȷ���ˣ�ʲô�������أ� ����i���ƣ�j��k��Ҫ���ơ�����ǵ������ˣ���һ�α����ô234�ζ�Ҫ�������i��j��k����ֻ�������ƣ���������и���û�е������ˡ�����

//#include <bits/stdc++.h>
//using namespace std;
#define fir sum[i - 1]
#define sec sum[j - 1] - sum[i]
#define thi sum[k - 1] - sum[j]
#define fou sum[n] - sum[k]

typedef long long LL;
const int maxn = 1e5+100;
int n;
LL a[maxn], sum[maxn];

bool solve()
{
	for(int i = 1, j = 1, k = 1; i <= n; i++)
	{
		while(fir > sec && j < n) j++; if(fir != sec) continue;   //�����һ�δ��ڵڶ��ξ�һֱ���ƣ��˳�while����������ڣ�˵���ڶ��δ��ڵ�һ�Σ���Ҫ�����ƶ���һ�Σ����������ȣ���ô����ȥ�ƶ�������

		while(sec > thi && k < n) k++; if(sec != thi) continue; //������ͬ���������Ķ�

		if(fir == sec && sec == thi && thi == fou)
		{
			printf("i = %d, j = %d, k = %d\n", i, j, k);
			return true;
		}
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%I64d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}

	puts(solve()?"YES":"NO");
	return 0;
}