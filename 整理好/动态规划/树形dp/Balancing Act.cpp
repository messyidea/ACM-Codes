/***********************************************\
 |Author: YMC
 |Created Time: 2014/6/1 0:17:02
 |File Name: Balancing Act.cpp
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

using namespace std;
#define N 20005
#define inf 1<<29
int n;
struct node{
    int v,nxt;
}edge[N<<1];
int head[N<<1];
int son[N],self[N];
bool vis[N];
void add_edge(int a,int b,int e){
    edge[e<<1].v = a;
    edge[e<<1].nxt = head[b];
    head[b] = e<<1;
    edge[e<<1|1].v = b;
    edge[e<<1|1].nxt = head[a];
    head[a] = e<<1|1;
}
void dfs(int rt){
    self[rt] = 1;
    vis[rt] = true;
    for(int tp = head[rt];tp != -1;tp = edge[tp].nxt){
        if(!vis[edge[tp].v]){
            dfs(edge[tp].v);
            self[rt] += self[edge[tp].v];
            if(son[rt] < self[edge[tp].v]){
                son[rt] = self[edge[tp].v];
            }
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset( head,-1,sizeof(head) );
        for(int i=0;i<n-1;++i){
            scanf("%d%d",&a,&b);
            add_edge(a,b,i);
        }
        memset(vis,false,sizeof(vis));
        memset(son,0,sizeof(son));
        dfs(1);
        //for(int i=1;i<=7;++i) cout<<self[i]<<"   "<<son[i]<<endl;
        int p = -1;
        int ans = inf;
        for(int i=1;i<=n;++i){
            int tmx = max(self[1] - self[i],son[i]);
            if(ans > tmx){
                ans = tmx;
                p = i;
            }
        }
        printf("%d %d\n",p,ans);
    }
	return 0;
}

