/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-28 15:49:26
 |File Name: Hard_Life.cpp
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
#define maxn 300
#define maxe 90005
#define inf 0x3f3f3f3f
struct Edge {int v,c,x; }E[maxe];
int l[maxn],e;
void init() {e = 0;memset(l,-1,sizeof(l));}
inline void insert(int u,int v,double f,double invf){
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
pair<int,int> pp[1005];
//vector <int> ve[1005];
int cal(int u) {
    rep()
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&m)) {
        rep(i,m) {
            scanf("%d %d",&pp[i].first,&pp[i].second);
        }
        init();
        int src = n + m + 2;
        int sink = src + 1;
        flow.src = src; flow.sink = sink;
        rep(i,m) {
            insert(src,i,1,0);
            insert(i,m + pp[i].first,inf,0);
            insert(i,m + pp[i].second,inf,0);
        }
        double l = 0,r = 10;
        double mid = (l + r) / 2.0; 
        /*rep(i,n) {
            insert(m + i,sink,g,0);
        }*/
        while(l < r) {
            cal(mid);
        }


    }
	return 0;
}

