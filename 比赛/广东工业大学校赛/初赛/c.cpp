/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/14 13:18:31
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
int da[1005];
void init() {
    da[1] = 1;
    for(int i=2;i<=1000;++i) {
        da[i] = da[i-1] + i-1;
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    init();
    int T,a;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&a);
        printf("%d\n",da[a]);
    }
	return 0;
}

