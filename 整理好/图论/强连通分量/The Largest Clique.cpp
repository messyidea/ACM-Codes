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
typedef long long ll;
const double eps=1e-7;
const int inf=0x7FFFFFFF;
#define rep(i,n) for(int i=0;i<n;i++)
#define mset(a,i) memset(a,i,sizeof(a))
#define MAX_N 1010
#define MAX_E 101000

using namespace std;
struct Edge {
	int v, x, u;
}E[MAX_E];
int l[MAX_N], tot;
int S[MAX_N], top, _clock;
vector<int> dag[MAX_N];
int pre[MAX_N], sccno, scc[MAX_N];
int cnt[MAX_N];
inline void add(int u, int v) {
	E[tot].u = u;
	E[tot].v = v;
	E[tot].x = l[u];
	l[u] = tot ++;
}

int dfs(int u) {
	int lowu = pre[u] = ++_clock;
	S[top ++] = u;
	for(int i = l[u]; ~i; i = E[i].x) {
		int v = E[i].v;
		if(!pre[v]) {
			lowu = min(lowu, dfs(v));
		} else if(!scc[v]) {
			lowu = min(lowu, pre[v]);
		}
	}
	if(lowu == pre[u]) {
		sccno ++;
		for(int v = -1; v != u;) {
			v = S[-- top];
			scc[v] = sccno;
			cnt[sccno] ++;
		}
	}
	return lowu;
}

void Build() {
	rep(i, tot) {
		int u = E[i].u;
		int v = E[i].v;
		if(scc[u] != scc[v]){
			dag[scc[u]].push_back(scc[v]);
			//cout<<scc[u]<<" "<<dag[scc[u]].size()<<endl;
		}
			
	}
}
 
int mi[MAX_N];
int dfs2(int u) {
	if(mi[u] != -1)		return mi[u];
	int sz = dag[u].size();
	int num = 0;
	rep(i, sz) {
		int v = dag[u][i];
		num = max(dfs2(v), num);
	}
	return mi[u] = num + cnt[u];
}

int main() {
	int T, n, m, u, v;
	scanf("%d", &T);
	while(T --) {
		mset(l, -1);
		mset(cnt, 0);
		mset(mi, -1);
		mset(pre, 0);
		mset(scc, 0);
		tot = top = _clock = sccno = 0;
		scanf("%d%d", &n, &m);
		rep(i, m) {
			scanf("%d%d", &u, &v);
			u --, v --;
			add(u, v);
		}
		rep(i, n)if(!pre[i]) {
			dfs(i);
		}
		for(int i = 1; i <= n; i ++)
			dag[i].clear();
		Build();
        //cout<<dag[1].size()<<endl;
		int ans = 0;
		for(int i = 1; i <= sccno; i ++)if(mi[i] == -1) {
			ans = max(ans, dfs2(i));
		}
		printf("%d\n", ans);
	}
	return 0;
}
