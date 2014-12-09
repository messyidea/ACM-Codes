/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/11 20:13:07
 |File Name: c.cpp
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
int n,m;
int da[4200005];
int db[4200000];
int dp[4200000];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        rep(i,n) scanf("%d",&da[i]);
        sort(da,da + n);
        for(int i=0;i < n-1;++i) {
            db[i] = da[i + 1] - da[i];
        }
        //memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;++i) dp[i] = 1;
        dp[0] = 1;
        for(int i=1;i<n-1;++i) {
            for(int j=i-1;j >= 0 ;-- j) {
                if(db[j] <= db[i]) dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        cout<<dp[n-2] + 1<<endl;
    }
	return 0;
}

