/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/13 19:03:44
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
ll a;
int da[100];
int tot;
void solve(ll a) {
    tot = 0;
    while(a > 0) {
        da[tot ++] = a % 2;
        a /= 2;
    }
    int t2 = 0;
    while(t2 < tot && da[t2] == 0) t2 ++;
    ll ans = 0;
    for(int i=t2;i<tot;++i) {
        ans *= 2;
        ans += da[i];
    } 
    printf("%I64d\n",ans);
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%I64d",&a);
        solve(a);
    }
	return 0;
}

