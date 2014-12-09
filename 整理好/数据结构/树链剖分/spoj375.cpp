#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
#define MAXN 10010
#define INF 987654321
struct tree_node
{
    int left,right;
    int num;
};
struct node
{
    int r,id;
    node *next;
};
node *graph[MAXN];
node memo[MAXN*2];
tree_node tree[4*MAXN];
int d[MAXN],father[MAXN],line[MAXN],son[MAXN],sonl[MAXN],top[MAXN],mark[MAXN],home[MAXN];
int n,m,edge[MAXN];
int etop;
void add(int x,int y,int id)
{
    node *p=&memo[etop++];
    p->r=y; p->id=id; p->next=graph[x]; graph[x]=p;
    p=&memo[etop++];
    p->r=x; p->id=id; p->next=graph[y]; graph[y]=p;
}
int dfs1(int i,int deep,int fa,int edge_id)
{
    d[i]=deep; father[i]=fa; line[i]=edge_id; 
    int size=1,maxsize=0,temp;
    for(node *p=graph[i];p;p=p->next)
    if(p->r!=father[i])
    {
        temp=dfs1(p->r,deep+1,i,p->id);
        if(temp>maxsize)
        {
            maxsize=temp; son[i]=p->r; sonl[i]=p->id;
        }
        size+=temp;
    }
    return size;
}
void dfs2(int x,int y)
{
    mark[line[x]]=++m; top[x]=y;
    home[m]=line[x];
    if(son[x]==-1) return ;
    dfs2(son[x],y);
    for(node *p=graph[x];p;p=p->next)
        if(p->r!=father[x]&&p->r!=son[x]) dfs2(p->r,p->r);
}
int build_tree(int t)
{
    if(tree[t].left==tree[t].right)
    {
        return tree[t].num=edge[home[tree[t].left]];
    }
    int mid=(tree[t].left+tree[t].right)/2;
    tree[2*t].left=tree[t].left; tree[2*t].right=mid;
    tree[2*t+1].left=mid+1; tree[2*t+1].right=tree[t].right;
    return tree[t].num=max(build_tree(2*t),build_tree(2*t+1));
}
void change(int i,int pos,int x)
{
    if(tree[i].left==tree[i].right)
    {
        tree[i].num=x;
        return ;
    }
    int mid=(tree[i].left+tree[i].right)/2;
    if(pos<=mid) change(2*i,pos,x);
    else change(2*i+1,pos,x);
    tree[i].num=max(tree[i*2].num,tree[i*2+1].num);
}
int search(int i,int x,int y)
{
    if(tree[i].left==x&&tree[i].right==y)
        return tree[i].num;
    int mid=(tree[i].left+tree[i].right)/2;
    if(y<=mid) return search(2*i,x,y);
    else if(x>mid) return search(2*i+1,x,y);
    else return max(search(2*i,x,mid),search(2*i+1,mid+1,y));
}
        

void build()
{
    dfs1(1,1,-1,0);
    dfs2(1,1);
    tree[1].left=1; tree[1].right=n; 
    build_tree(1);
}
void solve()
{
    char c[10];
    int x,y,nx,ny,ans;
    while(1)
    {
        scanf("%s",c);
        if(c[0]=='D') break;
        scanf("%d%d",&x,&y);
        if(c[0]=='C') change(1,mark[x],y);
        if(c[0]=='Q')
        {
            if(x==y) 
            {
                printf("0\n"); continue;
            }
            for(ans=-INF;top[x]!=top[y];x=father[nx])
            {
                nx=top[x]; ny=top[y];
                if(d[nx]<d[ny])
                {
                    swap(x,y); swap(nx,ny);
                }
                ans=max(ans,search(1,mark[line[nx]],mark[line[x]]));
            }
            if(d[x]<d[y]) swap(x,y);
            if(x!=y)
            ans=max(ans,search(1,mark[sonl[y]],mark[line[x]]));
            printf("%d\n",ans);
        }
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        etop=m=0; edge[0]=-INF;
        memset(son,0xff,sizeof(son));
        memset(sonl,0xff,sizeof(sonl));
        memset(graph,0,sizeof(graph));
        int x,y;
        int i;
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,edge+i);
            add(x,y,i);
        }
        build();
        solve();
    }
    return 0;
}
