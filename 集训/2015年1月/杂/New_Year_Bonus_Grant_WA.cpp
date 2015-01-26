/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-26 16:39:11
 |File Name: New_Year_Bonus_Grant.cpp
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
int n;
int da[500005];
vector <int> g[500005];
int sum;
int que[500005];
int tot;
void dfs(int now,int fa,int flag) {
    if(flag == false) {
    int p = -1; int minn = inf;
    for(int i=0;i<g[now].size();++i) {
        int u = g[now][i];
        int l = g[u].size();
        if(l < minn) {
            minn = l;
            p = u;
        }
    }
    for(int i=0;i<g[now].size();++i) {
        int u = g[now][i];
        if(u == p) {
            que[tot ++] = u;
            dfs(u,now,true);
        } else {
            dfs(u,now,false);
        }
    } } else {
        for(int i=0;i<g[now].size();++i) {
            int u = g[now][i];
            dfs(u,now,false);
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--) {
        scanf("%d",&n);
        if(cas ++ != 0) puts("");
        for(int i=1;i<=n;++i) g[i].clear();
        int tp;
        for(int i=2;i<=n;++i) {
            scanf("%d",&tp);
            g[tp].push_back(i);
        }
        sum = 0;
        tot = 0;
        dfs(1,-1,false);
        printf("%d\n",tot*1000);
        sort(que,que + tot);
        printf("%d",que[0]);
        for(int i=1;i<tot;++i) printf(" %d",que[i]);
        puts("");
    }

	return 0;
}

