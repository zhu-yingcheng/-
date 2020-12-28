/*哥尼斯堡七桥问题*/
#include<stdio.h>
int main()
{	
	int arr[4][4]={{0,2,0,1},{2,0,2,1},{0,2,0,1},{1,1,1,0}};  /*数组表示第n个城区与包括自己在内的其他四个城区的桥数*/ 
	int count=0;
	int degree;
	for(int i=0;i<4;i++){
		degree=0;
		for(int j=0;j<4;j++) /*将通过节点i的桥数求和*/
			degree+=arr[i][j];
			
		if(degree%2!=0)  /*桥数为基数*/
			count++;
			
		printf("****%d***",degree);
	}
	if(count==0)
		printf("存在欧拉回路\n");
	else
		printf("有%d个地方通奇数桥，不存在回路！",count);
	return 0;
}

