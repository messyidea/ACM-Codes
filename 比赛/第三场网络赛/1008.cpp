
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#define MM(a,t) memset(a,t,sizeof(a))
#define rep(i,n) for(i=1;i<=n;i++)
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
int n,ln,yu;
int a[100020],ex[100020];
ll gen[100];
ll maxres[100020];
bool vis[100020];
void setup(){
  int i,j;
  
  rep(i,100000)    maxres[i]=maxres[i-1]+i*2;
  rep(i,20) gen[i]=gen[i-1]*2+1;  
}
int main(){
    
    int i,j;
    
    setup();
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<=n;i++) scanf("%d",&a[i]);
        MM(vis,0);
        printf("%I64d\n",maxres[n]);
        ln=20; yu=n+1;
        for(i=n;i>=0;i--)
        {
          if(!vis[i] && yu==1){
              ex[i]=i;
            continue;    
            }
            while(!vis[i]){
              int tp=gen[ln]-i;
            if(tp<=n && tp>=0 && !vis[tp]){
              vis[i]=true;
              vis[tp]=true;    
              ex[i]=tp;
              ex[tp]=i;
              yu-=2;
            }     
            else ln--;
            }
        }
        for(i=0;i<=n;i++){
          printf("%d",ex[a[i]]);
          if(i==n) cout<<'\n';
          else     printf(" ");    
        }
    }
    
    return 0;
}
