#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cstdio>
using namespace std;
int fibonacci(int i)
{
	if (i <= 2)
		return i == 0 ? 0 : 1;//����ݹ����������
	return fibonacci(i - 1) + fibonacci(i - 2);
}

int main(void)
{
	int i,j;
	cout<<"�����·ݣ�"<<endl;
	cin>>j; 
	for (i = 1; i <= j; i++)
		cout<<"����"<<i<<"���º������Ϊ��"<<fibonacci(i)<<endl; 
	system("pause");
	return 0;
}
