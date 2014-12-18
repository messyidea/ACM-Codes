/***********************************************\
 |Author: YMC
 |Created Time: 2014-8-13 12:35:22
 |File Name: 10.cpp
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
#define maxn 500005
ll ans[maxn];
ll val[maxn];
int n;
void solve(){
    /*for(ll i=1;i*i<=t;++i){
         if(t % i == 0){
            sum += t/i*(1 + t/i)*t/i/2*i;
            if(i*i != t){
                ll tt = t/i;
                sum += t/tt*(1 + t/tt)*t/tt/2*tt;
            }
         }
    }*/
    /*for(ll i = 1; i<=500000;++i){
        for(ll j = 1;j<=i; ++j){
            if(i % j == 0){

            }
        }
    }*/
    for(ll i = 1; i<= 500000; ++i){     //好想法！
        for(ll j=i;j<= 500000;j+=i){
            val[j] += (j/i + 1)*(j/i)/2;
        }
    }
}
void pre(){
    memset(val,0,sizeof(val));
    solve();
    ll mod = 1;
    mod <<= 32;
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<=500000;++i) {
        ans[i] = ans[i-1] + val[i]*i;
        ans[i] %= mod;
    }
}
int main() {
	//freopen("1010.in","r",stdin); 
    int T,cas = 1;
    pre();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case #%d: %I64d\n",cas ++,ans[n]);
    }    
	return 0;
}

