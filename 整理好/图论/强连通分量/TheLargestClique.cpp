/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/5 18:22:53
 |File Name: TheLargestClique.cpp
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
#define mset(i,a) memset(i,a,sizeof(i))
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
#define maxn 2005
int n,m;
int a,b;
struct edge{
    int to;int rev;
};
vector<edge> G[maxn];
int stap[maxn],dfn[maxn],low[maxn],belong[maxn],mm[maxn],nn[maxn];
int stop,cnt,visitnum;
bool instack[maxn];
void add_edge(int from,int to){
    G[from].push_back((edge){to,G[to].size()});
    //G[to].push_back((edge){from,G[from].size()-1});
}
vector<int> D[maxn];
void tarjan(int i){
    int j;
    dfn[i] = low[i] = ++visitnum;
    instack[i] = true;
    stap[++stop] = i;
    for(int k = 0;k<G[i].size();++k){
        edge& e = G[i][k];
        j = e.to;
        if(!dfn[j]){
            tarjan(j);
            if(low[j] < low[i]) low[i] = low[j];
        }
        else if(instack[j] && dfn[j]<low[i]) low[i] = dfn[j];
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
void Build(){
    for(int i=1;i<=n;++i){
        for(int j=0;j<G[i].size();++j){
            edge& e = G[i][j];
            int k = e.to;
            if(belong[i] != belong[k]) D[belong[i]].push_back(belong[k]);
        }
    }
}
int dfs2(int u){
    if(mm[u]!=-1) return mm[u];
    int num = 0;
    for(int i=0;i<D[u].size();++i){
        int v = D[u][i];
        num = max(dfs2(v),num);
    }
    mm[u] = num + nn[u];
    return mm[u];
}

int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        mset(belong,0);
        mset(stap,0);
        mset(instack,false);
        mset(mm,-1);
        mset(nn,0);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i) G[i].clear();
        rep(i,m){
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }
        solve();
        //for(int i=1;i<=n;++i) cout<<belong[i]<<" ";cout<<endl;
        //for(int i=1;i<=n;++i) cout<<nn[i]<<" ";cout<<endl;
        for(int i=1;i<=cnt;++i) D[i].clear();
        Build();
        int ans = 0;
        for(int i=1;i<=cnt;++i){
            if(mm[i] == -1){
                ans = max(ans,dfs2(i));
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

