/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/3 12:00:18
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
set<pair<int,int> > se;
int n;
int a,x,y;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n) && n) {
        se.clear();
        while(n --) {
            scanf("%d %d %d",&a,&x,&y);
            if(a == -1) {
                se.erase(make_pair(x,y));
            } else if(a == 1) {
                se.insert(make_pair(x,y));
            } else {
                set<pair<int,int> >::iterator it = se.begin();
                int maxn = -1;
                for(;it != se.end();it ++) {
                    int tp = it->first * x + it->second * y;
                    if(tp > maxn) maxn = tp;
                }
                printf("%d\n",maxn);
            }
        }
    }
	return 0;
}

