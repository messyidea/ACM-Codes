
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-12 13:48:53
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
#define srep(i,n) for(int int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int a1,h1,a2,h2,a,b,c,n,m;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d %d",&a1,&h1,&a2,&h2);
        if(a1 == 0) {
            puts("Invalid");
            continue;
        }
        h1 -= a2;
        h2 -= a1;
        bool fg1 = true,fg2 = true;
        if(h1 <= 0) fg1 = false;
        if(h2 <= 0) fg2 = false;
        if(fg1) {
            printf("%d %d ",a1,h1);
        } else {
            printf("Discard ");
        }
        if(fg2) {
            printf("%d %d\n",a2,h2);
        } else {
            puts("Discard");
        }
    }
	return 0;
}
