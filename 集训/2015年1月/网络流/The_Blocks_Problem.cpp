/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-28 12:14:03
 |File Name: The_Blocks_Problem.cpp
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
#define maxn 3000
#define maxe 90005
#define inf 0x3f3f3f3f
struct Edge {int v,c,x; }E[maxe];
int l[maxn],e;
void init() {e = 0;memset(l,-1,sizeof(l));}
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
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
int da[60][60];
int db[60][60];
inline bool check(int i,int j) {
    if(i < 0 || i >= n) return false;
    if(j < 0 || j >= m) return false;
    return true;
}
int main() {
	//freopen("input.txt","r",stdin);
    int sum; 
    while(scanf("%d %d",&n,&m) != EOF) {
        sum = 0;
        init();
        int src = n * m + 1;
        int sink = src + 1;
        flow.src = src; flow.sink = sink;
        rep(i,n) {
            rep(j,m){
                scanf("%d",&da[i][j]);
                db[i][j] = i * m + j;
                sum += da[i][j];
                if(((i + j) % 2) == 0) {
                    insert(src,db[i][j],da[i][j],0);
                    rep(k,4) {
                        int xx = i + dx[k], yy = j + dy[k];
                        if(check(xx,yy)) {
                            insert(db[i][j],xx * m + yy,inf,0);
                        }
                    }
                } else {
                    insert(db[i][j],sink,da[i][j],0);
                }
            }
        }
        printf("%d\n",sum - flow.dinic());
    } 
	return 0;
}

