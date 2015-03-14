/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/14 14:21:18
 |File Name: f.cpp
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
int n,m;
vector <int> ma[1005];
int fa[1005];
void dfs(int u,int f) {
    fa[u] = f;
    int len = ma[u].size();
    for(int i=0;i<len;++i) {
        int v = ma[u][i];
        if(v != f)
            dfs(v,u);
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int a,b;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;++i) ma[i].clear();
        rep(i,n-1) {
            scanf("%d %d",&a,&b);
            ma[a].push_back(b);
            ma[b].push_back(a);
        }
        dfs(m,-1);
        printf("%d",fa[1]);
        for(int i=2;i<=n;++i) printf(" %d",fa[i]);
        puts("");
    }
	return 0;
}

