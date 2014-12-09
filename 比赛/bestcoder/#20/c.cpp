/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/29 19:25:07
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
int T;
int n,m;
int a,b;
int tk;
int da[1005][2];
int dp[1005][1005][2];
int kk[1005];
void solve() {
    int maxn = 0;
    //memset(dp,0,sizeof(dp));
    int maxk = 1;
    for(int i=1;i<=n;++i) {
        a = da[i][0]; b = da[i][1];
        kk[i] = 1;
        tk = 1;
        for(int k=0;k<=maxk + 1;++k) {
            dp[i][k][0] = 1;
            dp[i][k][1] = 1;
        }
        for(int j=i-1;j>=1;j--) {
            if(a > da[j][0]) {
                for(int k=0;k<=kk[j] && k<=m;++k) {
                    int tp = dp[i][k][0];
                    dp[i][k][0] = max(dp[i][k][0],dp[j][k][0]+1);
                    if(dp[i][k][0] > maxn) maxn = dp[i][k][0];
                    if(dp[i][k][0] > tp) {
                        tk = max(tk,k);
                    }
                }
            }
            if(a > da[j][1]) {
                for(int k=1;k<=kk[j]&& k<=m;++k) {
                    int tp = dp[i][k][0];
                    dp[i][k][0] = max(dp[i][k][0],dp[j][k][1]+1);
                    if(dp[i][k][0] > maxn) maxn = dp[i][k][0];
                    if(dp[i][k][0] > tp) {
                        tk = max(k,tk);
                    }
                }
            }
            if(b > da[j][0]) {
                for(int k=0;k<=kk[j]&& k<=m;++k) {
                    int tp = dp[i][k+1][1];
                    dp[i][k+1][1] = max(dp[i][k+1][1],dp[j][k][0]+1);
                    if(dp[i][k+1][1] > maxn) maxn = dp[i][k+1][1];
                    if(dp[i][k+1][1] > tp) {
                        tk = max(k,tk);
                    }
                }
            }
            if(b > da[j][1]) {
                for(int k=1;k<=kk[j]&& k<=m;++k) {
                    int tp = dp[i][k+1][1];
                    dp[i][k+1][1] = max(dp[i][k+1][1],dp[j][k][1]+1);
                    if(dp[i][k+1][1] > maxn) maxn = dp[i][k+1][1];
                    if(dp[i][k+1][1] > tp) {
                        tk = max(k,tk);
                    }
                }
            }
            //kk[i] = tk + 1;
        }
        kk[i] = tk + 1;
        maxk = max(kk[i]+1,maxk);
    }
    printf("%d\n",maxn);
}

//适用于正负整数
template <class T>
inline bool scan_d(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}


int main() {
	//freopen("input.txt","r",stdin); 
    //scanf("%d",&T);
    scan_d(T);
    while(T--) {
        //scanf("%d %d",&n,&m);
        scan_d(n);scan_d(m);
        srep(i,n) {
            //scanf("%d %d",&da[i][0],&da[i][1]);
            scan_d(da[i][0]);
            scan_d(da[i][1]);
            //cout<<da[i][0]<<"  "<<da[i][1]<<endl;
        }
        solve();
    }
	return 0;
}

