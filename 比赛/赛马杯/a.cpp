/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/2 12:36:57
 |File Name: a.cpp
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
ll n,l1,r1,a,b,c,d;
ll aa,bb,cc,dd;
ll mod = 4294967296ll;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d",&n,&l1,&r1,&a,&b,&c,&d);
        if(l1 < r1) {
            aa = r1;
            dd = l1;
        } else {
            aa = l1;
            dd = r1;
        }
        
        ll lnow = l1, rnow = r1;
        ll tlnow = l1, trnow = r1;
        ll llnow,rrnow;
        for(int i=1;i<n;++i) {
            lnow = lnow * a + b ;
            lnow %= mod;
            rnow = rnow * c + d;
            rnow %= mod;
            llnow = lnow; rrnow = rnow;
            if(llnow > rrnow) swap(llnow,rrnow);
            if(llnow > dd) dd = llnow;
            if(rrnow < aa) aa = rrnow;
        }
        if(aa >= dd) {
            puts("NO");
            continue;
        }
        bool fg = false;
        for(int i=1;i<n;++i) {
            tlnow = tlnow * a + b;
            tlnow %= mod;
            trnow = trnow * c + d;
            trnow %= mod;
            llnow = tlnow, rrnow = trnow;
            if(llnow > rrnow) swap(llnow,rrnow);
            if(llnow > aa && rrnow < dd) {
                fg = true;
                break;
            }
        }
        if(fg) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
	return 0;
}

