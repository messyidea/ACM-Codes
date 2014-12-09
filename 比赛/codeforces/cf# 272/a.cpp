/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/13 14:25:10
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
ll a,b;
ll t;
#define mod 1000000007ll
ll mod_pow(ll x,ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
/*ll cal(ll u) {
    ll tp = a;
    ll tt = a * u;
    tt %= mod;
    ll ha = 0;
    ll num;
    if(a % 2 == 0){
        ha = a / 2;
        ha %= mod;
        num = (u + tt) % mod;
        num *= ha;
        num %= mod;
    } else {
        num = ((u + tt )/2) % mod;
        num *= a;
        num %= mod;
    }
    ll res = 0;
    res += num * b;
    res %= mod;
    res += u * a % mod;
    res %= mod;
    return res;
}*/
int main() {
	//freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout); 
    cin>>a>>b;
    ll res = 0;
    ll t1;ll t2;
    for(ll i=1;i <= a;++i) {
        t1 = (b-1)*b /2;
        t1 %= mod;
        t2 = b * i + 1;
        t2 %= mod;
        res += t1*t2;
        res %= mod; 
    }
    cout<<res<<endl;
	return 0;
}

