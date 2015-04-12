
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-12 14:09:30
 |File Name: c.cpp
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
int ma[10][10];
int tot, n;
int mb[150000][10];
int da[10];
bool vis[10];
int mc[10];
int temp[10];

void dfs(int now,int d) {
    temp[d] = now;
    int ta[10];
    int oot = 0;
    if(d == n) {
        srep(i,n) {
            mb[tot][i] = temp[i];
        }
        tot++;
        return ;
    }
    
    for(int i=0;i<n;++i) {
        if(vis[da[i]]) continue;
        else {
            if(ma[now][da[i]] != 0) {
                int tttt = ma[now][da[i]];
                if(mc[tttt] == 1 && !vis[tttt]) {
                    continue;
                } else if(mc[tttt] == 1 && vis[tttt]) {
                    ta[oot ++] = da[i];
                    continue;
                } 
            } else {
                ta[oot ++] = da[i];
            }
        }
    }
    sort(ta,ta+oot);
    rep(i,oot) {
        vis[ta[i]] = true;
        dfs(ta[i],d+1);
        vis[ta[i]] = false;
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    //init
    ma[1][7] = 4; ma[7][1] = 4;
    ma[1][3] = 2; ma[3][1] = 2;
    ma[1][9] = 5; ma[9][1] = 5;
    ma[2][8] = 5; ma[8][2] = 5;
    ma[3][9] = 6; ma[9][3] = 6;
    ma[3][7] = 5; ma[7][3] = 5;
    ma[4][6] = 5; ma[6][4] = 5;
    ma[7][9] = 8; ma[9][7] = 8;
    int T;
    scanf("%d",&T);
    while(T--) {
        tot = 0;
        memset(mc,0,sizeof(mc));
        scanf("%d",&n);
        rep(i,n) {
            scanf("%d",&da[i]);
            mc[da[i]] = 1;
        }
        sort(da,da+n);
        memset(vis,false,sizeof(vis));
        rep(i,n) {
            memset(vis,false,sizeof(vis));
            vis[da[i]] = true;
            dfs(da[i],1);
        }
        printf("%d\n",tot);
        rep(i,tot) {
            printf("%d",mb[i][1]);
            for(int j=2;j<=n;++j) {
                printf(" %d",mb[i][j]);
            }
            puts("");
        }
    }

	return 0;
}
