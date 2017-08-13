#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long LL;
int fa[MAXN],anc[MAXN][32],deep[MAXN],dis[MAXN];
struct node{
    int to, val;
};
vector<node> edge[MAXN];
inline void dfs(int x){
    anc[x][0] = fa[x];
    for(int i = 1; i <= 31; i ++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
    int lens = edge[x].size();
    for(int i = 0; i < lens; i ++) {
        node nex = edge[x][i];
        if(nex.to != fa[x]) {
            fa[nex.to] = x;
            deep[nex.to] = deep[x] + 1;
            dis[nex.to] = dis[x] + nex.val;
            dfs(nex.to);
        }
    }
}
inline int LCA(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 31; i >= 0; i --) {
        if(deep[y] <= deep[anc[x][i]]) x = anc[x][i];
    } if(x == y) return x;
    for(int i = 31; i >= 0; i --) {
        if(anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
    } return anc[x][0];
}
int T, n, m;
vector<int> office[MAXN];
int main() {
    scanf("%d", &T);
    while(T --) {
        int u, v, w;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) edge[i].clear(), office[i].clear();
        memset(fa, 0, sizeof(fa)); memset(anc, 0, sizeof(anc));
        for(int i = 1; i < n; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back((node){v, w});
            edge[v].push_back((node){u, w});
        } for(int i = 1; i <= m; i ++) {
            int num; scanf("%d", &num);
            for(int j = 1; j <= num; j ++) {
                int id; scanf("%d", &id);
                office[i].push_back(id);
            }
        } fa[1] = 1; dfs(1);
        int Q;
        scanf("%d", &Q);
        for(int i = 1; i <= Q; i ++) {
            int ans = 99999999;
            scanf("%d%d", &u, &v);
            int l1 = office[u].size(), l2 = office[v].size();
            for(int j = 0; j < l1; j ++) {
                for(int k = 0; k < l2; k ++) {
                    int lca = LCA(office[u][j], office[v][k]);
                    ans = min(ans, dis[office[u][j]] + dis[office[v][k]] - dis[lca] * 2);
                }
            } printf("%d\n", ans);
        }
    }
    return 0;
}


