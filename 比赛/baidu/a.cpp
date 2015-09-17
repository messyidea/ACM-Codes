/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/17 19:34:31
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
ll l,r,t,d,t1,t2,m;
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    while(~scanf("%d",&n)) {
        if(n == 0) {
            puts("0");
            continue;
        }

        l = inf; t = inf;
        r = -inf; d = -inf;
        while(n --) {
            scanf("%I64d %I64d", &t1, &t2);
            if(l > t1) l = t1;
            if(r < t1) r = t1;
            if(t > t2) t = t2;
            if(d < t2) d = t2;
        }
        m = max(r - l, d - t);
        printf("%I64d\n", m * m);
    }
	return 0;
}

