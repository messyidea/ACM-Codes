
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
int que[maxn],s,t,fa[maxn],size[maxn],son[maxn],tot;
int fq[maxn];
ll an[maxn],bn[maxn];
int n,m,u,v,cnt;
int tp;
inline void add_edge(int a,int b){
    ma[a].push_back(b);ma[b].push_back(a);
}
//树链剖分
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

void init(int n){ 
    rep(i,n+2){
        ma[i].clear();
    }
    memset(an,0,sizeof(an));
    memset(bn,0,sizeof(bn));
}

void change1(int u,int v,int z) {
    int f1 = pathtop[u],f2 = pathtop[v];
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) { //始终让f1在下面
            swap(f1,f2);
            swap(u,v);
        }
        an[pathid[f1]] += z;
        an[pathid[u] + 1] -= z;
        u = fa[f1];
        f1 = pathtop[u];
    }
    if(dep[u] > dep[v]) swap(u,v);
    an[pathid[u]] += z;
    an[pathid[v] + 1] -= z;
}


void change2(int u,int v,ll z) {
    //if(u == v) return;
    int f1 = pathtop[u],f2 = pathtop[v];
    while(f1 != f2) {
        if(dep[f1] < dep[f2]) { //始终让f1在下面
            swap(f1,f2);
            swap(u,v);
        }
        bn[pathid[f1]] += z;
        bn[pathid[u] + 1] -= z;
        u = fa[f1];
        f1 = pathtop[u];
    }
    if(u == v) return ;
    if(dep[u] > dep[v]) swap(u,v);
    bn[pathid[son[u]]] += z;
    bn[pathid[v]+1] -= z;
}

char ch[20];
ll ans[maxn];
ll ans1[maxn];
//int lll[maxn],rrr[maxn];
pair<int,int> pa[maxn];
int main() {
    //freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--) {
        scanf("%d %d",&n,&m);
        init(n);
        rep(i,n-1) {
            scanf("%d %d",&u,&v);
            add_edge(u,v);
            pa[i] = make_pair(u,v);
        }

        buildpath();        //剖分
        rep(i,n-1){
            if(dep[pa[i].first] < dep[pa[i].second]) {
                swap(pa[i].first,pa[i].second);
            }
        }
        rep(i,m){
            scanf("%s %d %d %d",ch,&u,&v,&tp);
            if(ch[3] == '1'){
                change1(u,v,tp);
            }
            else {
                change2(u,v,tp);
            }
        }
        printf("Case #%d:\n",cas ++);
        ll sum = 0;
        for(int i=1;i<=n;++i){
            sum += an[i];
            ans1[fq[i]] = sum;
        }
        for(int i=1;i<n;++i){
            printf("%I64d ",ans1[i]);
        }
        printf("%I64d\n",ans1[n]);
        if(n == 1){
            puts("");
            continue;
        }
        sum = 0;
        for(int i=2;i<=n;++i){
            sum += bn[i];
            ans[fq[i]] = sum;
        }
        rep(i,n-2){
            printf("%I64d ",ans[pa[i].first]);
        }
        printf("%I64d\n",ans[pa[n-2].first]);
    }
    return 0;
}
