/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/11 19:22:51
 |File Name: b.cpp
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
#define mp make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;
using namespace std;
pair <char,int> pa[100005];
int pos[100];
int tot;
int T,n,m,b;
char a[10];
ll mod_pow(ll x,ll n,ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
void solve(int u) {
    int p = pa[u].second;
    int pp = 0;
    for(int i = u-1; i >= 0 ;--i) {
        char tt = pa[i].first;
        if(tt == 'Q') continue;
        int t = pa[i].second;
        if(t == 3) {
            pp ++;continue;
        } 
        if(t == 2) {
            p = n - p + 1;
            continue;
        }
        if(t == 1) {
            int tp = (n + 1)/2;
            if(p <= tp) p = p * 2 - 1;
            else {
                p -= tp;
                p *= 2;
                //p = p * 2 - n - n % 2;
            }
        }
    }
    //ll ans = mod_pow(p , mod_pow(2,pp,1000000007ll) , 1000000007ll); //wrong
    ll ans = mod_pow(p , mod_pow(2,pp,1000000007ll-1) , 1000000007ll);  //right
    cout<<ans<<endl;
}
int main() {
    //freopen("input.txt","r",stdin); 
    scanf("%d",&T);
    while(T--) {
        tot = 0;
        scanf("%d %d",&n,&m);
        rep(i,m) {
            scanf("%s %d",&a,&b);
            pa[i] = mp(a[0],b);
            if(a[0] == 'Q')  pos[tot ++] = i;
        }
        for(int i = 0;i<tot;++i) {
            solve(pos[i]);
        }
    }
	return 0;
}

