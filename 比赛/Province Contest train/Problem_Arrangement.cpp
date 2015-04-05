/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/5 15:23:06
 |File Name: Problem_Arrangement.cpp
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
int da[15][15];
int dp[(1<<12) + 5][505];
inline int gg(int t) {
    int count = 0;
    for(int i=0;i<12;++i) {
        if(t & (1<<i)) count ++;
    }
    return count;
}
inline int A(int n) {
    int ret = 1;
    for(int i=1;i<=n;++i) ret *= i;
    return ret;
}
int gcd(int a,int b) {
    return b == 0 ? a:gcd(b, a%b);
}
int main() { 
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        m--;
        rep(i,n) {
            rep(j,n) {
                scanf("%d",&da[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=0;i<(1<<n);++i) {
            int tp = gg(i);
            for(int j=0;j<n;++j) {
                if(((i>>j) & 1) == 0) {
                    for(int k=m;k>=da[tp][j];--k) {
                        if(dp[i][k-da[tp][j]]) {
                            dp[i|(1<<j)][k] += dp[i][k-da[tp][j]];
                        }
                    }
                    //dp[][i&(1<<j)] = dp[][i] + da[i][j];
                }
            }
        }
        int tp = (1 << n) - 1;
        int sum = 0;
        for(int i=0;i<=m;++i) {
            sum += dp[tp][i];
        }
        int all = A(n);
        sum = all - sum;
        tp = gcd(sum, all);
        if(sum) {
            printf("%d/%d\n",all/tp,sum/tp);
        } else {
            printf("No solution\n");
        }
    }
	return 0;
}

