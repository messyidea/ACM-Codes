/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/5 15:04:56
 |File Name: 食物链.cpp
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
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;
int n,m;
int ans;
int rank[50005];
int fa[50005];
void init(int n)
{
    for (int i=0;i<=n;++i)
    {
        fa[i] = i;
        rank[i] = 0;
    }
}
int find(int a)
{
    if (a == fa[a]) return a;
    int f = fa[a];
    fa[a] = find(fa[a]);
    rank[a] = (rank[a] + rank[f])%3;
    return fa[a];
}
void merge(int a,int b,int r)
{
	r--;
    int x =find(a);
    int y = find(b);
    if (x == y) return ;
    fa[x] = y;
    rank[x] = (rank[b]-rank[a]+r+3)%3;
    return ;

}
bool judge(int a,int b,int d)
{
    if (a > n || b > n ||(a == b && d == 2)) return false;
    int x = find(a);
    int y = find(b);
    if (fa[x] != fa[y]) return true;
    if (rank[a]==(d-1+rank[b])%3) return true;
    else return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int a,b,c;
    scanf("%d%d",&n,&m);

    ans = 0;
    init(n);
    while (m --)
    {
        scanf("%d%d%d",&a,&b,&c);
        if (!judge(b,c,a))
        {
            ans++;
        }
        else
        {
            merge(b,c,a);
        }
    }
    printf("%d\n",ans);

    return 0;
}
