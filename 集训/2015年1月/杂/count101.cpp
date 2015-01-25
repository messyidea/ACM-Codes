/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-25 12:08:41
 |File Name: count101.cpp
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
const int mod = 9997;
int dp[2][2][10010];
int n;
int solve(int a,int b,int l) {
    if(l >= n+1) return 1;
    if(dp[a][b][l] != -1) return dp[a][b][l];
    int& ans = dp[a][b][l];
    if(a == 1 && b == 0) {
        ans = solve(0,0,l+1);
        ans %= mod;
        return ans;
    } else {
        ans = solve(b,0,l+1) + solve(b,1,l+1);
        ans %= mod;
        return ans;
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n)) {
        if(n == -1) break;
        if(n < 0) {
            puts("0");
            continue;
        }
        if(n == 0) {
            puts("0");
            continue;
        } else if(n == 1) {
            puts("2");
            continue;
        } else if(n == 2) {
            puts("4");
            continue;
        } 
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        sum += solve(0,0,3);
        sum += solve(0,1,3);
        sum += solve(1,0,3);
        sum += solve(1,1,3);
        sum %= mod;
        printf("%d\n",sum);
    }
	return 0;
}

