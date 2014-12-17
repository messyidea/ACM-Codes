/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/10 22:36:04
 |File Name: tarjan.cpp
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
#define maxn 100005
#define mod  1000000007
int n;

vector<int>tree[maxn];
int stop;
int cnt;
int visitnum;
int dfn[maxn];
int low[maxn];
bool instack[maxn];
int stap[maxn];
int belong[maxn];
void tarjan(int i){
    int j;
    dfn[i] = low[i] = ++visitnum;
    instack[i] = true;
    stap[++stop] = i;
    for(int k=0;k<tree[i].size();k++){
        j = tree[i][k];
        if(!dfn[j]){
            tarjan(j);
            if(low[j]<low[i]) low[i] = low[j];
        }
        else if(instack[j] && dfn[j]<low[i]) low[i] = dfn[j];
    }
    if(dfn[i] == low[i]){
        cnt++;
        do{
            j = stap[stop--];
            instack[j] = false;
            belong[j] = cnt;
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
//long long val[maxn];
//long long ma[maxn];
//long long mb[maxn];
#define inf 0x7fffffff
int main() {
	//freopen("input.txt","r",stdin); 
    n = 6;
    tree[1].push_back(3);
    tree[1].push_back(2);
    tree[2].push_back(4);
    tree[3].push_back(5);
    tree[3].push_back(4);
    tree[4].push_back(1);
    tree[4].push_back(6);
    tree[5].push_back(6);
    solve();
    for(int i=1;i<=n;++i){
        cout<<belong[i]<<" ";
    }
    cout<<endl;

	return 0;
}

