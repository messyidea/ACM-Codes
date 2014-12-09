/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/15 21:57:12
 |File Name: poj3728.cpp
 |Description:神奇的lca 
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

using namespace std;
#define maxn 50005
struct edge{
    int v,id;
};
int n,m;
int mx[maxn],mi[maxn],down[maxn],up[maxn];
bool vis[maxn];
int ans[maxn];
int fa[maxn];
vector <int> G[maxn];
vector <edge> H[maxn];
vector <int> I[maxn];
int uu[maxn],vv[maxn];
void add_edge(int u,int v,int id){
    edge e;e.v = v;e.id = id;
    H[u].push_back(e);
}
int find(int u){
    if(fa[u] == u) return u;
    int f = fa[u];
    fa[u] = find(fa[u]);
    up[u] = max(mx[f] - mi[u], max(up[u], up[f]));  
    down[u] = max(mx[u] - mi[f], max(down[u], down[f]));  
    mx[u] = max(mx[u], mx[f]);  
    mi[u] = min(mi[u], mi[f]); 
    return fa[u];
}
void tarjan(int u){
    vis[u] = true;
    fa[u] = u;
    for(int i=0;i<H[u].size();++i){
        edge e = H[u][i];
        if(vis[e.v]){
            int f = find(e.v);
            I[f].push_back(e.id);
        }
    }
    for(int i=0;i<G[u].size();++i){
        int v = G[u][i];
        if(!vis[v]){
            tarjan(v);
            fa[v] = u;
        }
    }
    for(int i=0;i<I[u].size();++i){
        int id = I[u][i];
        int s = uu[id],t = vv[id];
        find(s);find(t);
        ans[id] = max(up[s],down[t]);
        ans[id] = max(ans[id],mx[t] - mi[s]);
    }
}
int u,v;
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;++i){
            G[i].clear();H[i].clear();I[i].clear();
        }
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;++i){
            scanf("%d",&mx[i]);
            mi[i] = mx[i];
        }
        for(int i=1;i<n;++i){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;++i){
            scanf("%d%d",&uu[i],&vv[i]);
            add_edge(uu[i],vv[i],i);
            add_edge(vv[i],uu[i],i);
        }
        tarjan(1);
        for(int i=1;i<=m;++i) cout<<ans[i]<<endl;

    }
	return 0;
}

