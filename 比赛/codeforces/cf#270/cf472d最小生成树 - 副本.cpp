/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/29 14:23:49
 |File Name: d.cpp
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
int n;
ll ma[2005][2005];
struct Edge{
    int u,v;
    ll dis;
    bool operator < (Edge a) const {
        return dis < a.dis;
    }
}edge[4000005];
int f[2005];
ll ds[2005];
bool vis[2005];
int tot;
vector <int> vv[2005];
void init(){
    srep(i,n) f[i] = i;
}
int find(int a){
    return f[a] = f[a] == a?a:find(f[a]);
}
void kru(){
    tot = 0;
    srep(i,n){
        for(int j=i+1;j<=n;++j){
            Edge tt;
            tt.u = i,tt.v = j,tt.dis = ma[i][j];
            edge[tot ++] = tt;
        }
    }
    sort(edge,edge + tot);
    init();
    int t = 1;
    for(int i=0;i<tot;++i){
        Edge e = edge[i];
        int aa = find(e.u);
        int bb = find(e.v);
        if(aa != bb) {
            f[aa] = bb;
            vv[e.u].push_back(e.v);
            vv[e.v].push_back(e.u);
            t ++;
            if(t == n) return ;
        }
    }
}
void dfs(int u,int fa,ll now){
    for(int i=0;i<vv[u].size();++i){
        if(vv[u][i] != fa){
            ds[vv[u][i]] = now + ma[u][vv[u][i]];
            dfs(vv[u][i],u,ds[vv[u][i]]);
        }
    }
}
bool isok(){
    for(int i=1;i<=n;++i){
        memset(ds,0,sizeof(ds));
        memset(vis,0,sizeof(vis));
        dfs(i,-1,0);
        srep(j,n){
            if(ma[i][j] != ds[j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&n);
    tot = 0;
    bool fg = true;
    memset(ma,0,sizeof(ma));
    srep(i,n){
        srep(j,n){
            scanf("%I64d",&ma[i][j]);
            if(ma[j][i] != 0 && ma[i][j] != ma[j][i]) fg = false;
            if(i != j && ma[i][j] == 0) fg = false;
        }
        if(ma[i][i] != 0) fg = false;
    }
    if(!fg){
        puts("NO");
        return 0;
    }
    kru();
    if(isok()){
        puts("YES");
    } else {
        puts("NO");
    }
	return 0;
}

