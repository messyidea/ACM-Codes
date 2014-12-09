
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
double dp[1300][1300],val[1300][1300];
bool vis[1300][1300];
int n,m,nm;
int main()
{
    int i,j,T,n2,k;

    scanf("%d",&T);
    rep(n2,T){
        scanf("%d%d",&n,&m);
        rep(i,n) 
            rep(j,m) scanf("%lf",&val[i][j]);
        MM(dp,0); MM(vis,0); nm=(1<<n)-1;
        dp[0][0]=0; vis[0][0]=true; 
        for(i=0;i<m;i++)
            for(j=0;j<nm;j++)
                for(k=1;k<=n;k++)
                    if(vis[i][j] && (j & (1<<(k-1)))==0){
                        int ff=j|(1<<(k-1));
                        vis[i+1][ff]=true;
                        dp[i+1][ff]=max(dp[i+1][ff],dp[i][j]+val[k][i+1]);
                        if(ff==nm){
                            vis[i+1][0]=true;
                            dp[i+1][0]=max(dp[i+1][0],dp[i+1][ff]);     
                        }
                    }
        double res=0;
        for(i=0;i<nm;i++) res=max(res,dp[m][i]);
        printf("Case #%d: %.5lf\n",n2,res);
    }


    return 0;
}
