#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int now,next;
} tree[40005];

int n,sum[40005],son[20005];
int head[20005],vis[20005],len;
//sum数组代表包含该节点与该点子节点数量和
//son数组代表该节点包含的所有子树的最大节点数
void add(int x,int y)//建树
{
    len++;
    tree[len].now = y;
    tree[len].next = head[x];
    head[x] = len;

    len++;
    tree[len].now = x;
    tree[len].next = head[y];
    head[y] = len;
}

void dfs(int root)
{
    int i,j;
    vis[root] = 1;
    for(i = head[root]; i!=-1; i = tree[i].next)
    {
        if(!vis[tree[i].now])
        {
            dfs(tree[i].now);
            sum[root]+=sum[tree[i].now];
            if(son[root]<sum[tree[i].now])
                son[root] = sum[tree[i].now];
        }
    }
}


int main()
{
	freopen("input.txt","r",stdin);
    int T,i,j,x,y,ans,pos;
    scanf("%d",&T);
    while(T--)
    {
        len = 0;
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        memset(head,-1,sizeof(head));
        for(i = 1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
        }
        memset(son,0,sizeof(son));
        memset(vis,0,sizeof(vis));
        for(i = 0; i<=n; i++)
            sum[i] = 1;
        dfs(1);
        for(int i=1;i<=7;++i) cout<<sum[i]<<"   "<<son[i]<<endl;
        pos = 1;
        ans = son[1];
        for(i = 2; i<n; i++)
        {
            if(ans>max(sum[1]-sum[i],son[i]))
            {
                ans = max(sum[1]-sum[i],son[i]);
                pos = i;
            }
        }
        printf("%d %d\n",pos,ans);
    }

    return 0;
}
