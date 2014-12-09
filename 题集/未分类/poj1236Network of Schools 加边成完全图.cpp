/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/18 22:55:04
 |File Name: poj1236Network of Schools 加边成完全图.cpp
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
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
#define N 105
int n,t;
int chu[N];
int ru[N];
vector <int> tree[N];
vector <int> tree2[N];
int stop;
int cnt;
int visitnum;
int dfn[N];
int low[N];
bool instack[N];
int stap[N];
int belong[N];
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
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)) {
        srep(i,n){
            while(tree){
                scanf("%d",&t);
                if(t == 0) break;
                tree[i].push_back(t);
            }
        }
        solve();
        if(cnt == 1){
            cout<<1<<"\n"<<0<<"\n";
            continue;
        }
        //srep(i,n) cout<<i<<" "<<belong[i]<<"\n";
        memset(chu,0,sizeof(chu[0])*(n+1));
        memset(ru,0,sizeof(ru[0])*(n+1));
        for(int i=1;i<=n;++i){
            int s = tree[i].size();
            rep(j,s){
                if(belong[i] == belong[tree[i][j]]) continue; 
                tree2[belong[i]].push_back(belong[tree[i][j]]);
                chu[belong[i]] ++;
                ru[belong[tree[i][j]]]++;
            }
        }
        //cout<<cnt<<endl;
        int ans1 = 0,ans2 = 0;
        for(int i=1;i<=cnt;++i) if(ru[i] == 0) ans1 ++;
        for(int i=1;i<=cnt;++i) if(chu[i] == 0) ans2 ++;
        cout<<ans1<<"\n"<<max(ans1,ans2)<<"\n";
    }
	return 0;
}

