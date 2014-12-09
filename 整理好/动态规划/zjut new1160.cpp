/*
Description
最近实验室新买了一个天平，为了能更好的测量还要采购一些砝码。但是为了能提高砝码的利用率，要求买n个砝码，它们的总重量为m，并且能根据所买的砝码组合出所有小于m的重量。现在请问有多少种采购方案。因为方案总数可能很大，请对4294967296取余。
Input
首先输入一个整数T（T<=30）表示有T组数据 接下来T行，每行两个整数N,M（N,M<=200）表示要买N个砝码，砝码总重量为m
Output
对于每组数据 输出有多少种方案。
Sample Input
3
3 5
2 4
4 7
Sample Output
2
0
3
HINT
样例3的三种方案分别为 ：
1 1 1 4
1 1 2 3
1 2 2 2
 * 
 *
 *
 *
 * */



/***********************************************\
 |Author: YMC
 |Created Time: 2014/8/18 20:54:13
 |File Name: A.cpp
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
ll n,m;
unsigned int dp[202][202][202];
void pre()
{
    memset(dp,0,sizeof(dp));
    dp[1][1][1] = 1;
    for(int i=1;i<200;++i) {
        for(int j=1;j<200;++j) {
            for(int k=1;k<200;++k) {
                if(!dp[i][j][k]) continue;
                for(int f=k;f + j<=200 && f <= j + 1;++f){
                    dp[i+1][j+f][f] += dp[i][j][k];
                }
            }
        }
    }
}
void solve(){
    unsigned int ans = 0;
    for(int i=1;i<=m;++i) ans += dp[n][m][i];
    cout<<ans<<endl;
}
int main() {
	//freopen("in.txt","r",stdin);
    pre(); 
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        solve();
    }
	return 0;
}

