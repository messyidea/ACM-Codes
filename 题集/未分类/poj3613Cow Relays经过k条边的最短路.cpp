/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/17 23:43:28
 |File Name: poj3613Cow Relays经过k条边的最短路.cpp
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
#define N 205
#define inf 0x3f3f3f3f
int ma[N][N];
int n,t,s,e;
int l,u,v,uu,vv;
int vis[1005];
int pos;
void floyd(int c[][N],int a[][N],int b[][N]) {
    for(int i=0;i<pos;++i){
        for(int j=0;j<pos;++j){
            for(int k=0;k<pos;++k){
                if(c[j][k] > a[j][i] + b[i][k]) c[j][k] = a[j][i] + b[i][k];
            }
        }
    }
}
int tp[N][N];
int mm[N][N];
int ans[N][N];
void clear(int a[][N]) {
    for(int i=0;i<pos;++i ) {
        for(int j=0;j<pos ;++j) {
            a[i][j] = inf;
        }
    }
}
void copy(int a[][N],int b[][N]) {
    for(int i=0;i<pos;++i){
        for(int j=0;j<pos;++j){
            a[i][j] = b[i][j];
        }
    }
}
void solve(int n){
    //clear(tp);
    //copy(mm,ma);
    while(n){
        //clear(tp);
        if(n & 1) {
            //floyd(tp,mm,ma);
            floyd(tp,ans,ma);
            //copy(mm,tp);
            copy(ans,tp);
            clear(tp);
        }
        floyd(tp,ma,ma);
        copy(ma,tp);
        clear(tp);
        n >>= 1;
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d %d %d",&n,&t,&s,&e)) {
        memset(vis,-1,sizeof(vis));
        rep(i,N) rep(j,N) ma[i][j] = tp[i][j] = ans[i][j] = inf;
        rep(i,N) ans[i][i] = 0;
        pos = 0;
        rep(i,t){
            scanf("%d %d %d",&l,&u,&v);
            if(u == v) continue;
            if(vis[u] == -1) vis[u] = pos ++;
            if(vis[v] == -1) vis[v] = pos ++;
            if(ma[vis[v]][vis[u]] > l){
                ma[vis[v]][vis[u]] = l;
                ma[vis[u]][vis[v]] = l;
            }
        }
        solve(n);
        printf("%d\n",ans[vis[s]][vis[e]]);
    }
	return 0;
}

