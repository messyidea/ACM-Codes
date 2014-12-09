/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/15 19:44:55
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
#define mod 1000000007
int n;
char s[1005];
ll zz[1005];
int an[1005][1005][2];
ll bn[1005][1005][2];
int len;
ll ans;
ll mod_pow(ll x,ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
pair<int,ll> solve(int i,int k,bool f) {
    //cout<<i<<" "<<k<<endl;
    if(k == 0) {
        return MP(1,0);
    }
    if(i >= len) return MP(0,0);
    if(an[i][k][f] != -1) {
        ans += bn[i][k][f];
        return MP(an[i][k][f],bn[i][k][f]);
    }
    if(f) {
        pair<int,ll> c1,c2;
        c1 = solve(i+1,k-1,f);
        c2 = solve(i+1,k,f);
        an[i+1][k][f]=c2.first%mod;
        an[i+1][k-1][f] = c1.first%mod;
        bn[i+1][k][f] = c2.second%mod;
        bn[i+1][k-1][f] = c1.second%mod;
        ll tt = c1.first * zz[len-i-1];
        ans += tt;
        c1.second += tt;
        c1.second %= mod;
        ans %= mod;
        return MP(c1.first + c2.first,c2.second + c1.second);
    } else {
        if(s[i] == '1') {
            pair<int,ll> c1,c2;
            c1 = solve(i+1,k-1,f);
            c2 = solve(i+1,k,true);
            an[i+1][k-1][f] = c1.first%mod;
            an[i+1][k][1] = c2.first%mod;
            bn[i+1][k-1][f] = c1.second%mod;
            bn[i+1][k][1] = c2.second%mod;
            ll tt = c1.first%mod * zz[len-i-1]%mod;
            //ans += c1 * zz[len-i-1];
            ans += tt;
            ans %= mod;
            c1.second += tt;
            c1.second %= mod;
            return MP(c1.first + c2.first,c2.second + c1.second);
        } else {
            pair<int,ll> c1,c2;
            c2 = solve(i+1,k,f);
            an[i+1][k][f] = c2.first%mod;
            bn[i+1][k][f] = c2.second%mod;
            return MP(c2.first,c2.second);
        }
    }

}
int main() {
	//freopen("input.txt","r",stdin); 
    zz[0] = 1;
    for(int i=1;i<=1001;++i) {
        zz[i] = zz[i-1] * 2;
        zz[i] %= mod;
    } 
    while(~scanf("%d %s",&n,s)) {
        memset(an,-1,sizeof(an));
        memset(bn,-1,sizeof(bn));
        ans = 0;
        len = strlen(s);
        solve(0,n,false);
        int nu = 0;
        for(int i=0;i<len;++i) {
            if(s[i] == '1') nu ++;
        }
        if(nu == n) {
            for(int i=0;i<n;++i) {
                if(s[i] == '1') ans -= zz[len-i-1];
            }
        }
        printf("%I64d\n",ans);
    }
	return 0;
}

