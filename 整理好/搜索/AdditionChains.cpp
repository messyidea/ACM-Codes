/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/16 0:12:59
 |File Name: AdditionChains.cpp
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
int n;
#define maxn 1000000
#define inf 1<<29
int ans[maxn];
int ma[maxn];
int maxlen;
void dfs(int now,int depth){
    if(now > n) return ;
    if(depth > maxlen) return ;
    if(now == n){
        if(maxlen > depth){
            for(int i=0;i<depth;++i){
                ans[i] = ma[i];
            }
            maxlen = depth;
        }
        return ;
    }
    for(int i=depth-1;i>=0;--i){
        ma[depth] = now + ma[i];
        dfs(ma[depth],depth+1);
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) && n){
        maxlen = inf;
        ma[0] = 1;
        dfs(1,1);
        printf("%d",ans[0]);
        for(int i=1;i<maxlen;++i){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }   
	return 0;
}

