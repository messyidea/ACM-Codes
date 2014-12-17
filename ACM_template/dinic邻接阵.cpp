/***********************************************\
 |Author: YMC
 |Created Time: 2014/8/18 9:40:50
 |File Name: dinic.cpp
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
#define maxn 500

int n,adj[maxn][maxn],src,sink; //n要先确定,对应的是0-(n-1)
int L[maxn],Q[maxn];
int _bfs(){
    int s = 0,t = 0,u;
    memset(L,0xff,sizeof(L));
    L[src] = 0;Q[t++] = src;
    while(s < t){
        u = Q[s ++];
        for(int v = 0;v < n;v ++){
            if(adj[u][v] && L[v] == -1){
                L[(Q[t++] = v)] = L[u] + 1;
            }
        }
    }
    return L[sink] != -1;
}
int _find(int u,int in){
    if(u == sink) return in;
    int t,w = 0;
    for(int v = 0;v < n && w < in;v ++){
        if(adj[u][v] && L[v] == L[u] + 1){
            if(t = _find(v,min(adj[u][v],in-w))) {
                adj[u][v] -= t;
                adj[v][u] += t;
                w += t;
            }
        }
    }
    if(w < in) L[u] = -1;   //流完了,那就不能流了。
    return w;
}
int dinic() {
    int t,res = 0;
    while(_bfs()) while(t = _find(src,inf)) res += t;
    return res;
}
int m;
int u,v,w;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d%d",&m,&n)) {
        memset(adj,0,sizeof(adj));
        src = 0;
        sink = n-1;
        while(m -- ) {
            scanf("%d%d%d",&u,&v,&w);
            u --;v --;
            adj[u][v] += w;
        }
        printf("%d\n",dinic());
    }
	return 0;
}

