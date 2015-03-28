/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/28 19:00:02
 |File Name: a.cpp
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
int n,m;
ll dp[13][13][2];
ll sum;
ll A(int a,int b) {
    if(a < b) swap(a,b);
    ll ans = 1;
    for(int i=a+1;i<=a+b;++i) ans *= i;
    for(int i=b;i>1;--i) ans /= i;
    return ans;
}
ll gcd(ll a,ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
ll solve(int n,int m,int k) {
    if(n == 0) return 0;
    if(m == 0 && k == 0 && n != 0) {
        return 1;
    }
    else if(m == 0) return 0;
    if(dp[n][m][k] != -1) return dp[n][m][k];
    ll &ans = dp[n][m][k];
    ans = 0;
    if(k == 1) {
        ans += solve(n-1,m,1);
        ans += solve(n,m-1,0);
    } else {
        ans += solve(n-1,m,1);
        ans += A(n-1,m);
        ans += solve(n,m-1,0);
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    ll ans = 0,ans2;
    while(scanf("%d %d",&n,&m) != EOF) {
        if(n == 0 || m == 0) {
            puts("0");
            continue;
        }
        memset(dp,-1,sizeof(dp));
        ans = 0;
        ans += solve(n-1,m,1);
        ans += solve(n,m-1,0);
        ans2 = A(n,m);
        ll t = gcd(ans,ans2);
        ans /= t;
        ans2 /= t;
        printf("%lld/%lld\n",ans,ans2);
    }
	return 0;
}

