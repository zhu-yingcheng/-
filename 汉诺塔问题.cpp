#include<stdio.h> 
#include <iostream>
using namespace std;
void hanoi(int n,char A,char B,char C) 
{ 
    if(n==1) 
          printf("Move disk %d from %c to %c\n",n,A,C); 
    else 
    { 
          hanoi(n-1,A,C,B); 
          printf("Move disk%d from %c to %c\n",n,A,C); 
          hanoi(n-1,B,A,C); 
    } 
} 
 
int main() 
{ 
    int n; 
    cout<<"����������n�Խ����ŵ�����⣺"<<endl;
	cin>>n; 
   // printf("����������n�Խ��n�׺�ŵ�����⣺\n"); 
    //scanf("%d",&n); 
    hanoi(n,'A','B','C'); 
}
