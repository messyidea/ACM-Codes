/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/16 22:09:37
 |File Name: Apple Transportation.cpp
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
#define rep(i,n) for(int i=0;i<n;++i)
#define srep(i,n) for(int i=1;i<=n;++i)
#define inf 0x3f3f3f3f
#define maxn 205
#define maxe 205*205
using namespace std;
struct Edge{
    int u, v, nxt, cap, cost;
}edge[maxe];
int head[maxn];
int n;
int co[maxn];
int add;
int vn; 
int cost[maxn], in[maxn], pre[maxn];
bool vis[maxn];
void init(){
    add = 0; vn = n ; memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int w, int c){
    edge[add].u = u; edge[add].v = v; edge[add].cap = w; edge[add].cost= c;
    edge[add].nxt = head[u]; head[u] = add++;
    edge[add].u = v; edge[add].v = u; edge[add].cap = 0; edge[add].cost = -c;
    edge[add].nxt = head[v]; head[v] = add++;
}

bool spfa(int s, int e){
    queue<int> que;
    memset(cost, 0x3f3f3f3f, sizeof(cost));
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    cost[s] = 0; pre[s] = -1;
    que.push(s); vis[s] = true; in[s]++;
    while (!que.empty()){
        int u = que.front(); que.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].nxt){
            int v = edge[i].v;
            if (edge[i].cap > 0 && cost[v] > cost[u] + edge[i].cost){
                cost[v] = cost[u] + edge[i].cost; pre[v] = i;
                if (!vis[v]){
                    que.push(v); vis[v] = true; in[v]++;
                    if (in[v] > vn) return false;
                }
            }
        }
    }
    if (cost[e] < inf) return true;
    else return false;
}
int mincostmaxflow(int s, int e){
    int mincost = 0, maxflow = 0;
    while (spfa(s, e)){
        int flow = inf;
        for (int i = pre[e]; i != -1; i = pre[edge[i].u]){
            flow = min(flow, edge[i].cap);
        }
        maxflow += flow;
        for (int i = pre[e]; i != -1; i = pre[edge[i].u]){
            edge[i].cap -= flow;
            edge[i ^ 1].cap += flow;
        }
        mincost += cost[e] * flow;
    }
    return mincost;
}

int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n)!=EOF){
        init();
        int sum = 0;
        srep(i,n){
            scanf("%d",&co[i]);
            add_edge(0,i,co[i],0);
            add_edge(i,n+1,1,0);
            sum += co[i];
        }
        int avg = sum / n;
        srep(i,n){
            add_edge(i,n+2,avg,0);
        }
        int u,v,w;
        srep(i,n-1){
            scanf("%d%d%d",&u,&v,&w);
            u++;v++;
            add_edge(u,v,inf,w);
            add_edge(v,u,inf,w);
        }
        add_edge(n+1,n+2,sum-avg*n,0);
        printf("%d\n",mincostmaxflow(0,n+2));
    }
	return 0;
}

