/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/22 9:44:03
 |File Name: K-th Nya Number.cpp
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
#define LL long long
int n,X,Y;
LL P,Q,K;
int num[100];
LL dp[30][30][30];
LL dfs(int cur,int x,int y,bool limit){
    if(cur<0) return (x==X && y==Y)?1:0;
    if(!limit && dp[cur][x][y]!=-1) return dp[cur][x][y];
    int up = limit?num[cur]:9;
    LL ret = 0;
    for(int i=0;i<=up;++i){
        ret+=dfs(cur-1,x+(i==4),y+(i==7),limit&&(i==up));
    }
    if(!limit) dp[cur][x][y] = ret;
    return ret;
}
LL cal(LL x){
    int len = 0;
    while(x){
        num[len++] = x%10;
        x/=10;
    }
    return dfs(len-1,0,0,true);
}
void makeans(int cur,int x,int y,bool limit,LL k,LL &ans){
    if(cur<0) return;
    int up = limit?num[cur]:9;
    LL ret = 0;
    int i;
    for(i=0;i<=up;++i){
        LL tp = dfs(cur-1,x+(i==4),y+(i==7),limit&&(i==up));
        if(ret+tp >= k) break;
        ret += tp;
    }
    ans = ans*10+i;
    makeans(cur-1,x+(i==4),y+(i==7),limit&&(i==up),k-ret,ans);
}
LL solve(LL x,LL k){
    k+=cal(P);
    int len = 0;
    while(x){
        num[len++] = x%10;
        x/=10;
    }
    LL ans = 0;
    makeans(len-1,0,0,true,k,ans);
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
    	printf("Case #%d:\n",cas++);
        scanf("%I64d%I64d%d%d",&P,&Q,&X,&Y);
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        while(n--){
            scanf("%I64d",&K);
            if(cal(Q) - cal(P) < K) printf("Nya!\n");
            else printf("%I64d\n",solve(Q,K));
        }
    }
	return 0;
}

