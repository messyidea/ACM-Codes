/***********************************************\
 |Author: Messyidea
 |Created Time: 2014-8-2 13:48:06
 |File Name: 1001.cpp
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
#define lc (tree[rt].ls)
#define rc (tree[rt].rs)
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
#define maxn 100005
vector <int> ma[maxn];
int que[maxn],s,t,fa[maxn],size[maxn],son[maxn],tot;
//size表示点所在子树所含节点数，son代表重儿子
int pathid[maxn],pathtop[maxn],dep[maxn];
//pathid线段在线段树中的位置，pathtop点所在重链的最顶端节点
int sumTree[maxn],markTree[maxn];
//sumTree直接变化的，markTree记录哪些重链连接的边变化了。
bool col[maxn]; //记录该点的上面的轻链是否是黑色的
int n,m,a,b,c;
inline void add_edge(int a,int b){
    ma[a].push_back(b);ma[b].push_back(a);
}
struct Tree{
    int l,r,ls,rs,sum;
    bool lz;            //翻转两次就相当于不变
}tree[maxn<<2];
int build(int l,int r){
    int rt = tot++;
    tree[rt].l = l;tree[rt].r = r;
    tree[rt].lz = tree[rt].sum = 0;
    if(l + 1 == r){
        tree[rt].ls = tree[rt].rs = -1;
        return rt;
    }
    int mid = l + r >> 1;
    tree[rt].ls = build(l,mid);
    tree[rt].rs = build(mid,r);
    return rt;
}
inline void resum(int rt){
    tree[rt].sum = tree[rt].r - tree[rt].l - tree[rt].sum;
}
inline void pushdown(int rt){
    if(tree[rt].lz){
        resum(lc),resum(rc);
        tree[lc].lz ^= 1;tree[rc].lz ^= 1;
        tree[rt].lz = false;
    }
}
inline void pushup(int rt){
    tree[rt].sum = tree[lc].sum + tree[rc].sum;
}
void update(int rt,int l,int r){
    if(r <= l) return ;
    if(l >= tree[rt].r || r <= tree[rt].l) return ;
    if(tree[rt].l == l && tree[rt].r == r){
        tree[rt].lz ^= 1;
        tree[rt].sum = tree[rt].r - tree[rt].l - tree[rt].sum;
        return ;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if(r <= mid) update(lc,l,r);
    else if(l >= mid) update(rc,l,r);
    else update(lc,l,mid),update(rc,mid,r);
    pushup(rt);
}
int query(int rt,int l,int r){
    if(r <= l ) return 0;
    if( l >= tree[rt].r || r <= tree[rt].l) return 0;
    if(tree[rt].l == l && tree[rt].r == r) return tree[rt].sum;
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    if( r <= mid) return query(lc,l,r);
    else if( l >= mid) return query(rc,l,r);
    else return query(lc,l,mid) + query(rc,mid,r);
}

void buildpath(){           //建立树链的非递归方法
    int u,v;
    s = 0,t = 0;
    que[t++] = 0;
    fa[0] = -1;dep[0] = 1;
    while(s < t) {
        u = que[s++];
        rep(i,ma[u].size()) {
            v = ma[u][i];
            if(v != fa[u]) {
                fa[v] = u ; dep[v] = dep[u]+1 ; que[t++] = v; 
            }
        }
    }
    for(int j=n-1;j>=0;--j){
        u = que[j];
        son[u] = -1;
        size[u] = 1;
        rep(i,ma[u].size()){
            v = ma[u][i];
            if(v != fa[u]){
                size[u] += size[v];
                if(son[u] == -1 || size[v] > size[son[u]]) son[u] = v;
            }
        }
        if(son[u] == -1) son[u] = u;
    }
    memset(pathtop,-1,sizeof(pathtop));
    for(int i=0;i<n;++i){
        u = que[i];
        if(pathtop[u] != -1) continue;
        int top = u,cnt = 0;
        for(;;) {
            pathtop[u] = top;
            pathid[u] = cnt++;
            if(son[u] == u) break;
            u = son[u];
        }
        sumTree[top] = build(0,cnt);
        markTree[top] = build(0,cnt);
    }
}
void rev1(int u,int v){
    while(pathtop[u] != pathtop[v]){
        if(dep[pathtop[u]] < dep[pathtop[v]]) swap(u,v);
        update(sumTree[pathtop[u]],1,pathid[u]+1);//重链的直接修改
        u = pathtop[u];
        col[u] ^= 1;    //点上的轻链的修改
        u = fa[u];
    }
    if(pathid[u] > pathid[v]) swap(u,v);
    update(sumTree[pathtop[u]],pathid[u]+1,pathid[v]+1);
}
void rev2(int u,int v){
    while(pathtop[u] != pathtop[v]) {
        if(dep[pathtop[u]] < dep[pathtop[v]]) swap(u ,v);
        update(markTree[pathtop[u]],0,pathid[u]+1); //标记哪些重边相邻的轻边发生变化了
        update(sumTree[pathtop[u]],pathid[u]+1,pathid[u]+2);    //对u的下面的邻接的重边的操作
        u = pathtop[u];
        col[u] ^= 1;    //轻边的修改
        u = fa[u];
    }
    if(pathid[u] > pathid[v]) swap(u,v);    //让u在顶部
    update(markTree[pathtop[u]],pathid[u],pathid[v]+1); //翻转部分的修改
    if(u == pathtop[u]) col[u] ^= 1;    //如果u是重链的顶端，则改变它上面的轻链
    else update(sumTree[pathtop[u]],pathid[u],pathid[u]+1); //否则还要把它上面的重链进行修改
    update(sumTree[pathtop[u]],pathid[v]+1,pathid[v]+2);    //v底部的修改，重链总是会到底的，所以不用考虑底部是否为轻链
}
int cal(int u){
    int f = fa[u];
    return col[u] ^ query(markTree[pathtop[f]],pathid[f],pathid[f]+1);
}
int sum(int u,int v){
    int res = 0;
    int tp = 10;
    while (pathtop[u] != pathtop[v]) {
        if(dep[pathtop[u]] < dep[pathtop[v]]) swap(u,v);
        res += query(sumTree[pathtop[u]],1,pathid[u]+1);
        u = pathtop[u];
        res += cal(u);
        u = fa[u];
    }
    if(pathid[u] > pathid[v]) swap(u,v);
    res += query(sumTree[pathtop[u]],pathid[u]+1,pathid[v]+1);
    return res;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tot = 0;
        rep(i,n) ma[i].clear();
        memset(col,false,sizeof(col));
        rep(i,n-1){
            scanf("%d%d",&a,&b);
            a--,b--;
            add_edge(a,b);
        }
        buildpath();
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            b--;c--;
            if(a == 1) rev1(b,c);
            else if(a == 2) rev2(b,c);
            else printf("%d\n",sum(b,c));
        }
    }
	return 0;
}

