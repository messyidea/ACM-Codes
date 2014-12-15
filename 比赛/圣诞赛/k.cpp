
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
int a[1020],b[1020],c[1020];
int ans,n,n1,n2;
int main()
{
    int i,j;
 
    while(scanf("%d%d%d",&n1,&n2,&n)!=EOF){
      rep(i,n1) scanf("%d",&a[i]);
      rep(i,n2) scanf("%d",&b[i]);
      rep(i,n)  scanf("%d",&c[i]);
      sort(a+1,a+n1+1); sort(b+1,b+n2+1); sort(c+1,c+n+1);
      ans=0;
      rep(i,n1){
        int ii=1,tmp,pr=0;
        rep(j,n2)
        if(j!=1 && b[j]==b[j-1]){
          ans+=pr;  
        }
        else{
          pr=0;
          tmp=a[i]+b[j];
          while(ii<=n && c[ii]<tmp) ii++;
          while(ii<=n && c[ii]==tmp){
            pr++;
            ii++;   
          } 
          ans+=pr;
        }   
      }
      printf("%d\n",ans);
    }
     
    return 0;
}
/**************************************************************
    Problem: 1325
    User: 2014CH145
    Language: C++
    Result: Accepted
    Time:64 ms
    Memory:1692 kb
****************************************************************/
