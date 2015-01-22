/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-21 13:35:40
 |File Name: Query_on_a_tree.cpp
 |Description: 
\***********************************************/
#pragma comment(linker,"/STACK:100000000,100000000")
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
const int maxn = 50010;
vector <int> ma[maxn];
int pathid[maxn],pathtop[maxn],dep[maxn];
int que[maxn],s,t,fa[maxn],size[maxn],son[maxn],tot;
int an[maxn],bn[maxn];
int fq[maxn];
int n,m,u,v,cnt,l,q;
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
            fq[cnt-1] = u;
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
    int l,r,m,add;
}tree[maxn<<2];
void build(int l,int r,int rt) {
    tree[rt].l = l;tree[rt].r = r;
    tree[rt].add = 0;
    if(l == r) {
        tree[rt].m = an[fq[l]];
        return ;
    }
    int mid = l + r >> 1;
    build(l,mid,L(rt));
    build(mid + 1, r, R(rt));
    //pushup(rt);
}
char op[15];
void pushdown(int rt) {
    if(tree[rt].add != 0) {
        tree[L(rt)].add += tree[rt].add;
        tree[R(rt)].add += tree[rt].add;
        tree[rt].add = 0;
    }
}
void update(int l,int r,int v,int rt) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        tree[rt].add += v;
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= r) update(l,r,v,L(rt));
    else if(l >= mid + 1)update(l,r,v,R(rt));
    else {
        update(l,mid,v,L(rt));
        update(mid + 1, r, v,R(rt));
    }
    //pushup(rt);
} 
int query(int l,int rt) {
    if(l == tree[rt].l && l == tree[rt].r) {
        return tree[rt].m + tree[rt].add;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(mid >= l) return query(l,L(rt));
    else  return query(l,R(rt));
}
void solve(int u,int v,int l) {
    if(u == v) {
        update(pathid[u],pathid[v],l,1);
        return ;
    }
    int f1 = pathtop[u],f2 = pathtop[v];
    int ret = 0;
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        //ret = max(ret,query(pathid[f1],pathid[u],1));
        update(pathid[f1],pathid[u],l,1);
        u = fa[f1];
        f1 = pathtop[u];
    }
    if(u == v) {
        update(pathid[u],pathid[v],l,1);
        return ;
    }
    if(dep[u] > dep[v]) swap(u,v);
    update(pathid[u],pathid[v],l,1);
    return ;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d %d",&n,&m,&q) != EOF) {
        for(int i=0;i<=n;++i) ma[i].clear();
        srep(i,n) {
            scanf("%d",&an[i]);
        }
        srep(i,m) {
            scanf("%d %d",&u,&v);
            add_edge(u,v);
        }
        buildpath();
        build(1,n,1);
        while(q --) {
            scanf("%s",op);
            if(op[0] == 'I') {
                scanf("%d %d %d",&u,&v,&l);
                solve(u,v,l);
            } else if(op[0] == 'D') {
                scanf("%d %d %d",&u,&v,&l);
                solve(u,v,-l);
            } else {
                scanf("%d",&u);
                printf("%d\n",query(pathid[u],1));
            }
        }
    }
    
	return 0;
}

