// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

//题意：
//给定一串数字 
//判断是否存在这三个元素，它们将数字串分为四个子串，其中每个子串的数字之和均相同(该3个元素不纳入计算) 
//
//要求时间复杂度和空间复杂度均不能超过O(n)


//思路：
//奇妙的利用了单调性，枚举第一段的和， 第一段的和确定了，那么接下来的2，3，4段的和就都确定了，什么单调性呢？ 就是i右移，j，k都要右移。这就是单调性了，第一段变大，那么234段都要变大，所以i，j，k，都只会往右移，如果有正有负就没有单调性了。。。

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
		while(fir > sec && j < n) j++; if(fir != sec) continue;   //如果第一段大于第二段就一直右移，退出while，如果不等于，说明第二段大于第一段，就要重新移动第一段，扩大，如果想等，那么就下去移动第三段

		while(sec > thi && k < n) k++; if(sec != thi) continue; //第三段同理，最后检查第四段

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