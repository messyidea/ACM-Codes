/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/19 23:34:55
 |File Name: 不要62.cpp
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
#define REP(i,n) for(int i=0;i<n;++i)
#define ll long long
ll dp[20][2];
ll num[20];
using namespace std;
ll dfs(int cur,int mask,bool limit){
    if(cur < 0) return 1;
    if(!limit && dp[cur][mask] != -1) return dp[cur][mask];
    int up = limit ? num[cur] : 9;
    ll ret = 0;
    for(int j=0;j<=up;++j){
        if(j == 4) continue;
        if(mask && j == 2) continue;
        if(j!=6){
            ret += dfs(cur-1,0,j==up && limit);
        }
        else{
            ret += dfs(cur-1,1,j==up && limit);
        }
    }
    if(!limit) dp[cur][mask] = ret;
    return ret;
}
ll solve(ll n){
    int len = 0;
    memset(dp,-1,sizeof(dp));
    while(n){
        num[len++] = n%10;
        n /= 10;
    }
    return dfs(len-1,0,true);
}
int main() {
	//freopen("input.txt","r",stdin); 
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0) break;
        printf("%d\n",(int)(solve(m) - solve(n-1)));
    }
	return 0;
}

