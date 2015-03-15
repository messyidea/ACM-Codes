/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/15 15:43:12
 |File Name: g.cpp
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
int n;
char ss[1005];
char ss2[1005];
int dp[1005][1005];
void dpit() {
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=n;++j) dp[i][j] = 0;
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(ss[i-1] == ss2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
    }
    printf("%d\n",n - dp[n][n]);
    
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s",ss);
        for(int i=0;i<n;++i) {
            if(ss[i] == '0') ss2[n-i-1] = '1';
            else ss2[n-i-1] = '0';
        }
        dpit();
        
    }
	return 0;
}

