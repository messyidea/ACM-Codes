//设dp[i][j][cnt]表示还剩余i行，j列未覆盖且已经用了cnt个棋子的概率

#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 111111;
const int maxm = 111111;

int n,m;
double d[55][55][3333];

void init()
{
    memset(d,0,sizeof(d));
    d[0][0][0] = 1;
    for(int k = 1;k<=n*m;k++){
        for(int j = 1;j<=m;j++){
            for(int i = 1;i<=n;i++){
                if(i!=n||j!=m)
                d[i][j][k] = d[i][j][k-1]*(double(i*j-k+1)/(n*m-k+1))+
                             d[i-1][j-1][k-1]*(double((n-i+1)*(m-j+1))/(n*m-k+1))+
                             d[i][j-1][k-1]*(double(i*(m-j+1))/(n*m-k+1))+
                             d[i-1][j][k-1]*(double(j*(n-i+1))/(n*m-k+1));
                else
                d[i][j][k] = d[i-1][j-1][k-1]*(double((n-i+1)*(m-j+1))/(n*m-k+1))+
                             d[i][j-1][k-1]*(double(i*(m-j+1))/(n*m-k+1))+
                             d[i-1][j][k-1]*(double(j*(n-i+1))/(n*m-k+1));
            }
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    init();
    double ans = 0;
    for(int i = 0;i<=n*m;i++){
        ans += d[n][m][i]*i;
    }
    printf("%.16lf\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
        }
    }
    return 0;
}

