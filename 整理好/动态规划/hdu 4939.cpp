/***********************************************\
 |Author: YMC
 |Created Time: 2014/8/12 20:31:14
 |File Name: hdu 4939.cpp
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
ll n,x,y,z,t;
#define maxn 1505
ll dp[maxn][maxn];
ll ans;
int cas;
void solve(){
    memset(dp,0,sizeof(dp));
    dp[1][0] = 0;dp[1][1] = 0;
    for(int i=2;i<=n;++i){
        for(int j=0;j<=i;++j){
            if(i == j) {
                dp[i][j] = dp[i-1][j-1] + (i-j)*(t + (j-1)*z);
                continue;
            } else if(j == 0){
                dp[i][j] = dp[i-1][j] + (i-1-j)*y*(t+j*z);
                continue;
            }
            dp[i][j] = max(dp[i-1][j-1] + (i-j)*y*(t+(j-1)*z),dp[i-1][j] + (i-1-j)*y*(t + j*z));
        }
    }
    ans = x*n*t;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=i;++j){
            ans = max(ans,dp[i][j] + (n-i)*(t + j*z)*(x + y*(i-j)));
        }
    }
    cout<<"Case #"<<cas++<<": "<<ans<<endl;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    cas = 1;
    cin>>T;
    while(T--){
        cin>>n>>x>>y>>z>>t;
        solve();
    }

	return 0;
}


