/***********************************************\
 |Author: YMC
 |Created Time: 2014/5/17 16:45:37
 |File Name: 百度之星2014Labyrinth.cpp
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
#define maxn 105
#define inf 1<<29
int ma[maxn][maxn];
int dp[maxn][maxn];
int n,m;
void scan(){
    dp[0][0] = ma[0][0];
    for(int i=1;i<n;++i){
        dp[i][0] = dp[i-1][0] + ma[i][0];
    }
}
void scan2(int x){
    for(int i=0;i<n;++i){
        int tp = dp[i][x-1] + ma[i][x];
        dp[i][x] = max(dp[i][x],tp);
        for(int j=i+1;j<n;++j){
            tp += ma[j][x];
            dp[j][x] = max(dp[j][x],tp);
        }
    }
    for(int i=n-1;i>=0;--i){
        int tp = dp[i][x-1] + ma[i][x];
        for(int j=i-1;j>=0;--j){
            tp += ma[j][x];
            dp[j][x] = max(dp[j][x],tp);
        }
    }
}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&ma[i][j]);
                dp[i][j] = -inf;
            }
        }
        scan();
        for(int i=1;i<m;++i){
            scan2(i);
        }
        printf("Case #%d:\n",cas++);
        printf("%d\n",dp[0][m-1]);
    }
	return 0;
}
/*
思路：这道题的思路是一列列的确定每一个格子的最大金币数。先确定第一列的最大金币数，因为只能向下走，所以很好求。之后每一列每格的最大金币数可以由前一列求得。
　　例如要求dp[i][j]（dp[][]的含义是走到这个位置的最大金币数），则从前一列有3种走法到这个格子：
　　1、它的左边一个格子，即a[i][j-1]，直接向右走一个格子；
　　2、a[i][j-1]上面的所有格子，可以先向右走一个格，然后向下一直走到a[i][j]的位置；
　　3、a[i][j-1]下面的所有格子，可以先向右走一个格，然后向上一直走到a[i][j]的位置。
　　遍历上述所有路径的过程中需要记录一个最大值，最后这个值就是dp[i][j]的值。
　　由此可知，确定该位置的每一种路径，需要遍历m次。而你需要确定每一列的每一个格子的dp[][]值，所以这个算法的时间复杂度为O(n*m*m)。

*/
