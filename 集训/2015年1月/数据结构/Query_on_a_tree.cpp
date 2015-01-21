/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-21 13:35:40
 |File Name: Query_on_a_tree.cpp
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
const int maxn = 20010;
vector <int> ma[maxn];
int pathid[maxn],pathtop[maxn],dep[maxn];
int que[maxn],s,t,fa[maxn],size[maxn],son[maxn],tot;
int fq[maxn];
int an[maxn];
int n,m,u,v,cnt,l;
int tp;
inline void add_edge(int a,int b){
    ma[a].push_back(b);ma[b].push_back(a);
}
void buildpath() {
    int u,v;
    s = 0;t = 0;
    que[t ++] = 1;
    fa[1] = -1;dep[1] = 1;
    //cal the depth and fa
    while(s < t) {
        u = que[s ++];
        rep(i,ma[u].size()) {
            v = ma[u][i];
            if(v != fa[u]) {
                fa[v] = u; dep[v] = dep[u] + 1; que[t ++] = v;
            }
        }
    }
    //cal the size
    for(int j = n-1;j >= 0;--j) {
        u = que[j];
        son[u] = -1; size[u] = 1;
        rep(i,ma[u].size()) {
            v = ma[u][i];
            if(v != fa[u]) {
                size[u] += size[v];
                if(son[u] == -1 || size[v] > size[son[u]]) son[u] = v;
            }
        }
        if(son[u] == -1) son[u] = u;
    }
    //cal the top
    memset(pathtop,-1,sizeof(pathtop));
    cnt = 1;
    for(int i = 0;i<n;++i) {
        u = que[i];
        if(pathtop[u] != -1) continue;
        int top = u;
        for(;;) {
            pathtop[u] = top;
            pathid[u] = cnt ++;
            fq[pathid[u]] = u;
            if(son[u] == u) break;
            u = son[u];
        }
    }
}
struct Path{
    int u,v,l;
}path[maxn];
int to;
struct Tree{
    int l,r,m;
}tree[maxn<<2];
inline void pushup(int rt) {
    tree[rt].m = max(tree[L(rt)].m,tree[R(rt)].m);
}
void build(int l,int r,int rt) {
    tree[rt].l = l;tree[rt].r = r;
    if(l == r) {
        tree[rt].m = an[l];
        return ;
    }
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid + 1, r, R(rt));
    pushup(rt);
}
char op[15];
void update(int l,int v,int rt) {
    if(l == tree[rt].l && l == tree[rt].r) {
        tree[rt].m = v;
        return ;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= l) update(l,v,L(rt));
    else update(l,v,R(rt));
    pushup(rt);
} 
int query(int l,int r,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].m;
    }
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) return query(l,r,L(rt));
    else if(l >= mid + 1) return query(l,r,R(rt));
    else {
        int ans = query(l,mid,L(rt));
        ans = max(ans,query(mid+1,r,R(rt)));
        return  ans;
    }
}
int solve(int u,int v) {
    if(u == v) return 0;
    int f1 = pathtop[u],f2 = pathtop[v];
    int ret = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        ret = max(ret,query(pathid[f1],pathid[u],1));
        u = fa[f1];
        f1 = pathtop[u];
    }
    if(u == v) return ret;
    if(dep[u] > dep[v]) swap(u,v);
    int s = son[u];
    ret = max(ret,query(pathid[s],pathid[v],1));
    return ret;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<=n; ++i) ma[i].clear();
        to = 0;
        for(int i=1;i<n;++i) {
            scanf("%d %d %d",&u,&v,&l);
            add_edge(u,v);
            path[to].u = u;path[to].v = v;path[to++].l = l;
        }
        buildpath();
        for(int i=0;i<to;++i) {
            u = path[i].u; v = path[i].v; l = path[i].l;
            if(dep[u] > dep[v]) an[pathid[u]] = l;
            else an[pathid[v]] = l;
        }
        build(1,cnt,1);
        while(true) {
            scanf("%s",op);
            if(op[0] == 'Q') {
                scanf("%d %d",&u,&v);
                printf("%d\n",solve(u,v));
            } else if(op[0] == 'C') {
                scanf("%d %d",&u,&v);
                u --;
                int ua,ub;
                ua = path[u].u; ub = path[u].v; 
                int id;
                if(dep[ua] > dep[ub])  id = pathid[ua];
                else id = pathid[ub];
                update(id,v,1);
            } else break;
        }
        
    }
	return 0;
}

