#include <iostream>
#include <cstdio>
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
typedef long long ll;

using namespace std;
int mo = 1000000007;
int n, m;
int ans;
int dp[1005][1005];
int init() {
	for(int i = 1; i <= 1000; ++i) {
		for(int j = i; j <= 1000; ++j) {
			if(i == 1) {
				dp[i][j] = j;
				continue;
			}
			if(i == j) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
			dp[i][j] %= mo;
			/*for(int k = j-1; k >= i-1; --k) {
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mo;
			}*/
		}
	}
} 
int main() {
	//freopen("input.txt","r",stdin); 
	//puts("hello world");
	
	init();
	int T;
	while(scanf("%d", &T) != EOF) {
		while(T--) {
			scanf("%d %d", &n, &m);
			if(n <= 0 || m <= 0) {
				puts("0");
				continue;
			}
			if(m < n) swap(n,m);
			printf("%d\n", dp[n][m]);
		}
	}
	return 0;
}

