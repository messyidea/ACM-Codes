/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/16 23:58:14
 |File Name: Cow Program.cpp
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
#define maxn 200005
int n;
long long ma[maxn];
long long mb[maxn][2];
bool vis[maxn][2];
long long dfs(int x,int type){
    if(mb[x][type]!=0) return mb[x][type];
    if(vis[x][type] == 1){
        mb[x][type] = -1;
        return -1;
    }
    vis[x][type] = true;
    if((type == 1 && x+ma[x]>n)||(type == 0 && x-ma[x] <= 0)){
        mb[x][type] = ma[x];
        return mb[x][type];
    }
    long long tp;
    if(type == 0){
        tp = dfs(x - ma[x],1);
    }
    else{
        tp = dfs(x + ma[x],0);
    }
    if(tp!=-1){
        mb[x][type] = tp + ma[x];
        return mb[x][type];
    }
    else{
        mb[x][type] = -1;
        return -1;
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    cin>>n;
    for(int i=2;i<=n;++i){
        cin>>ma[i];
    }
    memset(vis,false,sizeof(vis));
    memset(mb,0,sizeof(mb));
    for(int i=2;i<=n;++i){
        long long ans = dfs(i,0);
        if(ans == -1){
            cout<<-1<<endl;
        }
        else{
            cout<<ans + i - 1<<endl;
        }
    }
	return 0;
}

