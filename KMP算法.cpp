/*KMP模式匹配算法*/ 
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int next[30];
void get_next(string t)
{
	int i=0;
	next[0]=-1;
	int k=-1;
	int tlen = t.length();
	while(i<tlen-1)
	{
		if(k==-1 || t[i]==t[k])
			next[++i]=++k;
		else 
		    k=next[k];
    }
} 
int KMP(string s,string t)
{
	int i=0;
	int j=0;
	get_next(t);
	int slen = s.length();
	int tlen = t.length();
	while(i<slen&&j<tlen)
	{
		if(j==-1||s[i]==t[j])
			i++,j++;
		else
			j=next[j];
	}
	if(j==tlen) 
		return i-j+1;
	else 
	 	return -1;
} 
int main()
{
	int index(string m,string t,int pos);

	char m[20],t[10];	
	cout<<"输入主串："<<endl; 
	cin>>m;
	cout<<"输入子串："<<endl; 
	cin>>t;
	get_next(t); //计算待匹配子串的next表 
	cout<<KMP(m,t)<<endl; 

}
