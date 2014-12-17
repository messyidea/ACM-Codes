
#include <stdio.h>
#include <string.h>
#define len 510
int map[len][len];
int used[len];
int lin[len];
int n;
int dfs(int a)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(!used[i]&&map[a][i])
        {
            used[i]=1;
            if(lin[i]==-1||dfs(lin[i]))
            {
                lin[i]=a;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int a,b,m,sum,i;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(lin,-1,sizeof(lin));
        while(m--)
        {
            scanf("%d %d",&a,&b);
            map[a][b]=1;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            memset(used,0,sizeof(used));
            if(dfs(i))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 1;
}
