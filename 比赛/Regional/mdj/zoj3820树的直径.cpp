
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=200200;
const int INF=0x3f3f3f3f;

struct Edge
{
    int to,next;
}edge[maxn*2];

int Adj[maxn],Size;

void init()
{
    memset(Adj,-1,sizeof(Adj)); Size=0;
}

void addedge(int u,int v)
{
    edge[Size].to=v; edge[Size].next=Adj[u]; Adj[u]=Size++;
}

int n;
int dist[maxn],pre[maxn];

int bfs(int u)
{
    queue<int> q;
    q.push(u); dist[u]=0;  pre[u]=0;

    while(!q.empty())
    {
        u=q.front(); q.pop();
        for(int i=Adj[u];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dist[v]>dist[u]+1)
            {
                dist[v]=dist[u]+1;
                pre[v]=u;
                q.push(v);
            }
        }
    }

    return u;
}

bool check(int& s,int& e,int L)
{
    memset(dist,63,sizeof(dist));

    s=bfs(1);   //直径的一个端点
    for(int i=0;i<L;i++)
    {
        s=pre[s];
        if(s==0)
        {
            e=s%n+1;
            return true;
        }
    }

    memset(dist,63,sizeof(dist));
    e=bfs(s);
    for(int i=0;i<L;i++)
    {
        e=pre[e];
        if(e==0)
            return true;
    }

    if(s==e) e=s%n+1;

    bfs(e);

    for(int i=1;i<=n;i++)
        if(dist[i]>L) return false;
    return true;
}

int nextInt()
{
    int ret=0;
    bool ok=false;
    char ch;
    while(ch=getchar())
    {
        if(ch>='0'&&ch<='9')
        {
            ret=ret*10+ch-'0';
            ok=true;
        }
        else if(ok==true) break;
    }
    return ret;
}

int main()
{
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            u=nextInt(); v=nextInt();
            addedge(u,v); addedge(v,u);
        }
        if(n==2)
        {
            printf("0 1 2\n");
            continue;
        }
        else
        {
            int low=0,high=n,mid,ans;
            int s,e;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(check(s,e,mid)==true)
                {
                    ans=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            check(s,e,ans);
            printf("%d %d %d\n",ans,s,e);
        }
    }
    return 0;
}
