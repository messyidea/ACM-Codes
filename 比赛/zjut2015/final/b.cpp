/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/24 20:19:32
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
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n;
int Ci[25],Hi[25];
int get(int c,int h) {
    if(h * h + h >= c) return c - h;
    int p = sqrt(c) ;
    if(p * p + p >= c) p --;
    if(p * p + p >= c) p --;
    return get(p,h);
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)) {
        rep(i,n) {
            scanf("%d %d",&Ci[i],&Hi[i]);
        }
        int ans = get(Ci[0],Hi[0]);
        for(int i=1;i<n;++i) {
            ans = ans ^ (get(Ci[i],Hi[i]));
        }
        if(ans) puts("YES");
        else puts("NO");
    }
	return 0;
}

