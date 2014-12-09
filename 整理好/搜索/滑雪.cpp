/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/14 21:48:22
 |File Name: 滑雪.cpp
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
int n,m;
int sum;
int ma[105][105];
int dp[105][105];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
#define inf 1<<29
bool check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}
int dfs(int ii,int jj){
	if(dp[ii][jj] != -1) return dp[ii][jj];
    bool flag = false;
    for(int i=0;i<4;++i){
        int x = ii+dx[i];
        int y = jj+dy[i];
        if(check(x,y) && ma[x][y] < ma[ii][jj]){
            dp[ii][jj] = max(dp[ii][jj],1+dfs(x,y));
            flag = true;
        }
    }
    if(!flag) return 1;
	else return dp[ii][jj];
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d%d",&n,&m)!=EOF){
    	memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&ma[i][j]);
            }
        }
        sum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                sum = max(dfs(i,j),sum);
            }
        }
        printf("%d\n",sum);
    }
	return 0;
}

