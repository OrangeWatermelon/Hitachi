//构建最小堆(数组实现)
#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a[] = { 5,2,8,3,1,4,9,6,7 };
	int size = 9;
	//int l = size / 2 - 1; 
	//cout << a[l] << ' ' << l;
	int t = 0;
	int min;
	for (int n = 0; (n = size / 2 - 1) >= 0; size--)
	{
		int l = n * 2 + 1;
		min = l;
		if (a[l + 1] < a[l])
		{
			min = l+1;
		}
		if (a[n] > a[min])
		{
			int tmp = a[n];
			a[n] = a[min];
			a[min] = tmp;
		}
	}
	for (auto i : a)
	{
		cout << i;
	}
}
