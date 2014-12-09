
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
typedef long long ll;
const int inf=0x7FFFFFFF;
#define show(x) cout << x << endl
#define rep(i,n) for(int i=0;i<n;i++)
#define mset(a,i) memset(a,i,sizeof(a))
#define PB(i) push_back(i)

using namespace std;
#define MAX_N 100010
int N, a, b;
int p[MAX_N];
map<int, int> pos, vis;
int belong[MAX_N];
bool dfs(int x) {
	if(vis[x] != -1)
		return vis[x];
	if(pos.count(a - x) == 0)	return vis[x] = 0;
	int other = a - x, ot2 = b - x;
	vis[x] = 1;
	if(pos.count(ot2)) {
		if(!dfs(ot2)) 
			return vis[x] = 0;
	}
	if(!dfs(other))		return vis[x] = 0;
	return vis[x] = 1;
}
int main() {
	scanf("%d%d%d", &N, &a, &b);
	rep(i, N) {
		scanf("%d", p + i);
		pos[p[i]] = i;
		vis[p[i]] = -1;
	}
	rep(i, N) {
		if(dfs(p[i]))
			belong[i] = 1;
	}
	bool ok = true;
	rep(i, N) {
		if(belong[i] == 0) {
			if(!pos.count(b - p[i]) || belong[pos[b - p[i]]] == 1)
				ok = false;
		}
	}
	if(ok == false)		return puts("NO"), 0;
	puts("YES");
	rep(i, N) {
		printf("%d%c", 1 - belong[i], " \n"[i == N - 1]);
	}
	return 0;
}
