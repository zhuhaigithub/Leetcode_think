#include <iostream>
#include <string>

using namespace std;

int* Next(string ptr,int len)//求解next数组
{
	int *next;
	next=new int[len];
	int k=-1;
	next[0]=-1;//第一个赋值-1
	int j=0;
	while(j<len-1)//通过递推实现，j=len-1通过j=len-2得到
	{
		if(k==-1||ptr[j]==ptr[k])
		{
			k++;
			j++;
			next[j]=k;
		}
		else if(k!=-1&&ptr[j]!=ptr[k])//递推寻找更短的相同前缀和后缀
		{
			k=next[k];
		}
	}
	return next;
}

int KMP(string str,string ptr)
{
	int len=ptr.length();
	int *next;
	next=Next(ptr,len);
	int i=0;
	int j=0;
	while(i<str.length()&&j<len)
	{
		if(j==-1||str[i]==ptr[j])
		{
			i++;
			j++;
		}
		else if(j!=-1&&str[i]!=ptr[j])
		{
			j=next[j];//j==-1与next[0]=-1有关
		}
	}
	if(j==len)
	{
		return i-j;//返回下标
	}
	else
	{
		return -1;
	}

}

int main()
{
	string s="BBCABCDABABCDABCDABDE";
	string p="ABCDABD";

	cout <<KMP(s,p)<<endl;

}
