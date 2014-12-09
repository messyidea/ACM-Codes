/***********************************************\
 |Author: YMC
 |Created Time: 2014/4/28 20:14:22
 |File Name: Frontcompression.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;
#define maxn 200005
int wa[maxn],wb[maxn],wv[maxn],wss[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) wss[i]=0;
     for(i=0;i<n;i++) wss[x[i]=r[i]]++;
     for(i=1;i<m;i++) wss[i]+=wss[i-1];
     for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) wss[i]=0;
       for(i=0;i<n;i++) wss[wv[i]]++;
       for(i=1;i<m;i++) wss[i]+=wss[i-1];
       for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int RMQ[maxn];
int mm[maxn];
int best[20][maxn];
void initRMQ(int n)						//RMQ的初始化
{
     int i,j,a,b;
     for(mm[0]=-1,i=1;i<=n;i++)
     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
     for(i=1;i<=n;i++) best[0][i]=i;
     for(i=1;i<=mm[n];i++)
     for(j=1;j<=n+1-(1<<i);j++)
     {
       a=best[i-1][j];
       b=best[i-1][j+(1<<(i-1))];
       if(RMQ[a]<RMQ[b]) best[i][j]=a;
       else best[i][j]=b;
     }
     return;
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)				//返回a和b后缀的最长公共前缀
{
    int t;
    a=rank[a];b=rank[b];
    if(a>b) {t=a;a=b;b=t;}
    return(height[askRMQ(a+1,b)]);
}
char str[maxn];
int m;
int r[maxn],sa[maxn];
int ll[maxn],rr[maxn];
int callen(int a){
	int sum = 1;
	while(a/10){
		a/=10;
		sum ++;
	}
	return sum;
}
int main() {
	//freopen("input.txt","r",stdin);
	int a,b; 
	while(scanf("%s",str)!=EOF){
		int n = strlen(str);
		for(int i=0;i<n;++i) r[i] = str[i];
		r[n] = 0;
		da(r,sa,n+1,128);
		calheight(r,sa,n);
		for(int i=1;i<=n;i++) RMQ[i]=height[i];
		initRMQ(n);
		scanf("%d",&m);
		long long  sum = 0;
		long long sum2 = 0;
		for(int i=0;i<m;++i){
			scanf("%d%d",&ll[i],&rr[i]);
			if(i == 0){
				sum += 1;
				sum += 2+rr[i]-ll[i];
				sum2+=rr[i]-ll[i]+1;
			}
			else{
				sum2+=rr[i]-ll[i]+1;
				int tp;
				//cout<<ll[i]<<" "<<ll[i-1]<<"  "<<lcp(ll[i],ll[i-1])<<endl;
				if(ll[i]!=ll[i-1])
					tp = lcp(ll[i],ll[i-1]);    //求第ll[i]位和第ll[i-1]位最长公共前缀
				else tp = 10000000;
				tp = min(tp,rr[i]-ll[i]);
				tp = min(tp,rr[i-1]-ll[i-1]);
				sum += callen(tp);
				sum += 2+rr[i]-ll[i]-tp;
			}
		}
		printf("%I64d %I64d\n",sum2,sum);
	}
	return 0;
}

