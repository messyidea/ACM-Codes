#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define inf 0x3f3f3f3f
int n, m;
int a[100005][2];
vector<pair<int, int> > b;
int dp[15][1005];
int tp1, tp2;
int maa, mab;
long long int ans;
int fang = 0;
bool cmp(pair<int, int>a, pair<int, int> b) {
	return a.second > b.second;
}
int main()
{
    //freopen("input.txt", "r", stdin);
	while(scanf("%d %d", &n, &m) != EOF) {
		maa = -1; mab = -1;
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i][0], &a[i][1]);
			if(a[i][1] > maa) {
				maa = a[i][1];
			}
		} 
		b.clear();
		for(int j = 0; j < m; ++j) {
			scanf("%d %d", &tp1, &tp2);
			b.push_back(make_pair(tp1, tp2));
			if(tp2 > mab) {
				mab = tp2;
			}
		}
		if(mab <= maa) {
			puts("-1");
			continue;
		}
		sort(b.begin(), b.end(), cmp);
		//printf("%d %d\n", b[0].first, b[0].second);
		for(int i = 0; i <= 10; ++i) {
			dp[i][0] = 0;
			for(int j = 1; j <= 1000; ++j) {
				dp[i][j] = inf;
			}
		}
		//printf("%d\n", dp[0][0]);
		ans = 0;
		for(int i = 0;i <= 10; ++i) {
			for(int j = 0; j < m; ++j) {
				for(int k = 1; k <= 1000; ++k) {
					if (i >= b[j].second) continue;
				 	if (b[j].second - i - k > 0) {
	 					dp[i][k] = min(dp[i][k], dp[i][0] + b[j].first);
	 				}
	 				if (b[j].second - i - k <= 0) {
				 		dp[i][k] = min(dp[i][k], dp[i][k - b[j].second + i] + b[j].first);
				 	}
				}
			}
		}
		/*
		printf("%d\n", b[0].second);
		for(int i = 0; i < 10; ++i) {
			printf("%d %d %d\n", 0, i, dp[0][i]);
		}*/
		for(int i = 0; i < n; ++i) {
			ans += (long long int)dp[a[i][1]][a[i][0]];
		}
		printf("%I64d\n", ans);
		
	}	    
    return 0;
}