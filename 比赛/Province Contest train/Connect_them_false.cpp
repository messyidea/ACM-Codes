/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/14 20:30:14
 |File Name: Connect_them.cpp
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
int da[105][105];
int dis[105];
bool vis[105];
int pre[105];
pair<int,int> pp[105];
int tot;
int prim() {
    tot = 0;
    memset(vis,false,sizeof(vis));

    vis[0] = true;
    rep(i,n) {
        dis[i] = da[0][i];
        pre[i] = 0;
    }
    tot = 0;
    int ans = 0;
    int mindis,pos;
    int tp;
    
    for(int ii=1;ii<n;++ii) {
        mindis = inf;pos = -1;
        for(int i = 0;i<n;++i) {
            if(vis[i]) continue;
            if(dis[i] < mindis) {
                mindis = dis[i];
                pos = i;
            }
        }
        if(mindis >= inf) return -1;
        vis[pos] = true;
        ans += mindis;
        pp[tot ++] = MP(min(pos,pre[pos]),max(pos,pre[pos]));
        for(int i=0;i<n;++i) {
            if(vis[i]) continue;
            //dis[i] = min(dis[i],dis[pos] + da[pos][i]);
            if(dis[i] > dis[pos] + da[pos][i]) {
                dis[i] = dis[pos] + da[pos][i];
                pre[i] = pos;
            }
        }
    }
    sort(pp,pp+tot);
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        rep(i,n) {
            rep(j,n) {
                scanf("%d",&da[i][j]);
                if(da[i][j] == 0) da[i][j] = inf;
            }
        }
        int ans = prim();
        if(ans == -1)
            printf("%d\n",ans);
        else {
            printf("%d %d",pp[0].first+1,pp[0].second+1);
            for(int i=1;i<tot;++i) {
                printf(" %d %d",pp[i].first+1,pp[i].second+1);
            }
            puts("");
        }
    }
	return 0;
}

