/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-30 12:25:19
 |File Name: Farm.cpp
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
const ll mod = 1000000007;
using namespace std;
ll n;
ll da[1000005];
int tot;
ll cal(ll n) {
    ll ret = 0;
    for(int i=1;i*i<=n;++i) {
        if(n%i == 0) {
            if(i*i == n) {
                ret += i;
                continue;
            }
            ret += i;
            ret += n / i;
        }
    }
    return ret;
}
void solve(ll n) {
    ll sum = 0;
    tot = 0;
    for(ll i=1;i*i<=n;++i) {
        if(n % i == 0) {
            if(i * i == n) {
                da[tot ++] = i;
                continue;
            }
            da[tot ++] = i;
            da[tot ++] = n/i;
        }
    }
    sort(da,da + tot);
    rep(i,tot) {
        sum += cal(da[i]);
        sum %= mod;
    }
    /*ll now = 0;
    rep(i,tot) {
        now += da[i];
        sum += now;
        sum %= mod;
        now %= mod;
    }*/
    printf("%lld\n",sum);
    //cout<<sum<<endl;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    //cin>>T;
    while(T--) {
        scanf("%lld",&n);
        //cin>>n;
        solve(n);
    }
	return 0;
}

