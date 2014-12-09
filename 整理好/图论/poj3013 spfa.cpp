/***********************************************\
 |Author: YMC
 |Created Time: 2014/4/21 22:25:05
 |File Name: poj3013.cpp
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
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
struct node{
    int v,nxt;
    long long c;
}edge[200000];
int head[100005];
int value[50005];
long long dis[50005];
long long que[50005];
bool inq[50005];
void add_edge(int a,int b,int c,int i){
    edge[i<<1].v = a;
    edge[i<<1].c = c;
    edge[i<<1].nxt = head[b];
    head[b] = i<<1;

    edge[i<<1|1].v = b;
    edge[i<<1|1].c = c;
    edge[i<<1|1].nxt = head[a];
    head[a] = i<<1|1;
}
//--------TE
/*void dij(){
    for(int i=0;i<=n;++i) dis[i] = inf;
    //cout<<int(inf)<<endl;
    memset(vis,false,sizeof(vis));
    dis[1] = 0;
    for(int i=1;i<=n;++i){
        int minn = inf,pos = 0;
        for(int j=1;j<=n;++j){
            if(!vis[j] && minn > dis[j]){
                minn = dis[j];
                pos = j;
            }
        }
        if(pos == 0) return ;
        vis[pos] = true;
        for(int tp = head[pos];tp!=-1;tp = edge[tp].nxt){
            int vv = edge[tp].v;
            if(dis[vv] > edge[tp].c + dis[pos]){
                dis[vv] = edge[tp].c + dis[pos];
            }
        }
    }

}*/

long long spfa(){
    //for(int i=0;i<=n;++i) dis[i] = inf;
    memset(inq,false,sizeof(inq));
    memset(dis,-1,sizeof(dis));
    int front = 0,rear = 0;
    que[rear++] = 1;
    dis[1] = 0;
    inq[1] = true;
    while(front < rear){
        int tp = que[front++];
        if(front == 50005) front = 0;
        //inq[tp] = false;
        for(int i = head[tp];i!=-1;i = edge[i].nxt){
            int vv = edge[i].v;
            if(dis[vv] > dis[tp] + edge[i].c || dis[vv]==-1){
                dis[vv] = dis[tp] + edge[i].c;
                if(!inq[vv]){
                    inq[vv] = true;
                    que[rear++] = vv;
                    if(rear == 50005) rear = 0;
                }
            }
        }
        inq[tp] = false;
    }
    long long ans = 0;
    for(int i=2;i<=n;++i){
        if(dis[i] == -1){ return 0;}
        else ans += dis[i]*value[i];
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int a,b,c;
    while(scanf("%d",&T)!=EOF){
        while(T--){
            memset(head,-1,sizeof(head));
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;++i){
                scanf("%d",&value[i]);
            }
            for(int i=0;i<m;++i){
                scanf("%d%d%d",&a,&b,&c);
                add_edge(a,b,c,i);
                //add_edge(b,a,c,i);
            }
            long long sum = spfa();
            if(n == 0 || n == 1){
                printf("0\n");
                continue;
            }
            if(sum == 0){
                printf("No Answer\n");
            }
            else {
                printf("%lld\n",sum);
            }
        }
    }
	return 0;
}

