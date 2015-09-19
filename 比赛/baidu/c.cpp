/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/17 20:07:40
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
int dp[200005][16];
int ga[200005];
int n, m;
int tt;
int aa[2],bb[2];
inline int toget(int a,int b,int c) {
    aa[0] = a / 4;
    aa[1] = a % 4;
    bb[0] = b / 4;
    bb[1] = b % 4;
    int count = 0;
    if((abs(aa[0] - bb[0]) <= 1 && abs(aa[1] - bb[1]) <= 1) || (abs(aa[0] - bb[1]) <= 1 && abs(aa[1] - bb[0]) <= 1)) {
        count = 0;
        if((c & (1 << bb[0])) > 0) count ++;
        if((c & (1 << bb[1])) > 0) count ++;
        if(bb[0] == bb[1] && count > 0) count --;
        return count;
    } else return count;
}
int main() {
	//freopen("input.txt","r",stdin); 
	//freopen("out.txt","w",stdout); 
    while(~scanf("%d", &n)) {
        tt = 0;
        memset(ga, 0, sizeof(ga));
        int a, b;
        rep(i,n) {
            scanf("%d %d",&a,&b);
            if(a >= tt) tt = a;
            ga[a] |= 1 << (b-1);
        }
        for(int i=0;i<16;++i) {
            dp[0][i] = 0;
        }
        for(int ii=1; ii <= tt; ++ii) {
            for(int jj=0;jj < 16;++jj) {
                dp[ii][jj] = 0;
                for(int kk=0;kk < 16; ++kk) {
                    int ppp = dp[ii-1][kk];
                    int qqq = toget(kk,jj,ga[ii]);
                    if(ppp + qqq > dp[ii][jj]) dp[ii][jj] = ppp + qqq;
                }
            }
        }
        int ans = -inf;
        for(int i=0;i<16;++i) ans = max(ans,dp[tt][i]);
        printf("%d\n",ans);
        
    }
	return 0;
}

