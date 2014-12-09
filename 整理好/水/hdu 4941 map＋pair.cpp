
/***********************************************\
 |Author: YMC
 |Created Time: 2014-8-12 3:55:17
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
map <int,int> r;
map <int,int> c;
map <pair<int,int>,int> ma;
int n,m,k;
int u,v,w;
int nn;

int main() {
    //freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        printf("Case #%d:\n",cas++);
        rep(i,k){
            scanf("%d%d%d",&u,&v,&w);
            u++;v++;
            r[u] = u;
            c[v] = v;
            ma[make_pair(u,v)] = w;
        }
        scanf("%d",&nn);
        while(nn -- ){
            scanf("%d%d%d",&w,&u,&v);
            u++;v++;
            if(w == 1){
                if(r[u] == 0||r[v] == 0) continue;
                int t = r[u];
                r[u] = r[v];
                r[v] = t;
            } else if(w == 2){
                if(c[u] == 0||c[v] == 0) continue;
                int t = c[u];
                c[u] = c[v];
                c[v] = t;
            } else {
                int xx = r[u];
                int yy = c[v];
                printf("%d\n",ma[make_pair(xx,yy)]);
            }
        }
    }
    return 0;
}
