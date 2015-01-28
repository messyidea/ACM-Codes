/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-28 16:28:41
 |File Name: Firing.cpp
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
#define maxn 6006
#define maxe 100005
#define inf 0x3f3f3f3f
struct Edge {int v,x;ll c;}E[maxe];
int l[maxn],e;
void init() {e = 0;memset(l,-1,sizeof(l));}
inline void insert(int u,int v,int f,int invf){
    E[e].v = v;E[e].c = f;E[e].x = l[u];l[u] = e++;
    E[e].v = u;E[e].c = invf;E[e].x = l[v];l[v] = e++;
} 
struct Netflow {
    int src,sink;
    int L[maxn],Q[maxn];    //L层次,Q队列
    int _bfs() {
        int s = 0,t = 0,u;
        memset(L,0xff,sizeof(L));
        L[src] = 0;Q[t ++] = src;
        while(s < t){
            u = Q[s ++];
            for(int p = l[u];p >= 0;p = E[p].x){
                if(E[p].c && L[E[p].v] == -1) {
                    L[(Q[t++] = E[p].v)] = L[u] + 1;
                }
            }
        }
        return L[sink] != -1;
    }
    ll _find(int u,int in){
        if(u == sink) return in;
        ll t,w = 0;    //w表示已经从u流出的总流量
        for(int p = l[u];p >= 0 && w < in;p = E[p].x) {
            if(E[p].c > 0 && L[E[p].v] == L[u] + 1) {
                if(t = _find(E[p].v,min(E[p].c,in-w))) {
                    E[p].c -= t;
                    E[p^1].c += t;
                    w += t;
                }
            }
        }
        if(w < in) L[u] = -1;
        return w;
    }
    ll dinic() {
        ll t,res = 0;
        while(_bfs()){
            while(t = _find(src,inf)) res += t;
        }
        return res; 
    }
}flow;
int n,m;
bool vis[6005];
int qq[6005];
void dfs(int u) {
    vis[u] = true;
    for(int p = l[u];p >= 0;p = E[p].x) {
        if(!vis[E[p].v] && E[p].c > 0) {
            dfs(E[p].v);
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&m)) {
        int src = n + 3;
        int sink = src + 1;
        init();
        flow.src = src; flow.sink = sink;
        int t,a,b;
        long long sum = 0;
        srep(i,n) {
            scanf("%d",&t);
            if(t > 0) {
                sum += t;
                insert(src,i,t,0);
            } else {
                insert(i,sink,-t,0);
            }
        }
        rep(i,m) {
            scanf("%d %d",&a,&b);
            insert(a,b,inf,0);
        }
        ll ans = flow.dinic();
        int count = 0;
        memset(vis,false,sizeof(vis));
        dfs(src);
        for(int i=1;i<=n;++i) {
            if(vis[i]) count ++;
        }
        printf("%d",count);
        printf(" %lld\n",sum - ans);
    }
	return 0;
}

