/*************************************************************************
    > File Name: BinarySearch.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月28日 星期五 21时17分51秒
    > 折半查找
 ************************************************************************/

#include<iostream>
using namespace std;
//对于p指向的一个长度为length的数组，查找是否包含有value
//如果数组中有value，则返回下标；否则返回-1
int BinarySearch(int *p, int length, int value)
{

	int low = 0; 
	int high = length - 1;
	while(low < high)
	{
		int middle = (low + high) / 2;
		
		//在左半部分
		if(value < p[middle])
		{
			high = middle - 1;
		}
		//在右半部分
		else if(value > p[middle])
		{
			low = middle + 1;
		}
		//middle指向的正好是要查找的value
		else
		{
			return middle;
		}
	}
	return -1;
}

int main()
{
	int a[8] = {1, 3, 5, 8, 10, 19, 22, 30};
	int result1 = BinarySearch(a, 8, 22);
	cout << result1 << endl;
	int result2 = BinarySearch(a, 8, 20);
	cout << result2 << endl;
}
