/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-28 16:28:41
 |File Name: Firing.cpp
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
#define maxn 870010
#define maxm 4400000 
#define inf 0x3fffffff 
struct Edge{ int u,v,cap,cost,x; }E[maxm]; 
int e,l[maxn]; 
int n,m;
inline void init(){ 
    e=0; 
    memset(l,-1,sizeof(l)); 
} 
inline void insert(int u,int v,int cap,int cost){ //单向边 
  E[e].u=u; E[e].v=v; E[e].cap=cap; E[e].cost= cost; E[e].x=l[u]; l[u]=e++; 
  E[e].u=v; E[e].v=u; E[e].cap=0  ; E[e].cost=-cost; E[e].x=l[v]; l[v]=e++; 
} 
int q[20*maxn],s,t, inq[maxn], dis[maxn],eid[maxn]; 
void min_cost_max_flow(int src,int sink,int &cap,int &cost){//0~n-1 
  cost=cap=0; 
  while( true ){ //不断增广 
    //begin spfa 
    for(int i=0;i<maxn;i++) dis[i]=-inf; //-inf  最大费 
    s=t=0; q[t++]=src; inq[src]=1; dis[src]=0; 
    while(s<t){ 
      int u=q[s++]; inq[u]=0; 
      for(int p=l[u];p>=0;p=E[p].x){ 
        if( E[p].cap<=0 ) continue; 
        int v=E[p].v; 
        if( dis[v]<dis[u]+E[p].cost ){  //< 
          dis[v]=dis[u]+E[p].cost; eid[v]=p; 
          if( inq[v]==0 ){ 
            inq[v]=1; q[t++]=v; 
          } 
        } 
      } 
    } //end spfa 
    if( dis[sink]<=-inf ) return;  //<=-inf 
    int c=inf; 
    for(int i=sink;i!=src;i=E[eid[i]].u) c=min(c,E[eid[i]].cap); 
    cost+=dis[sink]*c;  cap+=c; 
    for(int i=sink;i!=src;i=E[eid[i]].u) { 
      int p=eid[i];  E[p].cap-=c; E[p^1].cap+=c; 
    } 
  } 
}//*****************模板结束******************* 
int da[606][606];
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    while(~scanf("%d",&n)) {
        init();
        int src = n*n*2 + 5;
        int sink = src + 1;
        insert(src,0,2,0);
        rep(i,n) {
            rep(j,n) {
                scanf("%d",&da[i][j]);
                if((i == 0 && j == 0) || (i == n-1 && j == n-1)) {
                    insert(i*n+j,n*n + i*n+j,2,0);
                    continue;
                }
                insert(i*n+j,n*n + i*n+j,1,da[i][j]);
            }
        }
        rep(i,n) {
            rep(j,n) {
                if(i<n-1) insert(i*n+j+n*n,(i+1)*n+j,inf,0);
                if(j<n-1) insert(i*n+j+n*n,i*n+j+1,inf,0);
            }
        }
        insert(n*n + n*n-1,sink,2,0);
        int cap,cost;
        min_cost_max_flow(src,sink,cap,cost);
        cost += da[0][0] + da[n-1][n-1];
        printf("%d\n",cost);
    }
	return 0; 
}

