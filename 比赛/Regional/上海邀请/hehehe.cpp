
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
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define MM(a,t) memset(a,t,sizeof(a))
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
int n,m,nx,ny;
int ttt;
char pan[100][100],xid[100][100],yid[100][100];
bool date[2592][2592],vis[2592];
int pei[2592];
bool find(int a){
    for(int i=1;i<=ttt;i++){
      if(date[a][i] && !vis[i]){
          vis[i]=true;
        if(pei[i]==0 || find(pei[i])){
          pei[i]=a;
          return true;    
        }    
        }
    }
    return false;
}
int main()
{
    int i,j,T,n2;
    char st[100];
    
    scanf("%d",&T);
    
    while(T--){
      scanf("%d%d",&n,&m);
      rep(i,n){
          scanf("%s",&st);
        rep(j,m)  pan[i][j]=st[j-1];
        }
      n2=1; nx=0; ny=0;
      rep(i,n){
       rep(j,m){
        if(pan[i][j]=='*'){
          xid[i][j]=n2;    
          nx=n2;
        } 
        if(pan[i][j]=='#') n2++;    
        }
        n2++;
        }

        n2=1;
      rep(j,m){
           rep(i,n){
        if(pan[i][j]=='*'){
          yid[i][j]=n2;    
          ny=n2;
        } 
        if(pan[i][j]=='#') n2++;    
        } 
      n2++;    
      }
       
        MM(date,0);
      rep(i,n)
        rep(j,m)
        if(pan[i][j]=='*') date[xid[i][j]][yid[i][j]]=1;  
      int res=0;
      MM(pei,0);
      ttt = max(nx,ny);
      rep(i,ttt){
            MM(vis,0);
            if(find(i)) res++;
        }
        printf("%d\n",res);
    }

    
    return 0;
}
