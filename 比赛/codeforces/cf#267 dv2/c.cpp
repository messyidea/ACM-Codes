/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/19 21:01:18
 |File Name: c.cpp
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
#define N 5005
int n,m,k;
ll da[N];
ll sum[N];
ll dp[N][N];
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d%d%d",&n,&m,&k)) {
        sum[0] = 0;
        srep(i,n){
            scanf("%I64d",&da[i]);
            sum[i] = sum[i-1] + da[i];
        }
        dp[0][0] = 0;
        ll ans = 0;
        srep(i,n){
            srep(j,k){
                if(i - m < 0) continue;
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                dp[i][j] = max(dp[i-m][j-1] + sum[i] - sum[i-m],dp[i][j]);
                if(j == k) ans = max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

