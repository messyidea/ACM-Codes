/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/23 18:08:30
 |File Name: d.cpp
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
ll a1,b1,a2,b2;
ll aa1,bb1,aa2,bb2;
int dp[50][50][50][50];
int dd[50][50][50][50];
int solve(ll a1,ll b1,ll a2,ll b2,int a,int b,int c,int d) {
    if(dp[a][b][c][d] != -1) {
        return dp[a][b][c][d];
    }
    ll tt1,tt2;
    tt1 = a1 * b1;
    tt2 = a2 * b2;
    if(tt1 == tt2) {
        dp[a][b][c][d] = 0;
        dd[a][b][c][d] = 0;
        return 0;
    }
    //dp[0][0][0][0] = inf;
    int &ans = dp[a][b][c][d];
    ans = inf;
    int tp;
    if(tt1 > tt2) {
        if(a1 % 2 == 0) {
            tp = ans;
            ans = min(solve(a1/2,b1,a2,b2,a+1,b,c,d) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 1;
            }
        } 
        if(b1 % 2 == 0) {
            tp = ans;
            ans = min(solve(a1,b1/2,a2,b2,a+1,b,c,d) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 2;
            }
        }
        if(a1 % 3 == 0) {
            tp = ans;
            ans = min(solve(a1/3*2,b1,a2,b2,a,b+1,c,d) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 3;
            }
        }
        if(b1 % 3 == 0) {
            tp = ans;
            ans = min(solve(a1,b1/3*2,a2,b2,a,b+1,c,d) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 4;
            }
        }
    } else {
        if(a2 % 2 == 0) {
            tp = ans;
            ans = min(solve(a1,b1,a2/2,b2,a,b,c+1,d) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 5;
            }
        } 
        if(b2 % 2 == 0) {
            tp = ans;
            ans = min(solve(a1,b1,a2,b2/2,a,b,c+1,d) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 6;
            }
        }
        if(a2 % 3 == 0) {
            tp = ans;
            ans = min(solve(a1,b1,a2/3*2,b2,a,b,c,d+1) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 7;
            }
        }
        if(b2 % 3 == 0) {
            tp = ans;
            ans = min(solve(a1,b1,a2,b2/3*2,a,b,c,d+1) + 1,ans);
            if(ans != tp) {
                dd[a][b][c][d] = 8;
            }
        }
    }
    return ans;
}
void get(int a,int b,int c,int d) {
    int tt = dd[a][b][c][d];
    if(tt == 0) return ;
    if(tt == 1) {
        a1 /= 2;
        get(a + 1,b,c,d);
    } 
    if(tt == 2) {
        b1 /= 2;
        get(a + 1,b,c,d);
    } 
    if(tt == 3) {
        a1 /= 3;
        a1 *= 2;
        get(a,b+1,c,d);
    } 
    if(tt == 4) {
        b1 /= 3;
        b1 *= 2;
        get(a,b+1,c,d);
    } 
    if(tt == 5) {
        a2 /= 2;
        get(a,b,c+1,d);
    } 
    if(tt == 6) {
        b2 /= 2;
        get(a,b,c+1,d);
    } 
    if(tt == 7) {
        a2 /= 3;
        a2 *= 2;
        get(a,b,c,d+1);
    } 
    if(tt == 8) {
        b2 /= 3;
        b2 *= 2;
        get(a,b,c,d+1);
    } 

}
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%I64d %I64d",&a1,&b1);
    scanf("%I64d %I64d",&a2,&b2);
    memset(dp,-1,sizeof(dp));
    int ans = solve(a1,b1,a2,b2,0,0,0,0);
    if(ans >= inf) ans = -1;
    //solve(a1,b1,a2,b2,0,0,0,0);
    if(ans == -1) {
        puts("-1");
    } else {
        printf("%d\n",ans);
        get(0,0,0,0);
        printf("%I64d %I64d\n",a1,b1);
        printf("%I64d %I64d\n",a2,b2);
    }
	return 0;
}

