
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAXN 200005
#define MAXL 20
using namespace std ;
typedef long long LL ;

int N, M, Q, P ;
int fa[MAXN] ;
int deep[MAXN], go[MAXN][MAXL] ;
int q[MAXN][2] ;
int st[MAXN], ed[MAXN] ;
vector<int> son[MAXN] ;

int find(int x)
{
    if(fa[x] == x) return x ;
    return fa[x] = find(fa[x]) ;    
}

void Dfs(int x)
{
    int i, tmp ;
    for(i = 1; i <= 18; i ++)
        go[x][i] = go[go[x][i-1]][i-1] ;
    for(i = 0; i < son[x].size(); i ++)
    {
        tmp = son[x][i] ;
        deep[tmp] = deep[x]+1 ;
        go[tmp][0] = x ;
        Dfs(tmp) ;
    }
}
int lca(int a, int b)
{
    if(deep[a] < deep[b]) swap(a, b) ;
    int i ;
    for(i = 18; i >= 0; i --)
        if(deep[a]-(1<<i) >= deep[b])
            a = go[a][i] ;
    if(a == b) return a ;
    for(i = 18; i >= 0; i --)
        if(go[a][i] != go[b][i])
            a = go[a][i], b = go[b][i] ;
    return go[a][0] ;
}

int main()
{
    int i, j ;
    int type, fr, to ;
    //freopen("1.in", "r", stdin) ;
    scanf("%d %d", &N, &M) ;
    for(i = 1; i <= N; i ++)
        fa[i] = i ;
    for(i = 1; i <= M; i ++)
    {       
        scanf("%d", &type) ;
        if(type == 1)
        {
            scanf("%d %d", &fr, &to) ;
            fa[fr] = to, son[to].push_back(fr) ;    //son
        }
        else if(type == 2)
        {
            P ++ ;
            scanf("%d", &fr) ;
            st[P] = fr, ed[P] = find(fr) ;
        }
        else
        {
            Q ++ ;
            scanf("%d %d", &q[Q][0], &q[Q][1]) ;
        }
    }
    for(i = 1; i <= N; i ++)
        if(fa[i] == i) Dfs(i) ; 
    for(i = 1; i <= Q; i ++)
    {
        fr = q[i][0], to = st[q[i][1]] ;
        if(find(fr) != find(to) || lca(fr, to) != fr) 
            printf("NO\n") ;
        else if(deep[ed[q[i][1]]] > deep[fr])
            printf("NO\n") ;
        else printf("YES\n") ;
    }
    //system("pause") ;
    return 0 ;
}
