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
    cout<<"请输入数字n以解决汉诺塔问题："<<endl;
	cin>>n; 
   // printf("请输入数字n以解决n阶汉诺塔问题：\n"); 
    //scanf("%d",&n); 
    hanoi(n,'A','B','C'); 
}
