#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define srep(i,n) for(int i=0;i<n;++i)
#define maxn 2000095
#define maxe 9000005
#define inf 0x3f3f3f3f
int dp[100005];
int da[100005];
int mx;
int n,m;
int u,v,w;
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
void solve() {
    for(int i=0;i<=n;++i) dp[i] = 1;
    mx = 1;
    for(int i=2;i<=n;++i) {
        for(int j=i-1;j>=1;--j) {
            if(da[j] < da[i]) {
                dp[i] = max(dp[i],dp[j] + 1);
                if(dp[i] > mx) mx = dp[i];
            }
        }
    }
    
    if(mx == 1) {
        printf("%d\n",n);
        return ;
    }
    init();
    flow.src = 2*n+2;
    flow.sink = 2*n+3;
    for(int i=1;i<=n;++i) {
        if(dp[i] == 1) {
            insert(flow.src,i,1,0);
        }
        if(dp[i] == mx) {
            insert(i+n,flow.sink,1,0);
        }
        insert(i,i+n,1,0);
    }
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            if(dp[j] == dp[i] + 1 && da[j] > da[i]) {
                insert(i+n,j,1,0);
            }
        }
    }
    printf("%d\n",flow.dinic());
}

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        srep(i,n) scanf("%d",&da[i]);
        solve();
    }
    return 0;
}
