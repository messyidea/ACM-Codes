#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 25005
#define maxe 25005
#define inf 0x3f3f3f3f
struct Edge {int v,c,x; }E[maxe*100];
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
int cas = 1;
int ma;
int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        init();
        scanf("%d%d",&n,&m);
        int sum = 0;
        ma = 0;
        for(int i=1;i<=n;++i) {
            scanf("%d%d%d",&u,&v,&w);
            if(w > ma) ma = w;
            sum += u;
            insert(0,i,u,0);
            for(int j=v;j<=w;++j){
                insert(i,n + j,1,0);
            }
        }
        for(int j=n+1;j<=n+ma;++j){
            insert(j,ma+n+2,m,0);
        }
        flow.src = 0;flow.sink = ma+n+2;
        printf("Case %d: ",cas ++);
        if(sum == flow.dinic()) puts("Yes");
        else puts("No");
        puts("");
    }
    return 0;
}
