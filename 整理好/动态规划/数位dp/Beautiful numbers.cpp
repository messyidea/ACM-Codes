/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/22 23:48:51
 |File Name: Beautiful numbers.cpp
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
#define MOD 2520
int num[20];
LL dp[20][50][MOD];
int index[MOD+1];
LL aa,bb;
int gcd(int a,int b){
	int r = a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
LL dfs(int cur,int lcm,int mod,bool limit){
    if(cur == -1) return mod%lcm == 0;
    if(!limit && dp[cur][index[lcm]][mod]!=-1) return dp[cur][index[lcm]][mod];
    int up = limit?num[cur]:9;
    LL ret = 0;
    ret += dfs(cur-1,lcm,mod*10%MOD,limit&&(0==up));
    for(int i=1;i<=up;++i){
        ret +=  dfs(cur-1,lcm*i/gcd(i,lcm),(mod*10+i)%MOD,limit&&(i==up));
    }
    if(!limit) dp[cur][index[lcm]][mod] = ret;
    return ret;
}
LL cal(LL x){
    //memset(dp,-1,sizeof(dp));
    int len = 0;
    while(x){
        num[len++] = x%10;
        x/=10;
    }
    return dfs(len-1,1,0,true);
}
int main() {
	//freopen("input.txt","r",stdin); 
	//memset(index,0,sizeof(index));
	memset(dp,-1,sizeof(dp));
	int cnt = 0;
	for(int i=1;i<=MOD;++i){
		if(MOD % i == 0) index[i] = cnt++;
	}
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&aa,&bb);
        printf("%lld\n",cal(bb)-cal(aa-1));
    }
	return 0;
}