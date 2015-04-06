
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-6 11:55:39
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
#define srep(i,n) for(int int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int da[405];
int n,m;
void solve() {
    for(int i=n;i<n*2;++i) da[i] = da[i-n];
    n = n * 2;
    int maxx = -inf;
    int now = 0;
    for(int i=0;i<m;++i) {
        now += da[i];
    }
    maxx = max(now,maxx);
    for(int i=m;i<n;++i) {
        now += da[i];
        now -= da[i-m];
        maxx = max(now,maxx);
    }
    printf("%d\n",maxx);
} 
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        rep(i,n) scanf("%d",&da[i]);
        solve();
    }
	return 0;
}
