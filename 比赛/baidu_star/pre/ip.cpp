/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/23 14:12:25
 |File Name: ip.cpp
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
int da[1005][4];
int db[4];
int n,m;
int cas = 1;
map<ll,int> ma;
inline void solve() {
    int count = 0;
    ma.clear();
    rep(i,n) {
        ll now = 0;
        ll a = da[i][0] & db[0];
        ll b = da[i][1] & db[1];
        ll c = da[i][2] & db[2];
        ll d = da[i][3] & db[3];
        now = a * 256 + b;
        now = now * 256 + c;
        now = now * 256 + d;
        if(ma[now] == 0) {
            ma[now] = 1;
            count ++;
        }
    }
    printf("%d\n",count);
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        printf("Case #%d:\n",cas ++);
        rep(i,n) {
            scanf("%d.%d.%d.%d",&da[i][0],&da[i][1],&da[i][2],&da[i][3]);
        }
        rep(i,m) {
            scanf("%d.%d.%d.%d",&db[0],&db[1],&db[2],&db[3]);
            solve();
        }

    }
	return 0;
}

