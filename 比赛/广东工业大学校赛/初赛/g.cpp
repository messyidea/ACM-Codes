/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/14 14:37:41
 |File Name: gg.cpp
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
#define mod 1000000007
using namespace std;
int n;
int fib[1000006];
void init() {
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2;i<=1000001;++i) {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= mod;
    }
}
void solve(int n) {
    ll sum = 1;
    rep(i,n) {
        sum *= 2;
        sum %= mod;
    }
    sum -= fib[n+1];
    sum = (sum % mod + mod) % mod; 
    //printf("%lld\n",sum);
    cout<<sum<<endl;
}
int main() {
	//freopen("input.txt","r",stdin); 
    init();
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        solve(n);
    }
	return 0;
}

