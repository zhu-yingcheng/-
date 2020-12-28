#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cstdio>
using namespace std;
int fibonacci(int i)
{
	if (i <= 2)
		return i == 0 ? 0 : 1;//满足递归结束的条件
	return fibonacci(i - 1) + fibonacci(i - 2);
}

int main(void)
{
	int i,j;
	cout<<"输入月份："<<endl;
	cin>>j; 
	for (i = 1; i <= j; i++)
		cout<<"经过"<<i<<"个月后的数量为："<<fibonacci(i)<<endl; 
	system("pause");
	return 0;
}
