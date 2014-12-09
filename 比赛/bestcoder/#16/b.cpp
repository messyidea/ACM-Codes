/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/1 19:19:18
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
int da[1005];
int dp[1005];
bool fg[1005];
int pre[1005];
int n;
void dodp() {
    memset(fg,false,sizeof(fg));    //表示没有重复
    for(int i=1;i<=n;++i) {
        dp[i] = 1; 
        pre[i] = i;
    }
    for(int i=1;i<=n;++i) {
        int tp = -1,p = -1;
        for(int j=i-1;j>=1;--j) {
            if(da[j] < da[i] && dp[j] > tp) {
                tp = dp[j]; p = j;
                fg[i] = false;
            } else if(da[j] < da[i] && dp[j] == tp){
                fg[i] = true;
            }
        }
        if(p == -1) {
            fg[i] = false;
        } else {
            dp[i] = max(dp[i],tp + 1);
            pre[i] = p;
        }
    }
    int ans = 0;
    int pp = -1;
    bool ff = false;
    for(int i=1;i<=n;++i) {
        if(dp[i] > ans) {
            ans = dp[i];
            pp = i;
            ff = false;
        } else if(dp[i] == ans){
            ff = true;
        }
    }
    if(ff){
        printf("%d\n",ans);
        return ;
    }
    if(ans == 1) {
        puts("1");
        return ;
   }
    bool flag = true;
    while(dp[pp] != 1) {
        if(fg[pp]) {
            flag = false;
            break;
        } else {
            pp = pre[pp];
        }
    }
    if(!flag) {
        printf("%d\n",ans);
    } else {
        printf("%d\n",ans-1);
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        srep(i,n) scanf("%d",&da[i]);
        dodp();
    }
	return 0;
}

