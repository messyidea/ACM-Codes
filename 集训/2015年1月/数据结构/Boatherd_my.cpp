/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-21 12:57:50
 |File Name: 树分治.cpp
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
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
const int N = 10010;
vector <pair<int,int> > g[N];
int root,size;
int dep[N],f[N],s[N],d[N];
bool vis[N];
int n,k,tot;
int ans;
int kk;
void getroot(int now,int fa) {
    int u,l;
    s[now] = 1;f[now] = 0;
    for(int i = 0; i < g[now].size(); ++i) {
        u = g[now][i].first; l = g[now][i].second;
        if(u == fa || vis[u]) continue;
        getroot(u,now);
        s[now] += s[u];
        f[now] = max(f[now],s[u]);
    }
    f[now] = max(f[now],size - s[now]);
    if(f[now] < f[root]) root = now;
}
void getdep(int now,int fa) {
    int u,v;
    dep[tot ++] = d[now];
    s[now] = 1;
    for(int i = 0;i < g[now].size(); ++i) {
        u = g[now][i].first; v = g[now][i].second;
        if(vis[u] || u == fa) continue;
        d[u] = d[now] + v;
        getdep(u,now);
        s[now] += s[u];
    }
}
int cal(int now,int len) {
    int u,v;
    tot = 0;
    d[now] = len;
    getdep(now,0);
    sort(dep,dep + tot);
    int ret = 0;
    int l = 0,r = tot - 1;
    while(l < r) {
        if(dep[l] + dep[r] < kk) {
            l ++;
        } else if(dep[l] + dep[r] > kk) {
            r --;
        } else {
            if(dep[l] == dep[r]) {
                int t = r - l + 1;
                ret += t * (t-1) / 2;
                break;
            }
            int aa = 0,bb = 0;
            while(dep[l+1] == dep[l]) l++,aa++;
            while(dep[r-1] == dep[r]) r--,bb++;
            l ++;r --;
            aa ++;bb ++;
            ret += aa * bb;
        }
    }
    return ret;
}
void solve(int now) {
    int u,v;
    ans += cal(now,0);
    vis[now] = true;
    for(int i = 0;i < g[now].size(); ++i) {
        u = g[now][i].first; v = g[now][i].second;
        if(!vis[u]) {
            ans -= cal(u,v);
            size = s[u];
            root = 0; f[0] = size;
            getroot(u,0);
            solve(root);
        }
    }
}
int que[105];
int to;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)) {
       if(n == 0) break;
       ans = 0;
       for(int i = 0;i <= n; ++i) g[i].clear();
       memset(vis,false,sizeof(vis));
       int u,v,l;
       for(int i=1;i<=n;++i) {
           while(true) {
               scanf("%d",&u);
               if(u == 0) break;
               else {
                   scanf("%d",&v);
                   g[i].push_back(MP(u,v));
                   g[u].push_back(MP(i,v));
               }
           }
       }
       while(true) {
            scanf("%d",&u);
            if(u == 0) break;
            memset(vis,false,sizeof(vis));
            ans = 0;
            kk = u;
            size = n;
            root = n; f[root] = n;
            getroot(1,n);
            solve(root);
            if(ans > 0) puts("AYE");
            else puts("NAY");
       }
       puts(".");
    }
	return 0;
}

