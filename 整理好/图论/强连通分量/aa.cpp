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
#define maxn 2005
int n;
int m,a,b;
int stop;
int cnt;
int visitnum;
int dfn[maxn];
int low[maxn];
bool instack[maxn];
int stap[maxn];
int belong[maxn];
vector<int>tree[maxn];
vector<int>G[maxn];
void tarjan(int i){
    int j;
    dfn[i] = low[i] = ++visitnum;
    instack[i] = true;
    stap[++stop] = i;
    for(int k=0;k<tree[i].size();k++){
        j = tree[i][k];
        cout<<j<<endl;
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
int ma[maxn];
int mm[1005];
int vis[maxn];
int sum = 0;
#define inf 0x7fffffff
void dfs(int k,int t){
    for(int i=0;i<tree[k].size();++i){
        if(vis[tree[k][i]] != t){
            vis[tree[k][i]] = t;
            //cout<<"tree"<<" "<<tree[k][i]<<endl;
            sum += ma[tree[k][i]-n];
            //cout<<1<<endl;
            //cout<<"sum = "<<sum<<endl;
            dfs(tree[k][i],t);
        }
    }
}

int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;++i) tree[i].clear();
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            tree[a].push_back(b);
        }
        solve();
        
        for(int i=1;i<=n;++i){
        	cout<<belong[i]<<" ";
		}
		cout<<endl;
        
        for(int i=1;i<=cnt;++i){
            G[i].clear();
        }
        for(int i=1;i<=n;++i){
            ma[belong[i]] ++;
            G[belong[i]].push_back(i);
        }
        //cout<<22<<endl;
        for(int i=1;i<=cnt;++i){
            set <int> a;
            a.clear();
            for(int j=0;j<G[i].size();++j){
                for(int k=0;k<tree[G[i][j]].size();++k)
                    a.insert(belong[tree[G[i][j]][k]]);
            }
            set<int>::iterator it = a.begin();
            while(it!=a.end()){
            	//cout<<*it<<endl;
                tree[n+i].push_back(*(it) + n);
                it++;
            }
        }
        //cout<<tree[6][0]<<" "<<tree[7][0]<<" "<<tree[8][0]<<endl;
        //cout<<tree[6].size()<<" "<<tree[7].size()<<" "<<tree[8].size()<<endl;
        //cout<<11<<endl;
        //cout<<ma[1]<<" "<<ma[2]<<" "<<ma[3]<<endl;
        memset(vis,0,sizeof(vis));
        int maxx = 0;
        sum = 0;
        //cout<<cnt<<endl;
        for(int i=1;i<=cnt;++i){
            if(vis[i+n] == 0){
            	sum = ma[i];
            	vis[i+n] = i+n;
                dfs(n+i,n+i);
                //cout<<sum<<endl;
                if(sum > maxx) maxx = sum;
            }
        }
        printf("%d\n",maxx);    

    }
	return 0;
}

