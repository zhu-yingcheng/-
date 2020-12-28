/*暴力匹配算法*/ 
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
 
int main()
{
	int index(string s,string t,int pos);
	char m[20],n[10];	
	cout<<"输入主串："<<endl; 
	cin>>m;
	cout<<"输入子串："<<endl; 
	cin>>n;
	cout<<index(m,n,0)<<endl; 

} 
int index(string s,string t,int pos){
    int i=pos;//pos为第几位开始匹配 
    int j=0;
    int slen = s.length();
    int tlen = t.length();
    while(i<slen&&j<tlen)//
	{
        if(s[i]==t[j])
		{ 
			i++,j++;
		}
        else
		{
            i=i-j+1;//i=i-(j-1) 
            j=0;
        }
    }
    if(j==tlen) 
		return i-tlen+1;
    return -1;
}
