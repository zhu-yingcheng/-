#include<stdio.h>
#include<windows.h>
#define N 8 //可以根据N来修改棋盘的格数 
int count = 0;//设置一个计数器 
int chess[N][N] = {0};//用于存放棋盘的二维数组 
 
void print()//打印函数 
{	
	int i = 0;
	int j = 0;
	printf("*****************************************\n");
	for(i = 0; i<N ;i++)
	{
		for(j = 0; j<N ; j++)
		{
			printf("%d ",chess[i][j]);
		}
		printf("\n");
	}
	printf("*****************************************\n");
}
 
//判断是否会互吃 
//关键条件
//返回1 表示存在互吃
//返回0 表示正常 
int check(int i, int j)//i = 7,j = 4 
{	
	if(i == 0)
		return 0;//表示正常
  
	int k = 0;
	for(k = 0; k<i ; k++)
	{
		if(chess[k][j] == 1)//(0,4)(1,4)...
			return 1;
	}
	for( int s = 0,k = j+1; k<N ;k++)
	{	
						//(7,4)(6,5),(5,6),(4,7)
		if(chess[i-s-1][k] == 1)//(0,11),(1,10),(2,9),(3,8),(4,7)
			return 1;
		s++;
	}
	for(k = 0; k<j ;k++)
	{
		if(chess[i-k-1][j-k-1] == 1)//(6,3)(5,2)(4,1)(3,0)
			return 1;	
	}
	for(k = 0; k<N ; k++)
	{
		if(chess[k][j]==1)
			return 1;
	}
	return 0;
}
//判断棋盘上是否有一行存在没有皇后的情况 
//返回0 ，表示棋盘正常（每一行都有皇后）
//返回1 ，表示棋盘有错 
int check_all()
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for(i = 0; i<N ;i++)
	{	
		flag = 0;
		for(j = 0; j<N ; j++)
		{
			if(chess[i][j]==1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			return 1;//有错 
	}
	return 0;
}
//检查某一行是否存在皇后
//返回0 表示存在
//返回1 表示没皇后 
int check_line(int line)
{	
	if(line==0)
		return 0;
	int k = 0;
	int s = 0;
	int flag = 1;
	for(s = 0; s<line-1 ; s++)
	{	
		flag = 1;
		for(k = 0; k<N ;k++)
		{
			if(chess[s][k]==1)
				flag = 0;
		}
		if(flag==1)
			return 1;
	}
	return 0;
}
//递归的主要算法 
void queen(int i,int j)
{		
	//符合，置一，进入下一行
	if(check_line(i)==1)//若该行有皇后，返回 
		return ;
	if((i==(N-1)))//若此时是最后一行 
	{		
		if(check(i,j)==0)//当最后一行的皇后可以放下（表示可以成功放置）	
		{
			chess[i][j] = 1;//将该位置1，表示皇后 
			print();//打印 
			count++;//计数器+1 
		}
	}		
	if(check(i,j)==0)//当可以放皇后时 
	{	
		chess[i][j] = 1;//放入 
		//print();
		//Sleep(1000);
		queen(i+1,0);//进行下一行的皇后放置 
	}
 	if(j==N)//如果j等于列数，表明越界，返回 
		return ;
		
	chess[i][j] = 0;//将该位置0 
	//print();
	//Sleep(500);
	//不符合，置零，右诺
		queen(i,j+1);//将该行皇后右移一位 
}
int main(void)
{	
	queen(0,0);
	printf("\n%d×%d%的走法有%d种\n",N,N,count);
	return 0;
}
