/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/1 19:09:52
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
int n;
#define mod 1000000007ll
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    ll ans;
    ll t;
    scanf("%d",&T);
    while(T--) {
        ans = 0;
        scanf("%d",&n);
        ll tt = n;
        for(int i=1;i<=n;++i) {
            scanf("%lld",&t);
            ans += t * i % mod * (tt--) % mod;
            ans %= mod;
        }
        printf("%I64d\n",ans);
    }
	return 0;
}

