
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cassert>
#include <vector>                              
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define INF 1000000000000000000ll
#define inf 1000000000
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007

const int N = 2005;

int d, n;
int a[N];
int ans = 0;
int cnt[N];
vector < int > g[N];

void dfs(int v, int id, int p = -1){
    cnt[v] = 1;
    for(int j = 0;j < g[v].size();++ j){
        int to = g[v][j];
        if(a[to] > a[id] || to == p)
            continue;
        if((a[to] == a[id] && to > id) || (a[to] < a[id] && a[id] - a[to] <= d)){
            dfs(to, id, v);
            cnt[v] = (cnt[v] * 1ll * (cnt[to] + 1)) % mod;
        }
    }
}

int main(){ 
    #ifndef ONLINE_JUDGE
    freopen ("in","r",stdin);
    freopen ("out","w",stdout);
    #endif
    scanf("%d%d",&d, &n);
    for(int i = 1;i <= n;++ i)
        scanf("%d", &a[i]);
    for(int i = 1;i < n;++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1;i <= n;++ i){
        memset(cnt, 0, sizeof cnt);
        dfs(i, i);
        ans = (ans + cnt[i]) % mod;
    }
    printf("%d\n", ans);
    return 0;
}
