
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int mod=2520;
int index[2530];
int bit[20];
long long dp[20][mod][50];
int gcd(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
void init()
{
	int num=0;
	for(int i=1;i<=mod;i++)
	{
		if(mod%i==0)
		{
			index[i]=num++;
		}
	}
}
long long dfs(int pos,int presum,int prelcm,int doing)
{
	if(pos==-1)
	{
		if(presum%prelcm==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(!doing&&dp[pos][presum][index[prelcm]]!=-1)
	{
		return dp[pos][presum][index[prelcm]];
	}
	long long ans=0;
	int end=doing?bit[pos]:9;
	for(int i=0;i<=end;i++)
	{
		int nsum=(presum*10+i)%mod;
		int nlcm=prelcm;
		if(i)
		{
			nlcm=lcm(nlcm,i);
		}
		ans+=dfs(pos-1,nsum,nlcm,doing&&i==end);
	}
	if(!doing)
	{
		dp[pos][presum][index[prelcm]]=ans;
	}
	return ans;
}
long long solve(long long n)
{
	int len=0;
	while(n)
	{
		bit[len++]=n%10;
		n/=10;
	}
	return dfs(len-1,0,1,1);
}
int main()
{
	init();
	memset(dp,-1,sizeof(dp));
	int T;
	cin>>T;
	while(T--)
	{
		long long left,right;
		cin>>left>>right;
		cout<<solve(right)-solve(left-1)<<endl;
	}
	return 0;
}