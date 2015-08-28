/*************************************************************************
    > File Name: ratioSearch.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月29日 星期六 00时24分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

//在p指向的长度为length的数组中，查找是否存在value
//若存在，则返回value的下标；若不存在，则返回-1
int RatioSearch(int *p, int length, int value)
{
	if(NULL == p || length <= 0)
		return -1;

	int low = 0;
	int high = length - 1;
	while(low < high)
	{
		//这里middle不是传统二叉排序中的middle
		//这里middle不是机械的指向low和high的中间
		//而是指向value最有可能出现的位置
		int middle = (value - p[low]) * (high - low) / (p[high] - p[low]);
		if(value < p[middle])
		{
			high = middle - 1;
		}
		else if(value > p[middle])
		{
			low = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

int main()
{
	int a[6] = {12, 34, 56, 90, 190, 200};
	int result1 = RatioSearch(a, 6, 200);
	cout << result1 << endl;
	int result2 = RatioSearch(a, 6, 250);
	cout << result2 << endl;
}
