#include<bits/stdc++.h>
using namespace std;
#define LL long long

#define maxn  505
#define  maxm  400005
#define INF 0x3f3f3f3f

struct Edge
{
    int v, c, w, next;
    Edge() {}
    Edge(int v, int c, int w, int next) : v(v), c(c), w(w), next(next) {}
} E[maxm];

queue<int> q;
int H[maxn], cntE;
int visit[maxn];
int cap[maxn];
int vis[maxn];
int dis[maxn];
int cur[maxn];
int flow, cost, s, t, T;

void addedges(int u, int v, int c, int w)
{
    E[cntE] = Edge(v, c, w, H[u]);
    H[u] = cntE++;
    E[cntE] = Edge(u, 0, -w, H[v]);
    H[v] = cntE++;
}

bool spfa()
{
    memset(dis, INF, sizeof dis);
    cur[s] = -1;
    vis[s] = ++T;
    cap[s] = INF;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = T - 1;
        for (int e = H[u]; ~e; e = E[e].next)
        {
            int v = E[e].v, c = E[e].c, w = E[e].w;
            if (c && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cap[v] = min(cap[u], c);
                cur[v] = e;
                if (vis[v] != T)
                {
                    vis[v] = T;
                    q.push(v);
                }
            }
        }
    }
    if (dis[t] > 0) return false;
    cost += cap[t] * dis[t];
    flow += cap[t];
    for (int e = cur[t]; ~e; e = cur[E[e ^ 1].v])
    {
        E[e].c -= cap[t];
        E[e ^ 1].c += cap[t];
    }
    return true;
}

int mfmc()
{
    flow = cost = 0;
    while (spfa());
    return cost;
}

int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;

}
int n, m;
int a[505], b[505], c[505], d[505];
int g[505][505];

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        cntE = T = 0;
        memset(H, -1, sizeof H);
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++)
        {
            a[i]=Read();
            b[i]=Read();
            c[i]=Read();
            d[i]=Read();
        }
        s = 0, t = n + 1;

        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
            {
                if (i == j) g[i][j] = 0;
                else g[i][j] = INF;
            }

        for (int i = 1; i <= m; i++)
        {
            int t1, t2, t3;
            t1=Read();t2=Read();t3=Read();
            if (g[t1][t2] > t3)
            {
                g[t1][t2] = g[t2][t1] = t3;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            addedges(i, t, b[i], a[i]);
            addedges(s, i, d[i], -c[i]);
        }

        for(int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i != j && g[i][j] != INF)
                {
                    addedges(i, j, INF, g[i][j]);
                }
            }
        int ans = -mfmc();
        printf("%d\n", ans);
    }


    return 0;
}
