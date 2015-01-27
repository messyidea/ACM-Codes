/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-27 12:38:36
 |File Name: Flow construction
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
        while(_bfs()){
            while(t = _find(src,inf)) res += t;
        }
        return res; 
    }
}flow;
int n,m;
int u,v,w;
struct Pipe {
    int u,v,c,p;
}pipe[10005];
int qu[10005];
bool qq[10005];
int an[10005];
int cap[10005];
int tot;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&m)) {
        int src = 1;
        int sink = n;
        int ssrc = sink + 1;
        int ssink = ssrc + 1;
        init();
        int sum = 0;
        tot = 0;
        memset(qq,false,sizeof qq);
        rep(i,m) {
            scanf("%d %d %d %d",&pipe[i].u,&pipe[i].v,&pipe[i].c,&pipe[i].p);
            cap[i] = pipe[i].c;
            if(pipe[i].p == 1) {
                sum += pipe[i].c;
                insert(ssrc,pipe[i].v,pipe[i].c,0);
                insert(pipe[i].u,ssink,pipe[i].c,0);
                qq[i] = true;
            } else {
                insert(pipe[i].u,pipe[i].v,pipe[i].c,0);
                qu[i] = e - 2;
            }
        }
        flow.src = ssrc;flow.sink = ssink;
        int ans = flow.dinic();
        insert(sink,src,inf,0);
        int st = e - 2;
        int ans2 = flow.dinic();
        ans = ans + ans2;
        if(ans != sum) {
            puts("Impossible");
        } else {
            printf("%d\n",inf - E[st].c);
            rep(i,m) {
                if(qq[i]) an[i] = pipe[i].c;
                else an[i] = cap[i] - E[qu[i]].c;
            }
            printf("%d",an[0]);
            for(int i=1;i<m;++i) printf(" %d",an[i]);
            puts("");
        }
    }
    return 0;
}
