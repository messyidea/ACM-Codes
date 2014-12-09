/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/23 17:12:30
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
int a[5005];
int b[5005];
int c[5005];
int t1,t2,t3;
int n;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)) {
        int tp;
        t1 = t2 = t3 = 0;
        rep(i,n) {
            scanf("%d",&tp);
            if(tp == 1) {
                a[t1 ++] = i+1;
            } else if(tp == 2) {
                b[t2++] = i+1;
            } else {
                c[t3 ++] = i+1;
            }
        }
        tp = min(t1,t2);
        tp = min(tp,t3);
        printf("%d\n",tp);
        for(int i=0;i<tp;++i) {
            printf("%d %d %d\n",a[i],b[i],c[i]);
        }

    }
	return 0;
}

