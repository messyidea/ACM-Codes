
/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-23 14:12:34
 |File Name: e.cpp
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
const ll mod = 10000000000007ll;
int l,m,n;
ll A[10005];
ll ppow(ll x,ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res % mod) * (x % mod) % mod;
        x = (x % mod) * x % mod;
        n >>= 1;
    }
    return res;
}
ll extgcd(ll a,ll b,ll& x,ll& y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b,a%b,y,x);
        y -= (a/b) *x;
    } else {
        x = 1;y = 0;
    }
    return d;
}
ll mod_inverse(ll a,ll m) {
    ll x,y;
    extgcd(a,m,x,y);
    return (m + x % m) % m;
}
ll cal(ll n,ll m) {
    if(m == -1 || m == 0) return 1;
    ll ans = A[n];
    ans *= mod_inverse(A[m],mod);
    //ans *= ppow(A[m],mod - 2);
    ans %= mod;
    ans *= mod_inverse(A[n-m],mod);
    //ans *= ppow(A[n-m],mod-2);
    ans %= mod;
    ans *= A[m];
    ans %= mod;
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    A[1] = 1;
    for(int i=2;i<=10005;++i) {
        A[i] = A[i-1] * i % mod;
    }
    int cnt = 1;
    while(T--) {
        scanf("%d %d %d",&l,&m,&n);
        l = l * l;
        ll sum = 0;
        ll tp = 1;
        int tt = m - 1;
        while(tt --) {
            tp *= l;
            tp %= mod;
            l --;
        }
        tt = n - m + 1;
        while(tt --) {
            tp *= l;
            tp %= mod;
            //cout<<tp<<endl;
            l --;
            sum += tp;
            sum %= mod;
        }
        //cout<<sum<<endl;
        printf("Case %d: %lld\n",cnt ++,sum);
    }

	return 0;
}
