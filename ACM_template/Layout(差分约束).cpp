/***********************************************\
 |Author: YMC
 |Created Time: 2014-7-15 14:01:14
 |File Name: a.cpp
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
#define maxn 1005
using namespace std;
int n,ml,md;
bool inq[maxn];
int cnt[maxn];
int d[maxn];
struct edge{
    int v,cap;
};
vector <edge> ma[maxn];
void add_edge(int u,int v,int cap){
    edge e;e.v = v;e.cap = cap;
    ma[u].push_back(e);
}
bool spfa(){
    queue<int> Q;
    memset(inq,0,sizeof(inq));
    memset(cnt,0,sizeof(cnt));
    d[1] = 0;inq[1] = true;cnt[1] = 1; Q.push(1);
    for(int i=2;i<=n;++i) {
        d[i] = inf;inq[i] = false;cnt[i] = 0;
    }
    while(!Q.empty()){
        int u = Q.front();Q.pop();
        inq[u] = false;
        for(int i=0;i<ma[u].size();++i){
            edge e = ma[u][i];
            if(d[e.v] > d[u] + e.cap){
                d[e.v] = d[u] + e.cap;
                if(!inq[e.v]){
                    inq[e.v] = true;
                    Q.push(e.v);
                    if(++cnt[e.v] > n) return true;
                }
            }
        }
    }
    return false;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int u,v,cap;
    while(scanf("%d%d%d",&n,&ml,&md)!=EOF){
        while(ml -- ){
            scanf("%d%d%d",&u,&v,&cap);
            if(u > v) swap(u,v);
            add_edge(u,v,cap);
        }
        while(md -- ){
            scanf("%d%d%d",&u,&v,&cap);
            if(u < v) swap(u,v);
            add_edge(u,v,-cap);
        }
        if(spfa()){
            puts("-1");
        } 
        else{
            if(d[n] == inf) puts("-2");
            else printf("%d\n",d[n]);
        }
    }
	return 0;
}

