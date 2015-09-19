/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/19 20:05:36
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
int n;
int da[105];
int now;
int now2;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)) {
        rep(i,n) scanf("%d", &da[i]);
        now = -inf;
        for(int i = 1; i < n; ++i) {
            now = max(now, da[i] - da[i-1]);
        }
        now2 = inf;
        for(int i = 2; i < n; ++i) {
            now2 = min(now2, da[i] - da[i-2]);
        }
        printf("%d\n", max(now, now2));

    }
	return 0;
}

