/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-29 12:19:56
 |File Name: Jump.cpp
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
#define maxn 100005 
#define maxm 30000005 
#define inf 0x3f3f3f3f 
struct Edge{ int u,v,cap,cost,x; }E[maxm]; 
int e,l[maxn]; 
inline void init(){ e=0; memset(l,-1,sizeof(l)); } 
inline void insert(int u,int v,int cap,int cost){ //单向边 
  E[e].u=u; E[e].v=v; E[e].cap=cap; E[e].cost= cost; E[e].x=l[u]; l[u]=e++; 
  E[e].u=v; E[e].v=u; E[e].cap=0  ; E[e].cost=-cost; E[e].x=l[v]; l[v]=e++; 
} 
int q[20*maxn],s,t, inq[maxn], dis[maxn],eid[maxn]; 
void min_cost_max_flow(int src,int sink,int &cap,int &cost){//0~n-1 
  cost=cap=0; 
  while( true ){ //不断增广 
    //begin spfa 
    for(int i=0;i<maxn;i++) dis[i]=inf; //-inf  最大费 
    s=t=0; q[t++]=src; inq[src]=1; dis[src]=0; 
    while(s<t){ 
      int u=q[s++]; inq[u]=0; 
      for(int p=l[u];p>=0;p=E[p].x){ 
        if( E[p].cap<=0 ) continue; 
        int v=E[p].v; 
        if( dis[v]>dis[u]+E[p].cost ){  //< 
          dis[v]=dis[u]+E[p].cost; eid[v]=p; 
          if( inq[v]==0 ){ 
            inq[v]=1; q[t++]=v; 
          } 
        } 
      } 
    } //end spfa 
    if( dis[sink]>=inf ) return;  //<=-inf 
    int c=inf; 
    for(int i=sink;i!=src;i=E[eid[i]].u) c=min(c,E[eid[i]].cap); 
    cost+=dis[sink]*c;  cap+=c; 
    for(int i=sink;i!=src;i=E[eid[i]].u) { 
      int p=eid[i];  E[p].cap-=c; E[p^1].cap+=c; 
    } 
  } 
}//*****************模板结束******************* 
int n,m,k;
char ss[150][150];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    srep(cas,T) {
        scanf("%d %d %d",&n,&m,&k);
        rep(i,n) {
            scanf("%s",ss[i]);
        }
        if(k < min(n,m)) {
            printf("Case %d : -1\n",cas);
            continue;
        }
        init();
        int src = n * m *2 + 5;
        int sink = src + 1;
        int ssrc = sink + 1;
        int ssink = ssrc + 1;
        insert(src,ssrc,k,0);
        insert(ssink,sink,k,0);
        rep(i,n) {
            rep(j,m) {
                insert(ssrc,i*m+j,1,0);
                insert(i*m+j,n*m+i*m+j,1,-100000);
                insert(n*m+i*m+j,ssink,1,0);
            }
        }
        rep(i,n) {
            rep(j,m) {
                for(int k=j+1;k<m;++k) {
                    int val =-( k - j - 1);
                    if(ss[i][k] == ss[i][j]) val += ss[i][j] - '0';
                    insert(n*m + i*m+j,i*m + k,inf,-val);
                }
                for(int k = i+1;k<n;++k) {
                    int val =-( k - i - 1);
                    if(ss[k][j] == ss[i][j]) val += ss[i][j] - '0';
                    insert(n*m + i*m+j,k*m+j,inf,-val);
                }
            }
        }
        insert(ssrc,ssink,inf,0);       //important
        int cap,cost;
        min_cost_max_flow(src,sink,cap,cost);
        int ans = -cost - 100000*n*m;
        if(ans < 0) ans = -1;
        printf("Case %d : %d\n",cas,ans);
    }
	return 0;
}



