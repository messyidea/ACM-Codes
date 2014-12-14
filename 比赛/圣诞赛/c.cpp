/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 12:24:09
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
int a,b,c;
int aa[1005];
int bb[1005];
int cc[1005];
map<int,int> ma;
map<int,int> mb;
map<int,int> mc;
set<int> sa;
set<int> sb;
int main() {

	freopen("input.txt","r",stdin); 
    while(scanf("%d %d %d",&a,&b,&c)!=EOF) {
        ma.clear();
        mb.clear();
        mc.clear();
        sa.clear();
        sb.clear();
        rep(i,a) {
            scanf("%d",&aa[i]);
            ma[aa[i]] ++;
            sa.insert(aa[i]);
        }
        rep(i,b) {
            scanf("%d",&bb[i]);
            mb[bb[i]] ++;
            sb.insert(bb[i]);
        }
        rep(i,c) {
            scanf("%d",&cc[i]);
            mc[cc[i]] ++;
        }
        int ans = 0;
        set<int>::iterator it1 = sa.begin();
        set<int>::iterator it2 = sb.begin();
        for(;it1 != sa.end();it1 ++) {
            it2 = sb.begin();
            for(;it2 != sb.end();it2 ++) {
                int tt = *it1 + *it2;
                ans += mc[tt] * ma[*it1] * mb[*it2];
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

