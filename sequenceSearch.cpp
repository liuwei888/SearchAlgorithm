/*************************************************************************
    > File Name: sequenceSearch.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月28日 星期五 21时08分48秒
    > 顺序查找
 ************************************************************************/

#include<iostream>
using namespace std;
//指针p指向的数组有length个元素,在数组中查找value，若存在，返回下标
int SequenceSearch(int *p, int length, int value)
{
	for(int i = 0; i < length; i++)
	{
		if(p[i] == value)
			return i;
	}
	return -1;
}

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int result1 = SequenceSearch(a, 5, 2);
	cout << result1 << endl;
	int result2 = SequenceSearch(a, 5, 6);
	cout << result2 << endl;
	int result3 = SequenceSearch(a, 5, 10);
	cout << result3 << endl;
}
