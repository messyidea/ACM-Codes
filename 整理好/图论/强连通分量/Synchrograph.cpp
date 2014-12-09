/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/5 20:17:38
 |File Name: Synchrograph.cpp
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
#define maxn 1005
#define rep(i,n) for(int i=0;i<n;++i)
#define mset(l,i) memset(l,i,sizeof(l))
struct edge{
    int to,cap;
};
vector<edge> G[maxn];
vector<edge> GG[maxn];
bool ans[maxn];
int nn[maxn],low[maxn],dfn[maxn],stap[maxn],belong[maxn];
bool instack[maxn];
bool pos[maxn];
int n,m;
int visitnum,stop,cnt;
int a,b,c;
void add_edge(int from,int to ,int cap){
    G[from].push_back((edge){to,cap});
}
void addedge(int from,int to ,int cap){
    GG[from].push_back((edge){to,cap});
}
void tarjan(int i){
    int j;
    dfn[i] = low[i] = ++visitnum;
    instack[i] = true;
    stap[++stop] = i;
    for(int k = 0;k<GG[i].size();++k){
        edge& e = GG[i][k];
        j = e.to;
        int cap = e.cap;
        //if(cap == 0)
        //{
            if(!dfn[j]){
                tarjan(j);
                if(low[j] < low[i]) low[i] = low[j];
            }
            else if(instack[j] && dfn[j]<low[i]) low[i] = dfn[j];
        //}
    }
    if(dfn[i] == low[i]){
        cnt++;
        do{
            j = stap[stop--];
            instack[j] = false;
            belong[j] = cnt;
            nn[cnt]++;
        }
        while(j!=i);
    }
}
void solve(){
    stop = cnt = visitnum = 0;
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i);
    }
}
void solve2(int t){
    ans[t] = false;
    for(int i=0;i<G[t].size();++i){
        edge &e = G[t][i];
        if(ans[e.to]){
            solve2(e.to);
        }
    }
}

int main() {
	freopen("input.txt","r",stdin); 
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(pos,false,sizeof(pos));
        memset(ans,true,sizeof(ans));
        for(int i=1;i<=n;++i) G[i].clear();
        rep(i,m){
            scanf("%d%d%d",&a,&b,&c);
            /*if(a == b && c == 0){
                ans[a] = false;
                pos[a] = true;
            }
            add_edge(a,b,c);*/
            add_edge(a,b,c);
            if(!c){
                if(a != b) addedge(a,b,c);
                else{
                    pos[a] = true;
                    ans[a] = false;
                }
            }
        }
        mset(belong,0);
        mset(nn,0);
        mset(stap,0);
        solve();
        //for(int i=1;i<=n;++i) cout<<belong[i]<<" ";cout<<endl;
        for(int i=1;i<=n;++i){
            if(nn[belong[i]] > 1 || pos[i]){
                solve2(i);
            }
        }
        for(int i=1;i<=n;++i){
            printf("%d\n",ans[i]?1:0);
        }
        
    }

	return 0;
}

