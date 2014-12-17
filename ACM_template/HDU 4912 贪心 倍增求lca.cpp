
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string>
#include <time.h>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
const int maxn=100010;
int head[maxn],tol,fa[maxn][20],dep[maxn];
struct Edge{
    int next,to;
    Edge(int _next=0,int _to=0){
        next=_next;to=_to;
    }
}edge[10*maxn];
void addedge(int u,int v){
    edge[tol]=Edge(head[u],v);
    head[u]=tol++;
}
void bfs(int s){   
    queue<int> q;
    dep[s]=0,fa[s][0]=s;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa[u][0])continue;
            fa[v][0]=u;
            dep[v]=dep[u]+1;
            q.push(v);
        }
    }
}
int LCA(int x,int y){       //fa[u][i] 就是u的第几个father,这里用的是倍增求lca
    if(dep[x]<dep[y])swap(x,y);
    for(int i=19;i>=0;i--)if((1<<i)&(dep[x]-dep[y]))x=fa[x][i];
    if(x==y)return x;
    for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
struct QQ{
    int u,v,lca;
}pp[100100];
bool vis[100100];
int n,m;
bool cmp(QQ a,QQ b){
    return dep[a.lca]>dep[b.lca];
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(head,-1,sizeof(head));
        tol=0;
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        bfs(1);
        for(int i=0;i<m;i++){
            scanf("%d%d",&pp[i].u,&pp[i].v);
            pp[i].lca=LCA(pp[i].u,pp[i].v);
        }
        sort(pp,pp+m,cmp);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<m;i++){
            int lca=pp[i].lca,flag=1,u=pp[i].u,v=pp[i].v;
            if(vis[u]||vis[v]||vis[lca])continue;
            for(int j=u;j!=lca;j=fa[j][0])
                if(vis[j]){
                    flag=0;break;
                }
            for(int j=v;j!=lca;j=fa[j][0])
                if(vis[j]){
                    flag=0;break;
                }
            if(!flag)continue;
            ans++;
            vis[lca]=1;
            for(int j=u;j!=lca;j=fa[j][0])vis[j]=1;
            for(int j=v;j!=lca;j=fa[j][0])vis[j]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

