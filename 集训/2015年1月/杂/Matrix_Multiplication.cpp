/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-26 15:48:40
 |File Name: Matrix_Multiplication.cpp
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int a,b,n,m;
int da[100010];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int cas = 0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        if(cas ++ != 0) puts("");
        memset(da,0,sizeof(da));
        rep(i,m) {
            scanf("%d %d",&a,&b);
            da[a] ++; da[b] ++;
        }
        ll sum = 0;
        for(int i=1;i<=n;++i) sum += (long long)da[i]*(long long)da[i];
        printf("%lld\n",sum);
    }
	return 0;
}

