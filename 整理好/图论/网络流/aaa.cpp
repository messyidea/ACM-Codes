
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int inf = 0x7FFFFFFF;
#define MAX_N 125
#define MAX_E 33333

struct Edge{
	int v, cap, x, w;
}E[MAX_E];
int l[MAX_N], tot, d[MAX_N], Q[MAX_E], p[MAX_N];
bool inq[MAX_N];

inline void add(int u, int v, int cap, int w) {
	E[tot].v = v; E[tot].w = w; E[tot].cap = cap;
	E[tot].x = l[u]; l[u] = tot ++;
	E[tot].v = u; E[tot].w = -w; E[tot].cap = 0;
	E[tot].x = l[v]; l[v] = tot ++;
}
int Mincost(int n, int src, int sink) {
	int cost = 0, u, v, s, t;
	while(true) {
		s = t = 0;
		memset(inq, false, sizeof inq);
		for(int i = 1; i <= n; i ++)
			d[i] = inf;
		d[src] = 0;
		Q[t ++] = src;
		while(s < t) {
			u = Q[s ++];
			inq[u] = false;
			for(int i = l[u]; ~i; i = E[i].x) {
				int v = E[i].v;
				if(E[i].cap && d[v] > d[u] + E[i].w) {
					d[v] = d[u] + E[i].w;
					p[v] = i;
					if(!inq[v]) {
						inq[Q[t ++] = v] = true;
					}
				}
			}
		}
		if(d[sink] == inf)	return cost;
		int c = inf;
		for(int i = sink; i != src; i = E[p[i] ^ 1].v) 
			c = min(c, E[p[i]].cap);
		cost += c * d[sink];
	//	printf("%d\n", d[sink]);
		for(int i = sink; i != src; i = E[p[i] ^ 1].v) {
			E[p[i]].cap -= c;
			E[p[i] ^ 1].cap += c;
		}
	}
}

int main() {
	int n, val, u, v;
	int src, sink, ss, _S, _T;
	while(~scanf("%d", &n)) {
		memset(l, -1, sizeof l);
		tot = 0;
		src = n + 1;
		ss = src + 1;
		sink = ss + 1;
		_S = sink + 1;
		_T = _S + 1;
		int sum = 0;
		for(int i = 1;i <= n; i ++) {
			scanf("%d", &val);
			sum += val;
			add(src, i, val, 0);
			add(i, ss, 1, 0);
		}
		for(int i = 1; i < n; i ++) {
			scanf("%d%d%d", &u, &v, &val);
			u ++, v ++;
			add(u, v, inf, val);
			add(v, u, inf, val);
		}
		add(ss, sink, sum, 0);
		add(sink, src, inf, 0);
		int ave = sum / n;
		add(_S, ss, ave * n, 0);
		for(int i = 1; i <= n; i ++)
			add(i, _T, ave, 0);
		int ans = 0;
		ans += Mincost(_T, _S, _T);
		ans += Mincost(_T, src, sink);
		printf("%d\n", ans);
	}
	return 0;
}
