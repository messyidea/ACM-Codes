/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/19 19:37:13
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
pair<int,int> ppa[55];
pair<int,int> ppb[55];
int p, q, u, v;
int a, b;
bool check(int t) {
    int ta = 0, tb = 0;
    pair<int,int> mm = MP(-1, -1);
    while(ta < p && tb < q) {
        if(ppa[ta].first <= ppb[tb].first + t) {
            if(ppa[ta].first <= mm.second) return true;
            else mm = ppa[ta ++];
        } else {
            if(ppb[tb].first + t <= mm.second) return true;
            else {
                mm = ppb[tb ++];
                mm.second += t;
            }
        }
        //cout<<"-----------"<<mm.second<<endl;
    }
    if(ta < p) {
        if(ppa[ta].first <= mm.second) return true;
    }
    if(tb < q) {
        if(ppb[tb].first + t <= mm.second) return true;
    }
    return false;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d %d %d", &p, &q, &u, &v)) {
        for(int i = 0; i < p; ++i) {
            scanf("%d %d",&a, &b);
            ppa[i] = MP(a, b);
        }
        for(int i = 0; i < q; ++i) {
            scanf("%d %d",&a, &b);
            ppb[i] = MP(a, b);
        }
        int count = 0;
        for(int i = u; i <= v; ++i) {
            if( check(i) ) {
                count ++;
            }
        }
        printf("%d\n", count);
    }
	return 0;
}

