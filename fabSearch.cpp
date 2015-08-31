/*************************************************************************
    > File Name: fabSearch.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月28日 星期五 15时52分32秒
    > 斐波拉契查找
 ************************************************************************/

#include<iostream>
#define MAXSIZE 20
using namespace std;

//构建斐波拉契数列
void Fab(int *f)
{
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i < MAXSIZE; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
}

int FabSearch(int *arr, int length, int value)
{
	int fab[MAXSIZE];
	int low = 0, high = length - 1;
	int k = 0;     //length = fab(k)
	Fab(fab);
	while(fab[k] - 1 < length)
	{
		k++;
	}
	
	//把数组补全，使其元素个数是斐波拉契中的一个数
	for(int i = length; i < fab[k] - 1; i++)
	{
		arr[i] = arr[high];
	}

	while(low <= high)
	{
		int middle = low + fab[k-1] - 1;
		if(value < arr[middle])
		{
			high = middle - 1;
			k = k - 1;
		}
		else if(value > arr[middle])
		{
			low = middle + 1;
			k = k - 2;
		}
		else
		{
			if(middle <= high)
				return middle;
			else
				return -1;
		}
	}
	return -1;
}

int main()
{
	int a[] = {1, 2, 3, 6, 12, 23, 45, 66, 99, 100, 188, 200, 290};
	int result = FabSearch(a, 13, 100);
	cout << result << endl;
}
