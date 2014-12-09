/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/12 19:09:25
 |File Name: b.cpp
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
int T,n;
int da[10005];
int dp[1005][2];
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,n){
            scanf("%d",&da[i]);
        }
        memset(dp,0,sizeof(dp));
        if(da[n-1] >= 1){
            dp[n-1][0] = 1; //1
            dp[n-1][1] = 2;
        }
        bool fg = false;
        for(int i=n-2;i>=0;--i){
            if(da[i] == 1){
                dp[i][0] = dp[i+1][1];
                dp[i][1] = dp[i+1][0];
            } else {
                if(dp[i+1][0]==1 && dp[i+1][1]==1) {
                    fg = true;break;
                }
                if(dp[i+1][0]==1 || dp[i+1][1]==1){
                    dp[i][0] = 1;
                } else {
                    dp[i][0] = 2;
                }
                if(dp[i+1][0] == 2 || dp[i+1][1] == 2){
                    dp[i][1] = 2;
                } else {
                    dp[i][1] = 1;
                }
            }
        }
        if(fg) {
            puts("Yes");
            continue;
        }
        if(dp[0][0] == 1){
            puts("Yes");
        } else {
            puts("No");
        }
    }
	return 0;
}

