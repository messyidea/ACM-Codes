/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/14 19:58:36
 |File Name: Dream_City.cpp
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
pair<int,int> pp[255];
int n,m;
int dp[255][255];
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.second < b.second;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        srep(i,n) {
            scanf("%d",&pp[i].first);
        }
        srep(i,n) scanf("%d",&pp[i].second);
        sort(pp+1,pp+1+n,cmp);
        memset(dp[0],0,sizeof(dp[0]));

        //memset(dp,0,sizeof(dp));
        srep(i,n) {
            srep(j,m) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + pp[i].first + pp[i].second * (j-1));
            }
        }
        printf("%d\n",dp[n][m]);
    }
	return 0;
}

