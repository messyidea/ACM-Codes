#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 300
#define maxe 90005
#define inf 0x3f3f3f3f
struct Edge {int v,c,x; }E[maxe];
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
    int _find(int u,int in){
        if(u == sink) return in;
        int t,w = 0;    //w表示已经从u流出的总流量
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
    int dinic() {
        int t,res = 0;
        while(_bfs()) while(t = _find(src,inf)) res += t;
        return res; 
    }
}flow;
int n,m;
int u,v,w;
int main(){
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        init();
        flow.src = 1;flow.sink = m;
        while(n--) {
            scanf("%d%d%d",&u,&v,&w);
            insert(u,v,w,0);
        }
        printf("%d\n",flow.dinic());
    }
    return 0;
}
