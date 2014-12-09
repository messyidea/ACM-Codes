#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<queue>
#include<map>
#include<stack> 
#include<vector>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define MM(a,t) memset(a,t,sizeof(a))
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
int n,b[10],ii;
int a[100020];
int res[100020];
map<int,bool> g;
map<int,int> index;
bool ff;
int main()
{
    int i,j;
    
    while(scanf("%d%d%d",&n,&b[0],&b[1])!=EOF){
      ff=true;
      g.clear(); index.clear();
      if(b[0]>b[1]) ii=0;
      else          ii=1;
      rep(i,n){
        int tmp;
        scanf("%d",&tmp);
        a[i]=tmp;
        g[tmp]=true;
        index[tmp]=i;
      }
      sort(a+1,a+n+1);
      rep(i,n)
      if(g[a[i]])
      {
        int t1=a[i],t2=b[ii]-t1,t3=b[1-ii]-t1;
        if(g[t2]){
          res[index[t1]]=ii;
          res[index[t2]]=ii;
          g[t1]=false; g[t2]=false; 
        }   
        else if(g[t3]){
               res[index[t1]]=1-ii;
               res[index[t3]]=1-ii;
               g[t1]=false;
               g[t3]=false;
             }
             else {
                ff=false;
                break;
             }
      }
      if(ff){
        printf("YES\n");
        rep(i,n-1) printf("%d ",res[i]);
        printf("%d\n",res[n]);  
      }
      else printf("NO\n");
    }
    
    
    return 0;
}
