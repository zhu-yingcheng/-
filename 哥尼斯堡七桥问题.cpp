/*����˹����������*/
#include<stdio.h>
int main()
{	
	int arr[4][4]={{0,2,0,1},{2,0,2,1},{0,2,0,1},{1,1,1,0}};  /*�����ʾ��n������������Լ����ڵ������ĸ�����������*/ 
	int count=0;
	int degree;
	for(int i=0;i<4;i++){
		degree=0;
		for(int j=0;j<4;j++) /*��ͨ���ڵ�i���������*/
			degree+=arr[i][j];
			
		if(degree%2!=0)  /*����Ϊ����*/
			count++;
			
		printf("****%d***",degree);
	}
	if(count==0)
		printf("����ŷ����·\n");
	else
		printf("��%d���ط�ͨ�����ţ������ڻ�·��",count);
	return 0;
}

