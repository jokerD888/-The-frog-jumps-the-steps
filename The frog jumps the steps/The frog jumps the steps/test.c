#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//问题描述：一只青蛙一次可以跳一个台阶，也可以跳两个台阶。求青蛙跳上n级台阶有多少种跳法？
// 类似于斐波那契数列（1，1，2，3，5，8...） 
// 经过n=1~5的计算，结果依次为1，2，3，5，8,相比于斐波那契数列，此结果是从第二项开始往后
//递归法
//可以设想青蛙现在已经在第n级台阶，那么它上一步是怎么跳的呢
//它上一步可能是跳了两步跳到第n级的，也可能是跳了一步跳到第n级的，这就有两种跳法了，即f(n)=f(n-1)+f(n-2)
//现在再设想两种情况
//1.它站在第n-1级,此时它的上一步也有两种跳法，f(n-1)=f(n-1-1)+f(n-1-2)=f(n-2)+f(n-3)
//2.它站在第n-2级,此时它的上一步也有两种跳法，f(n-2)=f(n-2-1)+f(n-2-2)=f(n-3)+f(n-4)
//即此问题的递归规律即是f(n)=f(n-1)+f(n-2)
// 
//但递归法的时间复杂度为O(2^N),极为“耗时”

//int Jump(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n == 1)
//	{
//		return 1;
//	}else if (n == 2)
//	{
//		return 2;
//	}
//	else
//	{
//		return Jump(n - 1) + Jump(n - 2);
//	}
//
//}
////非递归算法
////此算法时间复杂度为O(N),相比较于递归算法，高效许多，可读性也较高。
//int Jump1(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n == 1)
//	{
//		return 1;
//	}
//	else if (n == 2)
//	{
//		return 2;
//	}
//	int a = 1;
//	int b = 2;
//	int tmp = 0;
//	int count = 2;
//	while (count <= n)
//	{
//		tmp = a;
//		a = b;
//		b += tmp;
//		count++;
//	}
//	return b;
//}
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Jump1(n);
//	printf("%d\n", ret);
//	return 0;
//}


//问题：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
//此问题也可以向上面一样设想
//f(n)=f(n-1)+f(n-2)+f(n-3)...+f(n-(n-1))+f(n-n)     =     f(0)+f(1)+f(2)+f(3)+...+ f(n-2)+f(n-1)
//f(n-1)=f(n-2)+f(n-3)+f(n-4)...+f(n-1-(n-2))+f(n-1-(n-1))=f(0)+f(1)+f(2)+f(3)+...+ f(n-2)
//经上式观察发现，f(n)=2*f(n-1)
//据此可写出递归
//时间复杂度为O(N)
long long Jump3(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return 2 * Jump3(n-1);
}
//据观察可知，此结果符合等比数列定义
//首项为1，公比为2，直接套公式可得
long long Jump4(int n)
{
	//return pow(2, n - 1);//此处pow函数需要包含<math.h>
	return (long long)(pow(2, (long long)n - 1));//避免算数溢出
}
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	long long ret = Jump4(n);
	printf("%lld\n", ret);
	return 0;
}


