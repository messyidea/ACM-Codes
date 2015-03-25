/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 20:33:09
 |File Name: i.cpp
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
#define mod 1000000007
ll dp[101][101][2][2];
int n;
ll dfs(int i,int j,int a,int b) {
    if(a == 0 && b == 0) return 1;
    if(i == n && j == n) {
        return min(a,b) + 1;
    } 
    if(dp[i][j][a][b] != -1) return dp[i][j][a][b];
    ll &ans = dp[i][j][a][b];
    ans = 0;
    if(j < i) {
        if(b >= 0) {
            ans += dfs(i,j+1,a,0);
            ans %= mod;
        }
        if(b >= 1) {
            ans += dfs(i,j+1,a,1);
            ans %= mod;
        }
        if(b >= 2) {
            ans += dfs(i,j+1,a,2);
            ans %= mod;
        }
    }
    if(i < n) {
        if(a >= 0) {
            ans += dfs(i+1,j,0,b);
            ans %= mod;
        }
        if(a >= 1) {
            ans += dfs(i+1,j,1,b);
            ans %= mod;
        }
        if(a >= 2) {
            ans += dfs(i+1,j,2,b);
            ans %= mod;
        }
    }
    ans %= mod;
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) != EOF) {
        memset(dp,-1,sizeof(dp));
        ll ans = dfs(1,1,2,2);
        ans %= mod;
        printf("%lld\n",ans);
    }
	return 0;
}

