
/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-23 13:33:13
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n,m,s;
int u,v,w;
vector <int> g[2505];
//pair<int,int> pa[25005];
int ww[25005];
int uu[25005],vv[25005];
bool vis[2505];
int tot = 0;
int to = 0;
int tot2;
pair<int,int> pq[25005];
map<pair<int,int>,int> mm;
void add_edge(int u,int v) {
    g[u].push_back(v); g[v].push_back(u);
}
void bfs() {
    int front = 0,rear = 0;
    pq[rear ++] = make_pair(s,0);
    vis[s] = true;
    pair<int,int> t;
    to = 0;
    while(front < rear) {
        t = pq[front ++];
        //cout<<"t.first == "<<t.first<<endl;
        //vis[t.first] = true;
        int u = t.first,v = t.second;
        for(int i=0;i<g[u].size();++i) {
            if(vis[g[u][i]]) continue;
            int aa = u,bb = g[u][i];
            if(aa > bb) swap(aa,bb);
            mm[MP(aa,bb)] = ww[to ++];
            //cout<<aa<<"    "<<bb<<"   "<<ww[to-1]<<endl;
            pq[rear ++] = MP(g[u][i],v + ww[to - 1]);
            vis[pq[rear - 1].first] = true;
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--) {
        scanf("%d %d %d",&n,&m,&s);
        mm.clear();
        for(int i=0;i<=n;++i) g[i].clear();
        memset(vis,false,sizeof(vis));
        tot = 0;tot2 = 0;
        rep(i,m) {
            scanf("%d %d %d",&uu[i],&vv[i],&w);
            add_edge(uu[i],vv[i]);
            ww[tot ++ ] = w;
        }
        sort(ww,ww + m);
        //rep(i,m) cout<<ww[i]<<"  ";cout<<endl;
        bfs();
        int ans;
        printf("Case %d:\n",cas ++);
        rep(i,m) {
            int aa = uu[i],bb = vv[i];
            if(aa > bb) swap(aa,bb);
            ans = mm[MP(aa,bb)];
            if(ans == 0) {
                ans = ww[to++];
            }
            printf("%d %d %d\n",uu[i],vv[i],ans);
        }
    }
	return 0;
}
