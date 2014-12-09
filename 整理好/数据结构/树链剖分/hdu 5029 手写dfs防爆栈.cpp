
/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/22 21:23:55
 |File Name: hdu 5029 self.cpp
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
#define maxn 100010
vector <int> ma[maxn];
int pathid[maxn],pathtop[maxn],dep[maxn];
int que[maxn*2],s,t,fa[maxn],size[maxn],son[maxn],tot;
int fq[maxn]; 
int n,m,u,v,tp;
inline void add_edge(int a,int b){
    ma[a].push_back(b);ma[b].push_back(a);
}
void buildpath() {
    int u,v;
    s = 0;t = 0;
    que[t ++] = 1;          //注意修改起点
    fa[1] = -1;dep[1] = 1;
    while(s < t) {
        u = que[s ++];
        rep(i,ma[u].size()) {
            v = ma[u][i];
            if(v != fa[u]) {
                fa[v] = u; dep[v] = dep[u] + 1; que[t ++] = v;
            }
        }
    }
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
    memset(pathtop,-1,sizeof(pathtop));
    int cnt = 1;
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
vector <int> avec[maxn],dvec[maxn];
void change(int u,int v,int z) {
    int f1 = pathtop[u],f2 = pathtop[v];
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) { //始终让f1在下面
            swap(f1,f2);
            swap(u,v);
        }
        avec[pathid[f1]].push_back(z);
        dvec[pathid[u] + 1].push_back(z);
        u = fa[f1];
        f1 = pathtop[u];
    }
    if(dep[u] > dep[v]) swap(u,v);
    avec[pathid[u]].push_back(z);
    dvec[pathid[v] + 1].push_back(z);
}
void init(int n){ 
    rep(i,n+1){         //主义这边是1-n，边界包括。
        ma[i].clear();
        avec[i].clear();dvec[i].clear();
    }
    tot = 0;
}
struct Tree{
    int l,r,id,m;
}tree[maxn << 2];
void pushup(int rt) {
    if(tree[L(rt)].m < tree[R(rt)].m) {
        tree[rt].m = tree[R(rt)].m;
        tree[rt].id = tree[R(rt)].id;
    } else {
        tree[rt].m = tree[L(rt)].m;
        tree[rt].id = tree[L(rt)].id;
    }
}
void build(int rt,int l,int r){
    tree[rt].l = l;tree[rt].r = r;
    if(l == r){
        tree[rt].id = l;
        tree[rt].m = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(L(rt),l,mid);
    build(R(rt),mid + 1,r);
    pushup(rt);
}
void update(int rt,int u,int v){
    int l = tree[rt].l,r = tree[rt].r;
    if(tree[rt].l == u && tree[rt].r == u){
        tree[rt].m += v;
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(u <= mid) update(L(rt),u,v);
    else update(R(rt),u,v);
    pushup(rt);
}
int ans[maxn];
int main() {
    //freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&m)) {
        if(n == 0 && m == 0) break;
        init(n);
        rep(i,n-1) {
            scanf("%d %d",&u,&v);
            add_edge(u,v);
        }
        buildpath();
        rep(i,m){
            scanf("%d %d %d",&u,&v,&tp);
            change(u,v,tp);
        }
        build(1,1,100000);
        for(int i=1;i<=n;++i){
            for(int j=0;j<avec[i].size();++j) {
                update(1,avec[i][j],1);
            }
            for(int j=0;j<dvec[i].size();++j) {
                update(1,dvec[i][j],-1);
            }
            u = fq[i];
            if(tree[1].m == 0) ans[u] = 0;
            else ans[u] = tree[1].id;
        }

        for(int i=1;i<=n;++i) {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
