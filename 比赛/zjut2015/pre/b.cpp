/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 12:20:20
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
int da[100005];
int db[100005];
int k;
int main() {
	//freopen("input.txt","r",stdin); 
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF) {
        rep(i,n) {
            scanf("%d",&da[i]);
        }
        rep(i,m) {
            scanf("%d",&db[i]);
        }
        sort(da,da + n);
        sort(db,db + m);
        scanf("%d",&k);
        int t = 0;
        bool fg = false;
        for(int i=0;i<n;++i) {
            if(da[i] == db[t]) {
                t ++;
                continue;
            } else {
                if(da[i] < k) {
                    fg = true;
                } else {
                    fg = false;
                }
                break;
            }
        }
        if(fg) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
	return 0;
}

