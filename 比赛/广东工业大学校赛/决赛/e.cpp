/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/15 13:50:53
 |File Name: e.cpp
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
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int dp[10005][5][5];
int n,t,a,b,c;
int da[10005];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<=n;++i) {
            for(int j=0;j<5;++j) {
                for(int k=0;k<5;++k) {
                    dp[i][j][k] = inf;
                }
            }
        }
        dp[0][0][0] = 0;
        srep(i,n) {
            scanf("%d",&da[i]);
        }
        srep(k,n) {
            for(int i=0;i<5;++i) {
                dp[k][i][da[k]] = min(dp[k][i][da[k]],dp[k-1][i][da[k-1]] + abs(da[k] - da[k-1]));
                dp[k][da[k]][i] = min(dp[k][da[k]][i],dp[k-1][da[k-1]][i] + abs(da[k] - da[k-1]));
            }
            //dp[k][da[k-1]][da[k]]
            for(int i=0;i<5;++i) {
                dp[k][da[k-1]][da[k]] = min(dp[k][da[k-1]][da[k]], dp[k-1][da[k-1]][i] + abs(i - da[k]));
                dp[k][da[k]][da[k-1]] = min(dp[k][da[k]][da[k-1]], dp[k-1][i][da[k-1]] + abs(i - da[k]));
            }
        }
        int ans = inf;
        for(int i=0;i<5;++i) {
            ans = min(ans,dp[n][i][da[n]]);
            ans = min(ans,dp[n][da[n]][i]);
        }
        printf("%d\n",ans);

    }
	return 0;
}

