
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string.h>
using namespace std;
const int inf=500000000;
const int MAX=2000095;
struct node
{
    int v,next;
    int c;
}g[MAX];
int num[MAX],dis[MAX],cur[MAX],adj[MAX],pre[MAX];
int start,tend,e,vn,r,c,l;

void init(int nn,int ss,int tt)
{
    e=0;
    memset(adj,-1,sizeof(adj));
    start=ss;
    tend=tt;
    vn=nn;
}
void add(int u,int v,int c)
{
    g[e].v=v; g[e].c=c; g[e].next=adj[u]; adj[u]=e++;
    g[e].v=u; g[e].c=0; g[e].next=adj[v]; adj[v]=e++;
}
int sap()
{
    int i,u,v,flag;
    int aug=inf,flow=0.0;
    for(i=0;i<=vn;i++)
    {
        dis[i]=num[i]=0;
        cur[i]=adj[i];
    }
    u=start;
    num[0]=vn;
    while(dis[start]<vn)
    {
        flag=0;
        for(i=cur[u];i!=-1;i=g[i].next)
        {
            v=g[i].v;
            if(g[i].c>0.0&&dis[u]==dis[v]+1)
            {
                flag=1;
                cur[u]=i;
                pre[v]=u;
                aug=min(aug,g[i].c);
                u=v;
                if(u==tend)
                {
                    flow+=aug;
                    //cout<<flow<<endl;
                    while(u!=start)
                    {
                        u=pre[u];
                        g[cur[u]].c-=aug;
                        g[cur[u]^1].c+=aug;
                    }
                    aug=inf;
                }
                break;
            }
        }
        if(flag)
            continue;
        if(--num[dis[u]]==0)
            return flow;
        for(dis[u]=vn,i=adj[u];i!=-1;i=g[i].next)
        {
            v=g[i].v;
            if(g[i].c>0.0&&dis[v]<dis[u])
            {
                dis[u]=dis[v];
                cur[u]=i;
            }
        }
        dis[u]++;
        num[dis[u]]++;
        if(u!=start)
            u=pre[u];
    }
    return flow;
}
int a[1099],s[1099],dp[1099];
int lis(int n)
{
    int l,r,mid,len=1;
    a[1]=s[1];dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        l=1;r=len;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(a[mid]<s[i])l=mid+1;
            else
                r=mid-1;
        }
        a[l]=s[i];
        dp[i]=l;
        if(l>len)len++;
    }
    return len;
}

int main()
{
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,j;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
        }
        int max=lis(n);
        for(int i=1;i<=n;++i) cout<<dp[i]<<"  ";cout<<endl;
        init(2*n+2,0,2*n+1);
        for(i=1;i<=n;i++)
        {
            if(dp[i]==1){
                add(0,i,1);
            }
            if(dp[i]==max){
                add(i+n,n*2+1,1);
            }
            add(i,i+n,1);
        }

        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if((dp[i]+1)==dp[j]&&s[i]<s[j]){
                    add(i+n,j,1);
                }
            }
        }

        printf("%d\n",sap());
    }
    return 0;
}
