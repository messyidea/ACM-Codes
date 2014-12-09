
/***********************************************\
 |Author: YMC
 |Created Time: 
 |File Name: 
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
char str1[maxn];
char str2[maxn];
int m;
int k;
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
int sta[maxn],cn[maxn];
int main() {
//	freopen("input.txt","r",stdin);
	int a,b; 
    int nu;
	while(scanf("%d",&k) && k){
		//getchar();
		//scanf("%s",str1);
        scanf("%s",str1);
        scanf("%s",str2);
       // printf("%s\n",str1);
       // printf("%s\n",str2);
		int n1 = strlen(str1);
        int n2 = strlen(str2);
        int n = n1 + n2 + 1;
		for(int i=0;i<n1;++i) r[i] = str1[i];
        r[n1] = 1;
        for(int i=n1+1;i<n;++i) r[i] = str2[i-n1-1];
		r[n] = 0;
		da(r,sa,n+1,128);
		calheight(r,sa,n);
		for(int i=1;i<=n;i++) RMQ[i]=height[i];
		initRMQ(n);
        //cout<<lcp(2,7)<<endl;
        long long ans = 0,sum = 0;
        int top = 0;
        int cnt;
        for(int i=2;i<=n;++i){
            if(height[i] < k) {
                sum = top = 0;
            }
            else{
                cnt = 0;
                while(top > 0 && height[i] <= sta[top-1]){
                    top -- ;
                    sum -= cn[top] * (sta[top] - height[i]);    //sum 为当前那个字符串可以加的数目。
                    cnt += cn[top];     //共同前缀的数目
                }
                if(sa[i-1] < n1){
                    cnt ++;
                    sum += height[i] - k + 1;
                }
                sta[top] = height[i];
                cn[top ++] = cnt;
                if(sa[i] > n1) ans += sum;
            }
        }
        sum = top = 0;
       for(int i=2;i<=n;++i){
            if(height[i] < k) {
                sum = top = 0;
            }
            else{
                cnt = 0;
                while(top > 0 && height[i] <= sta[top-1]){
                    top -- ;
                    sum -= cn[top] * (sta[top] - height[i]);
                    cnt += cn[top];
                }
                if(sa[i-1] > n1){
                    cnt ++;
                    sum += height[i] - k + 1;
                }
                sta[top] = height[i];
                cn[top ++] = cnt;
                if(sa[i] < n1) ans += sum;
            }
        } 
        printf("%lld\n",ans);


	}
	return 0;
}
