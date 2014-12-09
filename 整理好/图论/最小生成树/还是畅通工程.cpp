/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/3 23:22:25
 |File Name: 还是畅通工程.cpp
 |Description:
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;
#define inf 1<<29
int n;
int map[105][105];
int ans;
int dis[105];
void prim()
{
    int i, j, now, min_node, min_edge;
    for (i = 1; i <= n; i ++)
        dis[i] = inf;
    now = 1;
    ans = 0;
    for (i = 1; i < n; i ++)
    {
        dis[now] = -1;    
        min_edge = inf;
        for (j = 1; j <= n; j ++)   
            if (now != j && dis[j] >= 0)
            {
                dis[j] = min(dis[j], map[now][j]);
                if (dis[j] < min_edge)
                {
                    min_edge = dis[j];
                    min_node = j;
                }
            }
        now = min_node;
        ans += min_edge;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    while (scanf("%d",&n)&&n)
    {
        int a,b,c;
        int m = n*(n-1)/2;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b] = c;
            map[b][a] = c;
        }
        prim();
        printf("%d\n",ans);

    }
    return 0;
}

