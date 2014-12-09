/***********************************************\
 |Author: YMC
 |Created Time: 2014/4/18 8:32:15
 |File Name: poj2449.cpp
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
#define N 1005
#define M 200100
#define INF 1<<29
int head[N],tail[N],dis[N];
int num[N];
int n,m;
int s,t,k;
bool vis[N];
struct node{
	int v,c,nxt;
}edge[M];
struct seg{
    int h,g,d;
    bool operator < (const seg a)const{
        return a.g + a.h < h+g;
    }
};
void add_edge(int u,int v,int c,int e){
	edge[e<<1].v = v;
	edge[e<<1].c = c;
	edge[e<<1].nxt = head[u];
	head[u] = e<<1;
	
	edge[e<<1|1].v = u;
	edge[e<<1|1].c = c;
	edge[e<<1|1].nxt = tail[v];
	tail[v] = e<<1|1;
}
void dij(){
	memset(vis,false,sizeof(vis));
    memset(dis,0x7F,sizeof(dis)); 
    dis[t] = 0;
    //vis[t] = true;
    for(int i=1;i<=n;++i){
        int mm = 0x7FFF;
        int pos = -1;
        for(int j=1;j<=n;++j){
            if(!vis[j] && mm > dis[j]){
                mm = dis[j];
                pos = j;
            }
        }
        if(pos == -1) break;
        vis[pos] = true;
        for(int j=tail[pos];j!=-1;j=edge[j].nxt){
        	int v = edge[j].v;
        	if(dis[v] > edge[j].c + dis[pos]) dis[v] = edge[j].c + dis[pos];
        }
    }
}

int astar(){
	memset(num,0,sizeof(num));
	seg tp,tp1,tp2;
	priority_queue<seg> pq;
	tp1.h = dis[s];
	tp1.g = 0;
	tp1.d = s;
	pq.push(tp1);
	while(!pq.empty()){
		tp = pq.top();
		pq.pop();
		num[tp.d] ++;
		if(num[tp.d] > k) continue;
		if(num[t] == k) return tp.g;
		for(int i=head[tp.d];i!=-1;i = edge[i].nxt){
			tp2.d = edge[i].v;
			tp2.g = tp.g + edge[i].c;
			tp2.h = dis[tp2.d];
			pq.push(tp2);
		}
		
	}
	return -1;
}

int main() {
	//freopen("input.txt","r",stdin);
    int a,b,c; 
    while(scanf("%d%d",&n,&m)!=EOF){
        memset( head,0xFF,sizeof(head) );  
        memset( tail,0xFF,sizeof(tail) );
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c,i);
        }
        scanf("%d%d%d",&s,&t,&k);
        if(s == t) k++;
       	dij();
        //for(int i=1;i<=n;++i) cout<<dis[i]<<" ";cout<<endl;
       	printf("%d\n",astar());

    }
	return 0;
}

