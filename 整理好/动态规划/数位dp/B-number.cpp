/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/22 22:41:44
 |File Name: B-number.cpp
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
LL n;
int num[50];
LL dp[30][15][3];//第三位为type,0末尾不是1,1末尾是1,2已经有13
LL dfs(int cur,int type,int mod,bool limit){
    if(cur < 0) return (type==2)&&(mod==0);
    if(!limit && dp[cur][mod][type]!=-1) return dp[cur][mod][type];
    int up = limit?num[cur]:9;
    LL ret = 0;
    for(int i=0;i<=up;++i){
        if(type == 2){
            ret += dfs(cur-1,2,(mod*10+i)%13,limit&&(i==up));
        }
        else if(type == 1){
            if(i==3){
                ret += dfs(cur-1,2,(mod*10+i)%13,limit&&(i==up));
            }
            else if(i==1){
                ret += dfs(cur-1,1,(mod*10+i)%13,limit&&(i==up));
            }
            else ret+=dfs(cur-1,0,(mod*10+i)%13,limit&&(i==up));
        }
        else{
            if(i==1){
                ret += dfs(cur-1,1,(mod*10+i)%13,limit&&(i==up));
            }
            else{
                ret+=dfs(cur-1,0,(mod*10+i)%13,limit&&(i==up));
            }
        }
    }
    //cout<<ret<<endl;
    if(!limit) dp[cur][mod][type] = ret;
    return ret;

}
LL cal(LL x){
    int len = 0;
    memset(dp,-1,sizeof(dp));
    while(x){
        num[len++] = x%10;
        x/=10;
    }
    return dfs(len-1,0,0,true);
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%I64d",&n)!=EOF){
        printf("%I64d\n",cal(n));
    }
	return 0;
}

