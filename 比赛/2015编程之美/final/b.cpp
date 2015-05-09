/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/9 14:57:59
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
int da[1005];
int n,q,a,b,c;
int solve(int a,int b,int c) {
    int ans = inf;
    for(int i=a;i<=b;++i) {
        ans = min(ans,abs(c-da[i]));
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&q);
        srep(i,n) scanf("%d",&da[i]);
        printf("Case #%d:\n",cas ++);
        rep(i,q) {
            scanf("%d %d %d",&a,&b,&c);
            printf("%d\n",solve(a,b,c));
        }
    }
	return 0;
}

