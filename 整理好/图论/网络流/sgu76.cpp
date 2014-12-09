#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
const int inf = 1e9 + 10;
#define MAX_N 300
#define MAX_E 300*300
#define rep(i, n)	for(int i = 0; i < n; i ++)
struct Edge{
	int v, cap, x;
}E[MAX_E];
int d[MAX_N], l[MAX_N], Q[MAX_N], tot;

inline void add(int u, int v, int cap) {
	E[tot].v = v; E[tot].cap = cap; E[tot].x = l[u]; l[u] = tot ++;
	E[tot].v = u; E[tot].cap = 0; E[tot].x = l[v]; l[v] = tot ++;
}
bool bfs(int src, int sink) {
	memset(d, 0xff, sizeof d);
	int s = 0, t = 0, u;
	d[src] = 0;
	Q[t ++] = src;
	while(s < t) {
		u = Q[s ++];
		for(int i = l[u]; ~i; i = E[i].x) {
			int v = E[i].v;
			if(d[v] == -1 && E[i].cap)
				d[Q[t ++] = v] = d[u] + 1;
		}
	}
	return d[sink] != -1;
}
int dfs(int u, int in, int sink) {
	if(u == sink)		return in;
	int flow = 0, f;
	for(int i = l[u]; ~i && flow < in; i = E[i].x) {
		int v = E[i].v;
		if(d[v] == d[u] + 1 && E[i].cap) {
			if(f = dfs(v, min(in - flow, E[i].cap), sink)) {
				E[i].cap -= f;
				E[i ^ 1].cap += f;
				flow += f;
			}
		}
	}
	if(flow < in)	d[u] = -1;
	return flow;
}

int Dinic(int src, int sink) {
	int flow = 0, tmp;
	while(bfs(src, sink)) {
		while(tmp = dfs(src, inf, sink))
			flow += tmp;
	}
	return flow;
}
struct question{
	int e, typ, cap;
	question(int e=0, int typ=0, int cap=0):e(e),typ(typ), cap(cap){}
}qq[MAX_E];

int dd[MAX_E];
int up;
int main() {
    //freopen("input.txt","r",stdin);
	int n, m, u, v, w, typ;
	int src, sink, _S, _T;
	while(~scanf("%d%d", &n, &m)) {
		memset(l, -1, sizeof l);
		tot = 0;
		src = 1, sink = n;
		_S = sink + 1, _T = _S + 1;
		int sum = 0;
		rep(i, m) {
			scanf("%d%d%d%d", &u, &v, &dd[i], &up);
            add(_S,v,dd[i]);
            add(u,_T,dd[i]);
            add(u,v,up - dd[i]);
            sum += dd[i];
            qq[i] = question(tot-1,up-dd[i],dd[i]);
		}
		if(sum != Dinic(_S, _T)) {
			puts("NO");
		} else {
            puts("YES");
            rep(i,m){
                printf("%d\n",qq[i].cap +  E[qq[i].e].cap);
            }
        }
	}
	return 0;
}

