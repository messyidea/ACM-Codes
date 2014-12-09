/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/11 20:26:18
 |File Name: mykosaraju.cpp
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
#define maxn 100
int v;
vector <int> G[maxn];
vector <int> rG[maxn];
vector <int> vs;
bool used[maxn];
int cmp[maxn];
void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v){
    used[v] = true;
    for(int i=0;i<G[v].size();++i){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}
void rdfs(int v,int k){
    used[v] = true;
    cmp[v] = k;
    for(int i=0;i<rG[v].size();++i){
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
}
int scc(){
    memset(used,false,sizeof(used));
    vs.clear();
    for(int i=0;i<v;++i){
        if(!used[i]) dfs(i);
    }
    memset(used,false,sizeof(used));
    int k = 1;
    for(int i=vs.size()-1;i>=0;--i){
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main() {
	//freopen("input.txt","r",stdin); 
    v = 6;
    for(int i=1;i<=6;++i){
        G[i].clear();
        rG[i].clear();
    }
    add_edge(1,3);
    add_edge(1,2);
    add_edge(2,4);
    add_edge(3,5);
    add_edge(3,4);
    add_edge(4,1);
    add_edge(4,6);
    add_edge(5,6);
    scc();
    for(int i=1;i<=v;++i){
        cout<<cmp[i]<<" ";
    }
    cout<<endl;
	return 0;
}

