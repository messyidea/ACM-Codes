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
int n;
int stop;
int cnt;
int visitnum;
int dfn[maxn];
int low[maxn];
bool instack[maxn];
int stap[maxn];
int belong[maxn];
#define mod  1000000007
vector<int>tree[maxn];
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
long long val[maxn];
long long ma[maxn];
long long mb[maxn];
#define inf 0x7fffffff
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%lld",&val[i]);
    int m;
    scanf("%d",&m);
    int a,b;
    while(m--){
        scanf("%d%d",&a,&b);
        tree[a].push_back(b);
    }
    solve();
    for(int i=1;i<=n;++i){
        ma[i] = inf;
    }
    for(int i=1;i<=n;++i){
        if(val[i] < ma[belong[i]]){
            ma[belong[i]] = val[i];
            mb[belong[i]] = 1;
        }
        else if(val[i] == ma[belong[i]]){
            mb[belong[i]] ++;
        }
    }
    long long sum = 0;
    long long nn = 1;
    for(int i=1;i<=cnt;++i){
        sum += ma[i];
        nn *= mb[i];
        nn%=mod;
    }
    printf("%lld %lld\n",sum,nn);
	return 0;
}

