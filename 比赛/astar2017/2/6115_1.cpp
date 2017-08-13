#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 1000000007
#define inf 1000000000
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool vis[100005];
int T;
int n, m, Q, id, cnt;
int last[100005];
int mp[100005], q[100005], dis[100005];
int dep[100005], D[100005];
vector<int>G[100005], B[100005];
int ans[205][100005];
int fa[100005][17];
map<int, int>ANS[100005];
struct data{
    int to, next, v;
}e[200005];
int lca(int x, int y)
{
    if(dep[x] < dep[y])swap(x, y);
    int d = dep[x] - dep[y];
    for(int i = 0; i <= 16; i++)
        if((1 << i) & d)x = fa[x][i];
    for(int i = 16; i >= 0; i--)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    if(x == y)return x;
    return fa[x][0];
}
void insert(int u, int v, int w)
{
    e[++cnt].to = v; e[cnt].next = last[u]; e[cnt].v = w; last[u] = cnt; 
    e[++cnt].to = u; e[cnt].next = last[v]; e[cnt].v = w; last[v] = cnt;
}
void bfs(int x)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    if(!mp[x])mp[x] = ++id;
    int now = mp[x], l = 0, r = 0;
    for(int i = 0; i < G[x].size(); i++)
    {
        q[r] = G[x][i];
        vis[G[x][i]] = 1;
        r++;
    }
    while(l <= r)
    {
        int u = q[l]; l++;
        for(int i = 0; i < B[u].size(); i++)
            ans[now][B[u][i]] = min(ans[now][B[u][i]], dis[u]);
        for(int i = last[u]; i; i = e[i].next)
            if(!vis[e[i].to])
            {
                vis[e[i].to] = 1;
                dis[e[i].to] = dis[u] + e[i].v;
                q[r] = e[i].to;
                r++;
            }
    }    
}
void dfs(int x)
{
    for(int i = 1; i <= 16; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i = last[x]; i; i = e[i].next)
        if(e[i].to != fa[x][0])
        {
            fa[e[i].to][0] = x;
            D[e[i].to] = D[x] + e[i].v;
            dep[e[i].to] = dep[x] + 1;
            dfs(e[i].to);
        }
}
int getdis(int x, int y)
{
    int f = lca(x, y);
    return D[x] + D[y] - 2 * D[f];
}
int main()
{
    T = read();
    while(T--)
    {
        cnt = id = 0;
        memset(last, 0, sizeof(last));
        memset(mp, 0, sizeof(mp));
        memset(ans, 127, sizeof(ans));
        for(int i = 1; i <= 100000; i++)
        {
            G[i].clear();
            B[i].clear();
            ANS[i].clear();
        }
        n = read(); m = read();
        for(int i = 1; i < n; i++)
        {
            int u = read(), v = read(), w = read();
            insert(u, v, w);
        }
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            x = read();
            for(int j = 1; j <= x; j++)
            {
                y = read();
                G[i].push_back(y);
                B[y].push_back(i);
            }
        }
        for(int i = 1; i <= m; i++)
            if(G[i].size() >= 500)
                bfs(i);
        dfs(1);
        Q = read();
        for(int i = 1; i <= Q; i++)
        {
            int x = read(), y = read();
            if(G[y].size() > G[x].size())swap(x, y);
            if(G[x].size() >= 500)
            {
                int now = mp[x];
                printf("%d\n", ans[now][y]);
            }
            else
            {
                if(ANS[x][y])
                    printf("%d\n", ANS[x][y] - 1);
                else
                {
                    int ans = inf;
                    for(int p = 0; p < G[x].size(); p++)
                        for(int q = 0; q < G[y].size(); q++)
                            ans = min(ans, getdis(G[x][p], G[y][q]));                    ANS[x][y] = ans + 1;
                    printf("%d\n", ans);
                }
            }
        }
    }
    return 0;
}