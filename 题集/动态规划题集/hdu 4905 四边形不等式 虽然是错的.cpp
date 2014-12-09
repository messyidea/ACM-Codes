
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x3f3f3f3f
#define MAXN 3010
#define MAXM 110
#define MOD 1000000007
#define MAXNODE 4*MAXN
#define eps 1e-9
using namespace std;
typedef long long LL;
int T,N;
int a[MAXN],g[MAXN][MAXN],s[MAXN][MAXN];
LL dp[MAXN][MAXN];
int gcd(int a,int b){
    return a%b?gcd(b,a%b):b;
}
void init(){
    for(int i=1;i<=N;i++){
        g[i][i]=a[i];
        for(int j=i+1;j<=N;j++) g[i][j]=gcd(g[i][j-1],a[j]);
    }
}
int main(){
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",&a[i]);
        init();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            s[i][i]=i;
            dp[i][i]=a[i];
        }
        for(int l=1;l<N;l++)
            for(int i=1;i+l<=N;i++){
                int j=i+l;
                for(int k=s[i][j-1];k<=s[i+1][j];k++){
                    if(k<j&&dp[i][j]<dp[i][k]+dp[k+1][j]+g[i][j]){
                        dp[i][j]=dp[i][k]+dp[k+1][j]+g[i][j];
                        s[i][j]=k;
                    }
                }
            }
        printf("%I64d\n",dp[1][N]);
    }
    return 0;
}
