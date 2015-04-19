
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<queue>
#include<stack> 
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define MM(a,t) memset(a,t,sizeof(a))
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
int w,n;
char str[105][1005];
int s[105],P[105],W[105],len[105],maxn;
int main()
{
    int i,j,k,T=1,ans;
    while(scanf("%d%d",&w,&n)!=EOF)
    {
        if(w+n==0) break;
        maxn=0;
        rep(i,n){
          scanf("%s%d",str[i],&s[i]);
          len[i]=strlen(str[i]);
          maxn=max(maxn,s[i]);
        }
        rep(i,n){
          P[i]=8+(int)ceil(1.0*40*(s[i]-4)/(maxn-4));
          W[i]=(int)ceil(1.0*9*len[i]*P[i]/16);
        }
        ans=0;
        int yu=w,maxw=0,ff=0;
        rep(i,n){
       	  if(ff==0){
  	       	 yu-=W[i],maxw=max(maxw,P[i]);
  	       	 ff=1; continue;
  	       }
          if(yu>=W[i]+10){
            yu-=10+W[i];
			maxw=max(maxw,P[i]);	
          }	
          else ans+=maxw,maxw=0,yu=w,i--,ff=0;
        }
        printf("CLOUD %d: %d\n",T++,ans+maxw);
    }
 
    return 0;
}
